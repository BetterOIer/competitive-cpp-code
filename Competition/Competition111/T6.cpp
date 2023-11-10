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
int n,m;
int ori[2002][2002],a[1005][1005];
int main(){
    n=read(),m=read();
    for(int i = 1;i<=2*n;i++){
        for(int j= 1;j<=2*m;j++){
            ori[i][j]=read();
        }
    }
    for(int i = 1,ii=1;i<=2*n;i+=2,ii++){
        for(int j= 1,jj=1;j<=2*m;j+=2,jj++){
            a[ii][jj]=ori[i][j]+ori[i][j+1]+ori[i+1][j]+ori[i+1][j+1];
        }
    }
    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            cout<<a[j][i]<<" \n"[j==n];
        }
    }
    return 0;
}