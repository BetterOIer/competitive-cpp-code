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
int a,b,c,d,M,ans=0;
int main(){
    a=read(),b=read(),c=read(),d=read(),M=read();
    int simAns=c*5,waDiff=b-d;
    if(simAns<=M){
        ans=simAns-waDiff*20;
    }else{
        ans=simAns+d*20-waDiff*20;
    }
    if(ans<0)ans=0;
    cout<<ans;
    return 0;
}