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
const long long mod = 1'000'000'007;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n=100,k;
struct Matrix{
    long long a[105][105];
    Matrix(){for(long long i = 1;i<=n;i++)for(long long j = 1;j<=n;j++)a[i][j]=0;}
    Matrix operator * (const Matrix &b){
        Matrix c;
        for(long long i = 1;i<=n;i++){
            for(long long j = 1;j<=n;j++){
                for(long long k =1;k<=n;k++){
                    (c.a[i][j]+=b.a[i][k]*a[k][j]%mod)%=mod;
                }
            }
        }
        return c;
    }
};
Matrix base;
Matrix qpow(long long p){
    Matrix res=base;p--;
    while(p){
        if(p&1)res=res*base;
        base=base*base;
        p>>=1;
    }
    return res;
}
int main(){
    n=read(),k=read();
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            base.a[i][j]=read();
        }
    }
    if(!k){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                printf("%lld ",i==j);
            }puts("");
        }return 0;
    }
    base=qpow(k);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            printf("%lld ",base.a[i][j]);
        }puts("");
    }
    return 0;
}