#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m;
int a[1000005],dp[1000005];
struct EDGE{
    int l;
    int r;
};
vector<EDGE>edge;
bool operator < (const EDGE a,const EDGE b){
    if(a.r==b.r)return a.l<b.l;
    return a.r<b.r;
}
struct node{
    int minn;
}tr[1000005<<2];
void build(int pos,int l,int r){
    tr[pos].minn=1919810;
    if(l==r)return;
    int mid = (l+r)>>1;
    build(pos<<1,l,mid);build(pos<<1|1,mid+1,r);
}
void update(int pos,int l,int r,int x,int val){
    if(l==r) return tr[pos].minn=val,void();
    int mid = (l+r)>>1;
    if(mid>=x)update(pos<<1,l,mid,x,val);
    else update(pos<<1|1,mid+1,r,x,val);
    tr[pos].minn=min(tr[pos<<1].minn,tr[pos<<1|1].minn);
}
int query(int pos,int l,int r,int x,int y){
    if(x<=l&&r<=y) return tr[pos].minn;
    int mid = (l+r)>>1,minn=1919810;
    if(mid>=x)minn=min(minn,query(pos<<1,l,mid,x,y));
    if(mid<y)minn=min(minn,query(pos<<1|1,mid+1,r,x,y));
    return minn;
}
int main(){
    #ifndef LOCAL
    freopen("ring.in","r",stdin);
    freopen("ring.out","w",stdout);
    #else
    freopen("ex_ring5.in","r",stdin);
    freopen("ex_ring5.out","w",stdout);
    #endif
    n=read(),m=read();
     for(int i = 1,l,r;i<=m;i++){
        l=read(),r=read();
        if(l>r)r+=n;
        edge.push_back((EDGE){l,r}); 
     }
     sort(edge.begin(),edge.end());
     for(int i = 1;i<=n;i++)dp[i]=1919810;
     build(1,1,n+1);update(1,1,n+1,1,0);dp[0]=0;
     for(EDGE i:edge){
        dp[i.r]=min(dp[i.r],query(1,1,n+1,max(1,i.l),i.r)+1);
        update(1,1,n+1,i.r+1,dp[i.r]);
     }
     if(dp[n]==1919810)cout<<"impossible";
     else cout<<dp[n];
    return 0;
}