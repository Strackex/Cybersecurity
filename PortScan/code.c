#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string.h>
#include <windows.h>

DWORD WINAPI socketScan(LPVOID lpParam);
char ip[16];
typedef struct{int startPort; int endPort;}portRange;

int main(){
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup Failed. Error: %d\n", WSAGetLastError());
        return 1;
    }

    int port1;
    int port2;
    int threadNO;

    portRange *chunk = NULL;
    HANDLE *thread = NULL;

    printf("Enter Number of threads\n");
    scanf("%d",&threadNO);

    printf("Port 1\n");
    scanf("%d",&port1);

    printf("Port 2\n");
    scanf("%d",&port2);

    printf("Enter IP: ");
    scanf("%15s", ip);

    printf("Scanning Adress %s\n",ip);

    int portsPerThread1 = (port2 - port1) + 1; //10
    int portsPerThread = portsPerThread1 / threadNO; //3
    int remainder = portsPerThread1 % threadNO; // 1

    chunk = malloc(threadNO * sizeof(portRange));
    thread = malloc(threadNO * sizeof(HANDLE));

    int currentStart = port1; // 1) 1 - 2) 4 - 3) 7

    for(int i=0;i<threadNO;i++)
    {
        int extra;
        if(i < remainder)
        {extra = 1; }
        else{extra = 0;}

        chunk[i].startPort = currentStart;
        chunk[i].endPort = currentStart + portsPerThread + extra -1;

        currentStart = chunk[i].endPort + 1;

        thread[i] = CreateThread(NULL,0,socketScan,&chunk[i],0,NULL);
    }

    WaitForMultipleObjects(threadNO,thread,TRUE,INFINITE);

    for(int j=0;j<threadNO;j++){
        CloseHandle(thread[j]);
    }

    free(chunk);
    free(thread);

    WSACleanup();
    return 0;
}

DWORD WINAPI socketScan(LPVOID lpParam){

    struct sockaddr_in serverAddr;

    portRange* range = (portRange*)lpParam;

    int start = range -> startPort;
    int end = range -> endPort;
    DWORD timeout = 100;

    SOCKET ServerFD;
    
    serverAddr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &serverAddr.sin_addr);


    for(int i = start; i <= end; i++){
        serverAddr.sin_port = htons(i);

        if ((ServerFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) != INVALID_SOCKET)
        {
            u_long mode = 1;
            ioctlsocket(ServerFD, FIONBIO, &mode);
            
            connect(ServerFD, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

            fd_set WriteSet;
            FD_ZERO(&WriteSet);
            FD_SET(ServerFD, &WriteSet);

            struct timeval tv;

            tv.tv_sec = 0;
            tv.tv_usec = 200000;

            if(select(0,NULL, &WriteSet,NULL,&tv)>0){
                int error = 0;
                int len = sizeof(error);

                getsockopt(ServerFD,SOL_SOCKET,SO_ERROR, (char*)&error,&len);

                if(error == 0)
                {
                    printf("Port %d is open\n", i);
                }
                //else{printf("Port %d is closed (refused) \n", i);}
            }

            //else{printf("Port %d is closed (timeout) \n",i);}

            closesocket(ServerFD);
        }   
        else{
            printf("Error creating socket %d\n",WSAGetLastError());
            return 1;
        }        
    }
    return 0;
}
