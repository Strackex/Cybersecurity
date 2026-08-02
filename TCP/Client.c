#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string.h>

void chatLoop(SOCKET serverFD);

int main(){
    SOCKET serverFD;
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup Failed\n");
        return 1;
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    serverFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(serverFD != INVALID_SOCKET){
        printf("Socket Created\n");

        if(connect(serverFD, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR ){
            printf("Connection Failed: %d\n", WSAGetLastError());
            closesocket(serverFD);
            WSACleanup();
            return 1;
        }
        
        printf("Connected to Server Successfully\n");
        chatLoop(serverFD);
        closesocket(serverFD);
    }

    WSACleanup();
    return 0;
}

void chatLoop(SOCKET serverFD){
    char inp[1024];
    char stored[1024];
    int bytes;
    
    while(1){
        memset(stored, 0, sizeof(stored));
        bytes = recv(serverFD, stored, sizeof(stored) - 1, 0);
        if (bytes > 0) {
            stored[bytes] = '\0'; 
            printf("Server: %s\n", stored);
            if (strcmp(stored, "exit") == 0) break;
        } else {
            printf("\nServer closed connection.\n");
            break;
        }
        
        // Client replies
        printf("Client: ");
        if (fgets(inp, sizeof(inp), stdin) == NULL) break;
        inp[strcspn(inp, "\n")] = '\0';

        send(serverFD, inp, (int)strlen(inp), 0);
        if (strcmp(inp, "exit") == 0) break;
    }
}
