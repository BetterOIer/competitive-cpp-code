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
int n,m,k;
char s[105];
int a[105][105];
int dp[105][105];
int pre[105][105];
void out(int x,int y){
    if(x==1){
        cout<<y<<endl;
        return;
    }
    if(pre[x][y]){
        out(x-1,y+1);
        cout<<"L";
    }else{
        out(x-1,y-1);
        cout<<"R";
    }
}
int main(){
    n=read(),m=read(),k=read();
    for(int i = 1;i<=n;i++){
        scanf("%s",s+1);
        for(int j = 1;j<=m;j++){
            a[i][j]=s[j]-'0';
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(dp[i-1][j-1]>dp[i-1][j+1]){
                dp[i][j] = dp[i-1][j-1]+a[i][j];
                pre[i][j] = 0;
            }else{
                dp[i][j] = dp[i-1][j+1]+a[i][j];
                pre[i][j] = 1;
            }
        }
    }
    int ans = -1,pos;
    for(int i = 1;i<=m;i++){
        if(dp[n][i]%(k+1)==0){if(ans<dp[n][i])ans=dp[n][i],pos=i;}
    }
    cout<<ans<<endl;
    if(ans!=-1)out(n,pos);
    return 0;
}