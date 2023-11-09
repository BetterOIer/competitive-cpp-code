#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,k;
struct EDGE{
    int u,v,t,tag;
};
vector<EDGE>edge;
vector<int>ro[15];
bool vis[15],col[15];
bool operator < (const EDGE a,const EDGE b){
    return a.t<b.t;
}
void update(EDGE i){
    if(i.tag==1){
        ro[i.u].push_back(i.v);
        ro[i.v].push_back(i.u);
    }else{
        for(int j = 0;j<ro[i.u].size();j++){
            if(ro[i.u][j]==i.v){
                ro[i.u][j]=ro[i.u][ro[i.u].size()-1];
                break;
            }
        }
        for(int j = 0;j<ro[i.v].size();j++){
            if(ro[i.v][j]==i.u){
                ro[i.v][j]=ro[i.v][ro[i.v].size()-1];
                break;
            }
        }
    }
}
bool dfs(int pos,int fa){
    col[pos]=col[fa]^1;
    vis[pos]=1;
    for(int i:ro[pos]){
        if(i==fa)continue;
        if(!vis[i]){if(!dfs(i,pos))return false;}
        else if(col[i]==col[pos])return false;
    }
    return true;
}
bool run(){
    memset(vis,0,sizeof vis);
    memset(col,0,sizeof col);
    return dfs(1,0);
}
int main(){
    #ifndef LOCAL
    freopen("yume.in","r",stdin);
    freopen("yume.out","w",stdout);
    #else
    freopen("ex_yume1.in","r",stdin);
    freopen("ex_yume1.res","w",stdout);
    #endif
    n=read(),m=read(),k=read();
    for(int i = 1,u,v,l,r;i<=m;i++){
        u=read(),v=read(),l=read(),r=read();
        edge.push_back((EDGE){u,v,l,1});
        edge.push_back((EDGE){u,v,r,-1});
    }
    sort(edge.begin(),edge.end());
    int t=0;
    for(EDGE i:edge){
        if(i.t==t){
            update(i);
        }else{
            bool ans = run();
            int delt = i.t-t;
            for(int j =1;j<=delt;j++)cout<<(ans? "Yes\n":"No\n");
            t=i.t;
            update(i);
        }
    }
    return 0;
}