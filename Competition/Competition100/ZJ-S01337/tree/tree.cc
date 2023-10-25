#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
const int N=1e5+5;
int head[N],len;
struct node{
    int to,nxt;
}; node edge[N<<1];
void add_edge(int u,int v){
    edge[++len]={v,head[u]}; head[u]=len;
}
int f[N];
void dfs(int u,int fa){
    f[u]=fa;
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v!=fa)
            dfs(v,u);
    }
}
__int128 calc(__int128 x){
    return x*(x+1)/2;
}
const __int128 awa=1;
inline __int128 calc(__int128 a,__int128 b,__int128 c){
    __int128 x=max(awa,min(a+1,(__int128)ceil(1.0*(1-b)/c)));
    if(c<0)
        return (x-1)*b+calc(x-1)*c+(a-x+1);
    else if(c==0)
        return a*b;
    else
        return (x-1)+(a-x+1)*b+(calc(a)-calc(x-1))*c;
}
long long a[N],b[N],c[N];
int p[N],t[N],n;
bool used[N];
int update(int u){
    if(used[u])
        return 0;
    used[u]=true;
    if(f[u])
        return update(f[u])+1;
    return 1;
}
bool check(int x){
    for(int i = 1;i<=n;i++){
        used[i]=false;
        __int128 val=calc(x,b[i],c[i]);
        if(val<a[i])
            return false;
        int l=1,r=n,ans=-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(val-calc(mid-1,b[i],c[i])>=a[i])
                ans=mid,l=mid+1;
            else
                r=mid-1;
        }
        t[i]=ans;
    }
    sort(p+1,p+n+1,[](const int &x,const int &y){
        return t[x]<t[y];
    });
    int res=0;
    for(int i = 1;i<=n;i++){
        res+=update(p[i]);
        if(res>t[p[i]])
            return false;
    }
    return true;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read();
    for(int i = 1;i<=n;i++)a[i]=read(),b[i]=read(),c[i]=read(),p[i]=i;
    for(int i = 2;i<=n;i++){
        int u=read(),v=read();
        add_edge(u,v);
        add_edge(v,u);
    }
    dfs(1,0);
    int l=n,r=1e9,ans=1e9;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))
            r=mid-1,ans=mid;
        else
            l=mid+1;
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}