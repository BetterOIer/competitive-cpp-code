#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m;
int tillNow[1000005];
int digPre[1000005][51];
int main(){
    freopen("pair.in","r",stdin);
    freopen("pair.out","w",stdout);
    n=read(),m=read();
    for(int i = 1,num;i<=n;i++){
        num=read();
        tillNow[i]=tillNow[i-1];
        for(int j = 1;j<=50;j++){
            digPre[i][j]=digPre[i-1][j];
            if(j>num)tillNow[i]+=digPre[i-1][j];
        }
        digPre[i][num]++;
    }
    for(int i  =1,l,r,ans=0,preDigNum=0;i<=m;i++){
        l=read(),r=read();
        ans = tillNow[r]-tillNow[l-1];
        preDigNum = 0;
        for(int j = 1;j<=50;j++){
            ans-=preDigNum*digPre[l-1][j];
            preDigNum+=digPre[r][j]-digPre[l-1][j];
        }
        printf("%d\n",ans);
    }
    return 0;
}