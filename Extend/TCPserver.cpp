// ServerTest.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//
 
#include <iostream>
#include<winsock.h>
#pragma comment(lib,"ws2_32.lib")
 
int main()
{
    std::cout << "Hello World!\n";
	WSADATA wsdata;
	std::cout << "start up now ...." << std::endl;
	if (WSAStartup(MAKEWORD(2, 2), &wsdata))
	{
		std::cout << "init socket failed!" << std::endl;
		WSACleanup();
		return FALSE;
	}
	std::cout << "before create socket ...." << std::endl;
	SOCKET s_server, s_accept;
	s_server = socket(PF_INET, SOCK_STREAM, 0);
	if (s_server == INVALID_SOCKET)
	{
		std::cout << "create socket fail" << std::endl;
		WSACleanup();
		return FALSE;
	}
	std::cout << "create socket success...." << std::endl;
	//���������Ϣ
	SOCKADDR_IN server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8226);
    //��Ȼ����Ҳ���Խ� 127.0.0.1�ĳ�����Ҫ��ip���� INADDR_ANY Ϊ������ip������Ϣ
	server_addr.sin_addr.S_un.S_addr = inet_addr("172.16.22.63");
 
	//���ݰ󶨷����� s_serverΪ������׽���
	std::cout << "before bind socket ...." << std::endl;
	if (bind(s_server, (SOCKADDR*)&server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		std::cout << "Binding Socket fail.......!" << std::endl;
		WSACleanup();
		return FALSE;
	}
	std::cout << "bind socket success...." << std::endl;
	std::cout << "before listen socket ...." << std::endl;
	if (listen(s_server, 1) == SOCKET_ERROR)
	{
		std::cout << "Listening Socket fail........!" << std::endl;
		WSACleanup();
		return FALSE;
	}
	std::cout << "listen socket success...." << std::endl;
	sockaddr_in accept_addr;         //������¼�������ӵ��׽�����Ϣ
	int len = sizeof(SOCKADDR);
	char recv_buf[8192] = { 0 };
	char send_buf[1024] = { 0 };
	while (true)
	{
		//������������
		std::cout << "wait accept...." << std::endl;
		s_accept = accept(s_server, (SOCKADDR*)&accept_addr, &len);
		if (s_accept == SOCKET_ERROR) {
			std::cout << "Error: accept failed !" << std::endl;
			WSACleanup();
			break;
		}
		std::cout << "�������ӳɹ�...." << std::endl;
		while (true)
		{
			std::cout << "�ȴ��ͻ���������...." << std::endl;
			int recv_len = recv(s_accept, recv_buf, sizeof(recv_buf), 0);
			if (recv_len < 0) {
				std::cout << "Error: receive info from server failed !" << std::endl;
				return -1;
			}
			std::cout << "���յ����ݣ��ͻ��˵������ǣ�" << recv_buf << std::endl;
			std::cout << "���ͻ��˷���������..."  << std::endl;
			//snprintf(send_buf, sizeof(send_buf), "%s", "�Ҹ��㷵����Ϣ��");
			int sendLen = send(s_accept, (char*)recv_buf, sizeof(recv_buf), 0);
			if (sendLen < 0) {
				std::cout << "Error: send info to server failed !" << std::endl;
				return -1;
			}
			std::cout << "���ͻ��˷����������" << std::endl;
		}
		
	}
}
 