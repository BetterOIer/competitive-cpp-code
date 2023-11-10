// ClientTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include<winsock.h>
int main()
{
    std::cout << "Hello World!\n";
	WSADATA wsdata;
	if (WSAStartup(MAKEWORD(2, 2), &wsdata))
	{
		std::cout << "init socket failed!" << std::endl;
		WSACleanup();
		return FALSE;
	}
	//检测版本号
	if (LOBYTE(wsdata.wVersion) != 2 || HIBYTE(wsdata.wHighVersion) != 2) {
		std::cout << "Error: wsadata.wVersion != 2 ." << std::endl;
		WSACleanup();
		return -1;
	}
	SOCKET client;
	client = socket(PF_INET, SOCK_STREAM, 0);
	if (client == INVALID_SOCKET)
	{
		std::cout << "create socket fail" << std::endl;
		WSACleanup();
		return FALSE;
	}
	//填充服务端信息
	SOCKADDR_IN server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.S_un.S_addr = inet_addr("172.16.22.63");
	server_addr.sin_port = htons(8226);
	//发送连接请求 请求连接服务器
	if (connect(client, (SOCKADDR*)&server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR) {
		std::cout << "Error: connect server failed !" << std::endl;
		WSACleanup();
		return -1;
	}
	std::cout << "成功连接到服务器" << std::endl;
	//发送数据
	while(true){
		char temp[1024] = { 0 };
		std::cout << "开始发送数据....." << std::endl;
		scanf("%s",temp);
		int sendLen = send(client, (char*)temp, sizeof(temp), 0);
		if (sendLen < 0) {
			std::cout << "Error: send info to server failed !" << std::endl;
			return -1;
		}
		std::cout << "发送数据成功、等待服务器响应....." << std::endl;
		char recv_buf[8192] = { 0 };
		int recv_len = recv(client, recv_buf, sizeof(recv_buf), 0);
		if (recv_len < 0) {
			std::cout << "Error: receive info from server failed !" << std::endl;
			return -1;
		}
		std::cout << "收到了服务器返回的信息 内容是：" << recv_buf << std::endl;
	}
}
 
 