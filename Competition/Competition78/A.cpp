/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cmath>
using namespace std;
const long long mod = 998244353;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long a,b,k;
long long num=1;
int main(){
    a=read(),b=read(),k=read();
    for(long long i = 1;i<=k;i++){
        if(i%a==0)num=(num*2)%mod;
        if(i%b==0){
            if(num>1)num=(num*499122177)%mod;
        }
    }
    cout<<(num+mod)%mod;
    return 0;
}