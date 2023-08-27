#include<iostream>
#include<cstring>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
int dp[10][520][520][2][2];
int a[15];
int dfs(int pos,int _7, int _4,bool lim,bool pre0){
    if(!pos) return 1;
    if(~dp[pos][_7][_4][lim][pre0]) return dp[pos][_7][_4][lim][pre0];
    int high = lim?a[pos]:9, ans=0;
    if(high>=7) ans+=dfs(pos-1,_7|(1<<pos),_4,lim&&7==high,false);
    if(high>=4) ans+=dfs(pos-1,_7,_4|(1<<pos),lim&&4==high,false);
    if(pre0) ans+=dfs(pos-1,_7,_4,false,true);
    return dp[pos][_7][_4][lim][pre0]=ans;
}
int dfs(int pos,int cho1,int _7,int cho2,int _4,bool lim,bool pre0){
    if(!pos) return 1;
    if(~dp[pos][_7][_4][lim][pre0]) return dp[pos][_7][_4][lim][pre0];
    int high = lim?a[pos]:9, ans=0;
    for(int i = 0;i<=high;i++){
        if(c1&&cho1==i) ans+=dfs(pos-1,cho1,_7|(1<<pos),cho2,_4,lim&&i==high,pre0&&i==0);
        if(c2&&cho2==i) ans+=dfs(pos-1,cho1,_7,cho2,_4|(1<<pos),lim&&i==high,pre0&&i==0);
        if(!c1) {
            c1=true;
            ans+=dfs(pos-1,i,_7|(1<<pos),cho2,_4,lim&&i==high,pre0&&i==0);
            c1=false;
        }
        else if(!c2){
            c2=true;
            ans+=dfs(pos-1,cho1,_7,cho2,_4|(1<<pos),lim&&i==high,pre0&&i==0);
            c2=false;
        }
        if(pre0&&i==0) ans+=dfs(pos-1,cho1,_7,cho2,_4,false,true);
    }
    return dp[pos][_7][_4][lim][pre0]=ans;
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
    memset(dp,-1,sizeof dp);
    int len = get(n);
    cout<<dfs(len,0,0,1,1)-1;
    return 0;
}