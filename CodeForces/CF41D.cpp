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
int n,m,k;
char s[105];
int a[105][105];
int dp[105][105][15];
int pre[105][105][15];
void out(int x,int y,int o){
    if(x==1){
        cout<<y<<endl;
        return;
    }
    if(pre[x][y][o]){
        out(x-1,y+1,((o-a[x][y])%(k+1)+k+1)%(k+1));
        cout<<"L";
    }else{
        out(x-1,y-1,((o-a[x][y])%(k+1)+k+1)%(k+1));
        cout<<"R";
    }
}
int main(){
    memset(dp,-1,sizeof dp);
    memset(pre,-1,sizeof pre);
    n=read(),m=read(),k=read();
    for(int i = 1;i<=n;i++){
        scanf("%s",s+1);
        for(int j = 1;j<=m;j++){
            a[n-i+1][j]=s[j]-'0';
        }
    }
    for(int i = 1;i<=m;i++)dp[0][i][0]=0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            for(int o = 0;o<=k;o++){
                int preFix = ((o-a[i][j])%(k+1)+k+1)%(k+1);
                if((dp[i-1][j-1][preFix]!=-1&&(dp[i-1][j+1][preFix]==-1))||(dp[i-1][j-1][preFix]!=-1&&dp[i-1][j+1][preFix]!=-1&&dp[i-1][j-1][preFix]>dp[i-1][j+1][preFix])){
                    dp[i][j][o] = dp[i-1][j-1][preFix]+a[i][j];
                    pre[i][j][o] = 0;
                }else if((dp[i-1][j+1][preFix]!=-1&&(dp[i-1][j-1][preFix]==-1))||(dp[i-1][j-1][preFix]!=-1&&dp[i-1][j+1][preFix]!=-1&&dp[i-1][j-1][preFix]<=dp[i-1][j+1][preFix])){
                    dp[i][j][o] = dp[i-1][j+1][preFix]+a[i][j];
                    pre[i][j][o] = 1;
                }
            }
        }
    }
    int ans = -1,pos;
    for(int i = 1;i<=m;i++){
        if(dp[n][i][0]!=-1){if(ans<dp[n][i][0])ans=dp[n][i][0],pos=i;}
    }
    cout<<ans<<endl;
    if(ans!=-1)out(n,pos,0);
    return 0;
}