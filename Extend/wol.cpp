#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<easyx.h>
using namespace std;

struct node{
    int id;
    string name;
    unsigned char mac[6];
    int port;
}mach[1];
hostent *host;
string s;

bool wol(int which){
    unsigned char packet[102];
    struct sockaddr_in addr;
    int sockfd, i,j, on = 1; 

    for(i=0;i<6;i++){
        packet[i] = 0xFF;    
    }
    for(i=1;i<17;i++){
        for(j=0;j<6;j++){
            packet[i*6+j] = mach[which].mac[j];
        }
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST,(char*)&on, sizeof(on));
    if(sockfd < 0){
        return false;
    }
    memset((void*)&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(mach[which].port);
    addr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr *)host->h_addr_list[0]));
    sendto(sockfd,(char*)&packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr));
    return true;
}

int main(){
    mach[0].name="Server";
    mach[0].mac[0]=80;
    mach[0].mac[1]=229;
    mach[0].mac[2]=73;
    mach[0].mac[3]=23;
    mach[0].mac[4]=24;
    mach[0].mac[5]=68;
    mach[0].port=10;
    s="BetterOIer.tpddns.cn";
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    host = gethostbyname(s.c_str());
    
    initgraph(400,100);

    setfillcolor(RGB(0, 120, 215));
    setlinecolor(RGB(0, 120, 215));
    setbkcolor(RGB(0, 120, 215));

    fillrectangle(0,0,400,100);

    LOGFONT now;

    gettextstyle(&now);

    now.lfQuality=PROOF_QUALITY;
    now.lfHeight = 36;	
    RECT r1 = {0, 0, 195, 100}, r2={200,0,380,100};
    _tcscpy(now.lfFaceName, _T("¿¬Ìå"));
    
    settextstyle(&now);
    settextcolor(WHITE);
    drawtext(_T("»½ÐÑ£¡"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    drawtext(_T("ÍË³ö"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    setlinecolor(WHITE);
    rectangle(30,30,150,70);
    rectangle(230,30,350,70);
    ExMessage m;
    while(true)
	{
		// »ñÈ¡Ò»ÌõÊó±ê»ò°´¼üÏûÏ¢
		m = getmessage(EX_MOUSE | EX_KEY);

		switch(m.message)
		{
			case WM_MOUSEMOVE:
				break;
			case WM_LBUTTONDOWN:
				// Èç¹ûµã×ó¼üµÄÍ¬Ê±°´ÏÂÁË Ctrl ¼ü
				if (m.x>=30&&m.x<=150&&m.y>=30&&m.y<=70){
					wol(0);wol(0);wol(0);
                    fillrectangle(30,30,150,70);
                    now.lfHeight = 30;
                    settextstyle(&now);
                    settextcolor(WHITE);
                    drawtext(_T("ÒÑ»½ÐÑ£¡"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                }else if(m.x>=230&&m.x<=350&&m.y>=30&&m.y<=70){
                    return 0;
                }
				break;

			case WM_KEYDOWN:
				if (m.vkcode == VK_ESCAPE)
					return 0;
		}
	}
    return 0;
}