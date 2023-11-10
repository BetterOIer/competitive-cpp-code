#include <iostream>  
#include <cstring>  
#include <winsock2.h>  
#include<windows.h>
  
char temp[1024] = { 0 }; 
hostent *host;

int main() {  
    WSADATA wsaData;  
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);  
    if (result != 0) {  
        std::cerr << "WSAStartup failed: " << result << std::endl;  
        return 1;  
    }  
  
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  
    if (sock == INVALID_SOCKET) {  
        std::cerr << "Socket creation failed: " << WSAGetLastError() << std::endl;  
        return 1;  
    }  
  
    sockaddr_in serverAddr;  
    serverAddr.sin_family = AF_INET;  
    serverAddr.sin_port = htons(2000);  
    host = gethostbyname("betteroier.site");
    serverAddr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr *)host->h_addr_list[0]));
    /* if (inet_pton(AF_INET, "betteroier.site", &serverAddr.sin_addr) <= 0) {  
        std::cerr << "inet_pton failed: " << WSAGetLastError() << std::endl;  
        closesocket(sock);  
        return 1;  
    }   */
  
    result = connect(sock, (SOCKADDR*)&serverAddr, sizeof(serverAddr));  
    if (result == SOCKET_ERROR) {  
        std::cerr << "Connection failed: " << WSAGetLastError() << std::endl;  
        closesocket(sock);  
        return 1;  
    }  
    std::cout << "Success: Connect to the server!" << std::endl;

    std::cout << "Closing Request sending countdown: " ;

    std::cout << "3 ";
    Sleep(1000);
    std::cout << "2 ";
    Sleep(1000);
    std::cout << "1 ";
    Sleep(1000);
    std::cout << "0\n";
    snprintf(temp, sizeof(temp), "%s", "shutdown\n");
	int sendLen = send(sock, (char*)temp, sizeof(temp), 0);
	if (sendLen < 0) {
		std::cout << "Error: send info to server failed !" << std::endl;
		return -1;
	}
	std::cout << "Success: Request sent to the server!" << std::endl;

    char recv_buf[8192] = { 0 };
    const char* message = "Received";  
	int recv_len = recv(sock, recv_buf, sizeof(recv_buf), 0);
	if (recv_len < 0) {
		std::cout << "Error: receive info from server failed!" << std::endl;
		return -1;
	}
    if(memcmp(recv_buf,message,strlen(message))==0){
        return std::cout << "Success: Closing info confirmed!" << std::endl,closesocket(sock),WSACleanup(),0;
    }else std::cout << "Error: failed to close the server!" << std::endl;
    closesocket(sock);  
    WSACleanup();  
    return 0;  
}