#include<iostream>
#include<cstdlib>
#include<random>
#include<chrono>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
mt19937  engi(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,root,ans=0;
struct EDGE{
    int u,v;
    int used;
    int val;
};
vector<int>ro[3003];
vector<EDGE>edge;
map<pair<int, int>, int >M;
/* int idx[3003]; */
int dfs1(int pos,int fa){
    int res=(pos>root);
    for(int i:ro[pos]){
        if(i==fa)continue;
        res+=dfs1(i,pos);
    }
    if(!fa)return 0;
    if(pos>fa)swap(pos,fa);
    edge[M[make_pair(pos,fa)]].used+=res;
    return res;
}
bool hav[3005];
void dfs2(int pos,int fa,int mex){
    if(pos>root)ans+=mex;
    for(int i:ro[pos]){
        if(i==fa)continue;
        int cnt=pos,cnts=i;if(cnt>cnts)swap(cnt,cnts);
        int va=edge[M[make_pair(cnt,cnts)]].val,nowmex=mex;
        hav[va]=true;if(nowmex==va){
            for(int j= nowmex;j<=n;j++){
                if(!hav[j]){nowmex=j;break;}
            }
        }
        dfs2(i,pos,nowmex);
        hav[va]=false;
    }
}
bool cmp(int a,int b){
    if(a>=n-1||b>=n-1||a<0||b<0)return false;
    if(edge[a].used==edge[b].used)return bool(rand()%2);
    return edge[a].used>edge[b].used;
}
int main(){
    #ifndef LOCAL
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    #else
    freopen("ex_tree2.in","r",stdin);
    freopen("ex_tree2.out","w",stdout);
    #endif
    int t=clock();
    n=read();
    for(int i = 1,u,v;i<n;i++){
        u=read(),v=read();if(u>v)swap(u,v);
        edge.push_back((EDGE){u,v,0,0});M[make_pair(u,v)]=i-1;
        ro[u].push_back(v),ro[v].push_back(u);
    }
    
    vector<int>idx(n-1);
    for(int i = 0;i<n-1;i++)idx[i]=i;
    for(int i = 1;i<=n;i++)root=i,dfs1(i,0);
    int res=0;
    while(clock()-t<2980){
        /* sort(idx.begin(),idx.end(),cmp); */
        if(n>9)shuffle(idx.begin(),idx.end(),engi);
        else next_permutation(idx.begin(),idx.end());
        for(int i = 0;i<n-1;i++)edge[idx[i]].val=i;
        ans=0;
        for(int i = 1;i<=n;i++){
            root=i,dfs2(i,0,0);
        }
        res=max(res,ans);
    }
    cout<<res;
    return 0;
}