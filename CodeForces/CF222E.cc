/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cstring>
const long long mod = 1e9+7;
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,m,k;
long long getPos(char x){return (x>='a'? x-'a'+1:x-'A'+27);}
struct Matrix{
    long long a[53][53];
    Matrix () {memset(a,0,sizeof a);}
    void build(){
        for(long long i = 1;i<=k;i++){
            char a1,a2;
            cin>>a1>>a2;
            a[getPos(a2)][getPos(a1)]=1;
        }
        for(long long i=1;i<=m;i++)for(long long j=1;j<=m;j++)a[i][j]^=1;
        return;
    }
    Matrix operator * (const Matrix &w)const{
        Matrix ans;
        for(long long i = 1;i<=m;i++)for(long long j = 1;j<=m;j++)for(long long k = 1;k<=m;k++)ans.a[i][j]=(ans.a[i][j]+1LL*a[i][k]*w.a[k][j]%mod)%mod;
        return ans;
    }
}a,ans;
int main(){
    n=read()-1,m=read(),k=read();
    a.build();for(long long i = 1;i<=m;i++)ans.a[i][1]=1;
    while(n){
        if(n&1)ans=a*ans;
        a=a*a;
        n>>=1;
    }
    long long res=0;
    for(long long i =1;i<=m;i++)res=(res+ans.a[i][1])%mod;
    cout<<res;
    return 0;
}