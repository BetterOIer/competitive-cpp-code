#include<iostream>
#include<cstring>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
int dp[10][520][520][2][2];
int a[15];
int dfs(int cho1,int cho2,int pos,int _a, int _b,bool lim,bool pre0){
    if(!pos) return 1;
    if(~dp[pos][_a][_b][lim][pre0]) return dp[pos][_a][_b][lim][pre0];
    int high = lim?a[pos]:9, ans=0;
    if(high>=7) ans+=dfs(cho1,cho2,pos-1,_a|(1<<pos),_b,lim&&7==high,false);
    if(high>=4) ans+=dfs(cho1,cho2,pos-1,_a,_b|(1<<pos),lim&&4==high,false);
    if(pre0) ans+=dfs(cho1,cho2,pos-1,_a,_b,false,true);
    return dp[pos][_a][_b][lim][pre0]=ans;
}
int get(int x){
    int idx=0;
    while(x){
        a[++idx]=x%10;
        x/=10;
    }
    return idx;
}
int main(){
    n=read();
    int len = get(n),ans=0;
    for(int i = 0;i<=9;i++){
        for(int j = i+1;j<=9;j++){
            memset(dp,-1,sizeof dp);
            ans+=dfs(i,j,len,0,0,1,1)-1;
        }
    }
    for(int i = 0;i<=9;i++){
        ans-=8*(dfs(i,i,len,0,0,1,1)-1);
    }
    cout<<ans;
    return 0;
}