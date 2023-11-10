#include <iostream>  
#include <cstring>  
#include <winsock2.h>  
  
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
    
    snprintf(temp, sizeof(temp), "%s", "shutdown\n");
	int sendLen = send(sock, (char*)temp, sizeof(temp), 0);
	if (sendLen < 0) {
		std::cout << "Error: send info to server failed !" << std::endl;
		return -1;
	}
	std::cout << "Send successfully, quiting....." << std::endl;
    closesocket(sock);  
    WSACleanup();  
    return 0;  
}