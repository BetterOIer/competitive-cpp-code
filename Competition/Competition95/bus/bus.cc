#include<iostream>
#include<queue>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,p,t;
struct node{
    int to;
    long long val;
};
vector<node>ro[100005];
vector<int> path[100005];
int m[100005],g[100005],getRng[100005],tot;
long long dis[100005];
bool vis[100005];
struct Qnode{
    int pos;
    long long val;
};
bool operator<(const Qnode a, Qnode b){return a.val>b.val;}
priority_queue<Qnode>Q;
int main(){
    /* freopen("bus.in","r",stdin);
    freopen("bus.ans","w",stdout); */
    n=read(),p=read(),t=read();tot=n;
    for(int i=1,rng,M;i<=p;i++){
        m[i]=read(),g[i]=read(),M=m[i]<<1,rng=tot+1,tot+=M,getRng[i]=rng;
        for(int j=0;j<=m[i];j++) path[i].push_back(read());
        for(int j=m[i]-1;j>=0;j--)path[i].push_back(path[i][j]);
        for(int j=0;j<M;j++){
            ro[path[i][j]].push_back((node){rng+j,-i});
            ro[rng+j].push_back((node){path[i][j+1],t});
            if (j != M-1)ro[rng+j].push_back((node){rng+j+1,1});
        }
    }

    /* Dji */
    for(int i=2;i<=tot;i++)dis[i]=0x3f3f3f3f;
    Q.push((Qnode){1,0});
    while(Q.size()){
        Qnode now=Q.top();Q.pop();
        if(vis[now.pos])continue;
        vis[now.pos]=true;
        for(node to:ro[now.pos]){
            int val = to.val;
            if(val<0){
				int d=dis[now.pos]+getRng[-val]-to.to;
				if(d<0) val=-d+1;
				else{
					d%=g[-val];
					if(d == 0)d=g[-val];
					val=g[-val]-d+1;
				}
			}
            if (to.to == n){
				printf ("%lld" , dis[now.pos]);
				return 0;
			}
            if(dis[to.to]>dis[now.pos]+val){
                dis[to.to]=dis[now.pos]+val;
                Q.push((Qnode){to.to,dis[to.to]});
            }
        }
    }
    return 0;
}

/* 10 2 6
9 3
4 3 6 9 5 10 7 1 2 8 
2 4
1 3 9 
1 2
10 8 
 */