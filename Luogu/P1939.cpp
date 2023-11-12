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
long long n;
struct Matrix{
    long long a[4][4];
    Matrix(){for(long long i = 1;i<=3;i++)for(long long j = 1;j<=3;j++)a[i][j]=0;}
    Matrix operator * (const Matrix &b){
        Matrix c;
        for(long long i = 1;i<=3;i++){
            for(long long j = 1;j<=3;j++){
                for(long long k =1;k<=3;k++){
                    (c.a[i][j]+=b.a[i][k]*a[k][j]%mod)%=mod;
                }
            }
        }
        return c;
    }
};
Matrix base,x;
Matrix qpow(Matrix res,long long p){
    Matrix base1=base;
    while(p){
        if(p%2)res=res*base1;
        base1=base1*base1;
        p>>=1;
    }
    return res;
}
int main(){
    base.a[1][2]=1;base.a[2][3]=1;base.a[3][1]=1;base.a[3][3]=1;
    x.a[1][1]=x.a[2][1]=x.a[3][1]=1;
    long long t=read();
    while(t--){
        n=read();
        Matrix res=qpow(x,n-1);
        cout<<res.a[1][1]<<endl;
    }
    return 0;
}