#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,m;
struct node{
    long long to;
    long long val;
};
struct Qnode{
    long long pos;
    long long val;
    long long step;
};
vector<node>ro[300005];
queue<Qnode>Q;
long long ans = 1145141919810;
int main(){
    freopen("elegans.in","r",stdin);
    freopen("elegans.out","w",stdout);
    n=read(),m=read();
    for(long long i = 1,u,v,w;i<=m;i++){
        u=read(),v=read(),w=read();
        ro[u].push_back((node){v,w});
    }
    Q.push((Qnode){1,0,1});
    while(Q.size()){
        Qnode now = Q.front();Q.pop();
        if(now.pos==n){ans = min(ans,now.val);continue;}
        if(now.val>ans)continue;
        for(node to:ro[now.pos]){
            Q.push((Qnode){to.to,max(now.val,to.val*now.step),now.step+1});
        }
    }
    cout<<ans;
    return 0;
}