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
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
int a[1005],dp[1005][1005],pre[1005][1005][3];
void getPre(int i,int j,int x,int y,int z){
    pre[i][j][0]=x,pre[i][j][1]=y,pre[i][j][2]=z;
}
void getAns(int x,int y){
    if(y==0)return;
    getAns(x-1,pre[x][y][2]);
    if(pre[x][y][0]<=n)cout<<pre[x][y][0]<<" ";
    if(pre[x][y][1]<=n)cout<<pre[x][y][1]<<" ";
    cout<<endl;
}
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
    }
    memset(dp,63,sizeof dp);
    dp[1][1]=max(a[2],a[3]),dp[1][2]=max(a[1],a[3]),dp[1][3]=max(a[2],a[1]);
    getPre(1,1,2,3,0),getPre(1,2,1,3,0),getPre(1,3,1,2,0);
    int m = (n&1)? n/2+1:n/2;
    for(int i = 2;i<=m;i++){
        int x = i<<1,y = i<<1|1;
        for(int j  =1;j<x;j++){
            if(dp[i][x]>dp[i-1][j]+max(a[j],a[y]))dp[i][x]=dp[i-1][j]+max(a[j],a[y]),getPre(i,x,j,y,j);
            if(dp[i][y]>dp[i-1][j]+max(a[j],a[x]))dp[i][y]=dp[i-1][j]+max(a[j],a[x]),getPre(i,y,j,x,j);
            if(dp[i][j]>dp[i-1][j]+max(a[y],a[x]))dp[i][j]=dp[i-1][j]+max(a[y],a[x]),getPre(i,j,x,y,j);
        }
    }
    cout<<dp[m][n+1]<<endl;
    getAns(m,n+1);
    return 0;
}