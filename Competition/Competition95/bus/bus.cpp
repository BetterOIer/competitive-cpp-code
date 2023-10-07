#include<iostream>
#include<vector>
#include<queue>
using namespace std;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
long long n,p,t;
long long g[100005];
long long path[200005],cnt=0,sta[100005];
struct node{
    long long to;
    long long bus;
    long long id;
};
vector<node>ro[100005];
struct DFN{
    long long pos;
    long long tim;
    long long last;
    long long nexPos;
};
bool operator < (DFN a,DFN b){
    return a.tim<b.tim;
}
priority_queue<DFN>Q;
int main(){
    freopen("bus2.in","r",stdin);
    freopen("bus2.ans","w",stdout);
    n=read(),p=read(),t=read();
    for(long long i = 1,m;i<=p;i++){
        m=read(),g[i]=read();
        long long u=read(),v;sta[i]=++cnt;path[cnt]=u;
        for(long long j = 1;j<=m;j++){
            v=u;u=read();path[++cnt]=u;
            ro[u].push_back((node){v,i,j});
            ro[v].push_back((node){u,i,2*m-j});
        }
    }
    sta[p+1]=++cnt;
    Q.push((DFN){1,-t,0,0});
    long long ans = 2147483647;
    while(Q.size()){
        DFN now = Q.top();Q.pop();
        if(now.tim>ans)continue;
        if(now.pos==n){
            ans=min(ans,now.tim);
        }
        for(node to:ro[now.pos]){
            if(now.last==to.bus&&now.nexPos==to.to)Q.push((DFN){to.to,now.tim+1,to.bus,path[sta[to.bus]+(to.id+1<sta[to.bus+1]-sta[to.bus]? to.id+1:2*(sta[to.bus+1]-sta[to.bus]-1)-(to.id+1))]});
            else{
                DFN nex;
                nex.last = to.bus;
                nex.pos = to.to;
                nex.tim = (now.tim+t<to.id? to.id:now.tim+t+g[to.bus]-((now.tim+t-to.id)-(now.tim+t-to.id)/g[to.bus]*g[to.bus]));
                nex.nexPos = path[sta[to.bus]+(to.id+1<sta[to.bus+1]-sta[to.bus]? to.id+1:2*(sta[to.bus+1]-sta[to.bus]-1)-(to.id+1))];
                Q.push(nex);
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}