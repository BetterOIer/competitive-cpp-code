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
long long pos,neg,zero,one;
int main(){
    long long t=read();
    while(t--){
        long long n=read(),ans=0;pos=neg=zero=one=0;
        for(long long i = 1,cur;i<=n;i++){
            cur=read();
            if(cur<=0)ans+=(pos);
            else if(cur==1)ans+=(pos+neg+zero);
            else ans+=(zero+neg+one);

            if(cur<0)neg++;
            else if(cur==0)zero++;
            else if(cur==1)pos++,one++;
            else pos++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}