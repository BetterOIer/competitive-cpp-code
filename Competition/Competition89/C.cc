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
int a[101],b[101];
int dp[101][101];
int pre[101][101];
int n,c;
void out(int x,int y){
    if(x==y&&x==1){
        return;
    }
    if(pre[x][y]==1){
        out(x,y-1);
        cout<<"R";
    }else{
        out(x-1,y);
        cout<<"D";
    }
}
int main(){
    n=read(),c=read();
    for(int i = 1;i<=n;i++) a[i]=read();
    for(int i = 1;i<=n;i++) b[i]=read();
    for(int i =  1;i<=n;i++){
        for(int j =  1;j<=n;j++){
            if(dp[i][j-1]>dp[i-1][j]){
                dp[i][j]=dp[i][j-1]+a[i]*b[j]%c;
                pre[i][j]=1;
            }else{
                dp[i][j]=dp[i-1][j]+a[i]*b[j]%c;
                pre[i][j]=-1;
            }
        }
    }
    out(n,n);
    return 0;
}