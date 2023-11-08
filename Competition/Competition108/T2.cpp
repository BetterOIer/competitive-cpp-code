#include<iostream>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,k,id;
int idx[2000005],val[2000005];
bool isBig[2000005];
struct node{int to;int val;};
vector<node>ro[2000005];
vector<node>nRo[2000005];
int dfs(int pos,int fa,int roval){
    if(fa==0)idx[pos]=++id;
    if(ro[pos].size()<=k)idx[pos]=id;
    else return nRo[id].push_back((node){idx[pos],roval}),nRo[idx[pos]].push_back((node){id,roval}),0;
    int res = 0;
    for(auto i:ro[pos]){
        if(i.to==fa)continue;
        res+=dfs(i.to,pos,i.val);
    }
    return res+roval;
}
int main(){
    #ifndef LOCAL
    freopen("warm.in","r",stdin);
    freopen("warm.out","w",stdout);
    #else
    freopen("ex_contest3.in","r",stdin);
    freopen("ex_contest3.out","w",stdout);
    #endif
    n=read(),k=read();
    for(int i = 1,u,v,w;i<n;i++){
        u=read(),v=read(),w=read();
        ro[u].push_back((node){v,w});
        ro[v].push_back((node){u,w});
    }
    for(int i = 1;i<=n;i++){
        if(ro[i].size()>k)idx[i]=++id,isBig[id]=true;
    }
    for(int i = 1;i<=n;i++){
        if(!idx[i]){int va = dfs(i,0,0);val[id]=va;}
    }
    int ans=0;
    for(int i = 1;i<=id;i++){
        if(isBig[i]){
            for(node j:nRo[i]){
                if(!isBig[j.to])val[i]+=val[j.to]+j.val;
            }
            ans=max(ans,val[i]);
        }
    }
    cout<<ans;
    return 0;
}