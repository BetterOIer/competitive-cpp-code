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
int f[1000005][20];
int main(){
    int n=read(),m=read();
    for(int i = 1;i<=n;i++)f[i][0]=read();
    for(int i = 1;i<=20;i++){
        for(int j = 1;j+(1<<i)-1<=n;j++){
            f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
        }
    }
    for(int i = 1,x,y,k;i<=m;i++){
        x=read(),y=read();
        k=__builtin_log2(y-x+1);
        printf("%d\n",max(f[x][k],f[y-(1<<k)+1][k]));
    }
    return 0;
}