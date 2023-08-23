/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int x1,y1,x2,y2,a1,a2;
int main(){
    freopen("pubg.in","r",stdin);
    freopen("pubg.out","w",stdout);
    while(cin>>x1>>y1>>x2>>y2){
        if(abs(x2-x1)<=1&&abs(y2-y1)<=1){
            cout<<"YE5\n";
            a1++;
        }else{
            cout<<"NO\n";
            a2++;
        }
    }
    if(a1>a2) cout<<"Poor xshen!";
    else if(a1==a2) cout<<"Friend Ship.";
    else cout<<"Yahoo!";
    fclose(stdin);
    fclose(stdout);
    return 0;
}