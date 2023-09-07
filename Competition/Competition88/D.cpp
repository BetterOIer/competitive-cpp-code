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
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long LCM(long long a,long long b){
    long long aa=1LL*a*b;
    while(b^=a^=b^=a%=b);
    return aa/a;
}
int main(){
    long long t=read();
    while(t--){
        long long n=read(),x=read(),y=read();
        long long lcm = n/LCM(x,y);
        long long bsX = n/x-lcm,bsY = n/y-lcm;
        printf("%lld\n",(n+1-bsX+n)*bsX/2-(1+bsY)*bsY/2);
    }
    return 0;
}