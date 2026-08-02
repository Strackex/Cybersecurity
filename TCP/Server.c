#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string.h>

void sendMsg(int newSocket);

int main(){
    int serverFD;
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup Failed\n");
        return 1;
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if((serverFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) != -1 ){
        printf("Socket Passed\n");
        int result = bind(serverFD, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

        if(result == -1){
            perror("Error");
        }
        
        if(result != -1){
            printf("Binding Passed\n");

            listen(serverFD, 5);
            printf("Listening in progress\n");

            int addrLen = sizeof(serverAddr);
            int newSocket = accept(serverFD, (struct sockaddr*)&serverAddr, &addrLen);

            if(newSocket != INVALID_SOCKET){
 
                sendMsg(newSocket); 

                closesocket(newSocket);
                closesocket(serverFD);
            }
            else{
                printf("Failed Connection\n");
                WSACleanup();
                return 1;
            }
        }
    }
    else{
        perror("Connection Failed");
    }
    WSACleanup();
    return 0;
}

void sendMsg(int newSocket){

    char inp[1024];
    char stored[1024] = {0};
    int bytes;

    do{

        // Send

        printf("Server: ");
        fgets(inp,sizeof(inp),stdin);
        inp[strcspn(inp, "\n")] = '\0';

        send(newSocket,inp,strlen(inp),0);
        if (strcmp(inp, "exit") == 0) {break;}
        if (strcmp(inp, "payload") == 0){printf("Sucesfully Hacked \n User = admin \n Password = 1456");}

        // Recv

        if((bytes = recv(newSocket, stored, sizeof(stored) - 1, 0)) > 0){
        stored[bytes] = '\0';

        printf("%s\n", stored);

        if (strcmp(inp, "exit") == 0) {break;}
        }

        else{printf("CLient Disconnected");
        break;}
    }while(1);

}
