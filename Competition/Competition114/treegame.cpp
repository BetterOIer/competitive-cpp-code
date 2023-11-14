#include<iostream>
#include<vector>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,k,winLis[1000005],winNum[1000005],tot;
vector<int>ro[1000005];
bool dfs(long long pos,long long fa,long long &winNum,long long chg){
    bool won=false;long long tmpNum1=0,tmpNum2=0;
    if(ro[pos].size()==1)tmpNum2=1;
    for(long long i:ro[pos]){
        if(i==fa)continue;
        bool opt = dfs(i,pos,winNum,chg^1);
        if(!opt) won=true,tmpNum1+=winNum;
        else if(opt) tmpNum2+=winNum;
    }
    if(won) winNum=tmpNum1;
    else winNum=tmpNum2;
    return won;
}
int main(){
    #ifndef LOCAL
    freopen("treegame.in","r",stdin);
    freopen("treegame.out","w",stdout);
    #else
    freopen("extreegame_6.in","r",stdin);
    freopen("extreegame_6.res","w",stdout);
    #endif
    n=read(),k=read();
    for(long long i = 1,u,v;i<n;i++){
        u=read(),v=read();
        ro[u].push_back(v);
        ro[v].push_back(u);
    }
    for(long long i = 1;i<=n;i++){
        if(dfs(i,0,winNum[i],1))winLis[++tot]=i;
    }
    if(k==1)for(long long i = 1;i<=tot;i++)printf("%lld ",winLis[i]);
    else for(long long i = 1;i<=tot;i++)printf("%lld ",winNum[winLis[i]]);
    return 0;
}