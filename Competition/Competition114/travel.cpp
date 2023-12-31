// #include<iostream>
// #include<vector>
// #include<queue>
// #include<map>
// using namespace std;
// inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
// struct node{
//     long long to;
//     long long val;
// };
// vector<node>ro[1005];
// deque<long long>stk;
// vector<long long>scc[1005],rscc[1005];
// map<pair<long long, long long>, long long >edge;
// bool instack[1005];
// long long n,m,k,q;
// long long dfn[1005],tot=0,cnt=0;
// long long val[1005];
// void Tarjan(long long pos){
//     dfn[pos]=++tot;
//     stk.push_front(pos);
//     instack[pos]=true;
//     for(node to:ro[pos]){
//         if(!dfn[to.to]){
//             Tarjan(to.to);
//         }else if(instack[to.to]){
//             long long y,last=to.to;++cnt;
//             do{
//                 y=stk.front();stk.pop_front();
//                 instack[y]=false,scc[cnt].push_back(y),rscc[y].push_back(cnt),val[cnt]+=edge[make_pair(y,last)],last=y;
//             }while(y!=to.to);
//             stk.push_front(y);instack[y]=true;
//         }
//     }
// }
// long long main(){
//     #ifndef LOCAL
//     freopen("travel.in","r",stdin);
//     freopen("travel.out","w",stdout);
//     #else
//     /* freopen("extravel_2.in","r",stdin);
//     freopen("extravel_2.res","w",stdout); */
//     #endif
//     long long n=read(),m=read(),k=read(),q=read();
//     for(long long i = 1,u,v,w;i<=m;i++){
//         u=read(),v=read(),w=read();
//         ro[u].push_back((node){v,w});
//         edge[make_pair(u,v)]=w;
//     }
//     Tarjan(1);
//     while(stk.size()){
//         long long y=stk.front();stk.pop_front();++cnt;
//         instack[y]=false;scc[cnt].push_back(y),rscc[y].push_back(cnt);
//     }
//     for(long long i = 1;i<=n;i++){
//         if(rscc[i].size()>1)
//     }
//     return 0;
// }


//! 不会写辣!!!

#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
struct node{
    long long pos;
    long long val;
};
long long n,m,k,q;
vector<node>ro[1005];
long long vis[1005];
set<long long>val[1005];
void solve(long long pos){
    queue<node>Q;while(Q.size())Q.pop();
    for(long long i = 1;i<=n;i++)val[i].clear();
    for(long long i = 1;i<=n;i++)vis[i]=0;
    Q.push(node{1,k});
    while(Q.size()){
        node now = Q.front();Q.pop();
        //cout<<now.val<<endl;
        if(val[now.pos].find(now.val)==val[now.pos].end())val[now.pos].insert(now.val);
        else continue;
        if(!vis[now.pos]){
            vis[now.pos]=now.val;
        }else for(long long i = now.val-(vis[now.pos]-now.val);i>=0;i-=(vis[now.pos]-now.val))Q.push((node){now.pos,i});
        if(now.pos==pos) continue;
        for(node to:ro[now.pos]){
            if(now.val-to.val>=0)Q.push((node){to.pos,now.val-to.val});
        }
    }
    cout<<val[pos].size()<<endl;
}
int main(){
    #ifndef LOCAL
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    #else
    freopen("extravel_2.in","r",stdin);
    freopen("extravel_2.res","w",stdout);
    #endif
    n=read(),m=read(),k=read(),q=read();
    for(long long i = 1,u,v,w;i<=m;i++){
        u=read(),v=read(),w=read();
        ro[u].push_back((node){v,w});
    }
    for(long long i = 1,x;i<=q;i++){
        x=read();solve(x);
    }
    return 0;
}