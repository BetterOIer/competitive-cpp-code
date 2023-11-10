#include <iostream>
#include <string>
#include <cstring>
#include <winsock2.h> 
using namespace std;

hostent *host;
int main() {
    cout << "测试开始了!" << endl;
    SOCKET clientsocket;
    SOCKADDR_IN serveraddr;
    SOCKADDR_IN clientaddr;
    char buf[1024];
 
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,0),&wsa);    //初始化WS2_32.DLL
 
    //创建套接字
    if((clientsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) <= 0)
    {
        printf("套接字socket创建失败!\n");
        return -1;
    }
 
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(2000); //
    host = gethostbyname("betteroier.site");
    serveraddr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr *)host->h_addr_list[0]));
 
    //请求连接
    printf("尝试连接中...\n");
    if(connect(clientsocket, (SOCKADDR *)&serveraddr, sizeof(serveraddr)) != 0)
    {
        printf("连接失败!\n");
        return -1;
    }
    printf("连接成功!\n");
 
    //发送数据
    while(1){printf("请输入发送给服务器的字符:\n");
    scanf("%s", buf);
    snprintf(buf, sizeof(buf), "%s\n", buf);
    printf("%s\n",buf);
    if(send(clientsocket, buf, sizeof(buf), 0)<=0)
//        if(send(clientsocket, buf, strlen(buf)+1, 0)<=0)
    {
        printf("发送错误!\n");
    }
    }
 
    //接收数据  这里是同步处理发送后的接收，如果需要大数据量，可以接收改成异步
    /* while(1){
        if(recv(clientsocket, buf, 1024, 0) <= 0)
        {
            printf("关闭连接!\n");
            //closesocket(clientsocket);
            break;
        }
        printf("接收来自服务器的信息: %s\n",buf);
        //break;
    } */
    //关闭套接字
    closesocket(clientsocket);
    WSACleanup();    //释放WS2_32.DLL
    return 0;
}