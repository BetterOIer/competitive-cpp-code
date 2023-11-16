#include<bits/stdc++.h>
using namespace std;
#define go(u) for(int i=head[u],v=e[i].to;i;i=e[i].last,v=e[i].to)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define pb push_back
typedef long long LL;
inline int gi(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-48;ch=getchar();}
    return x*f;
}
template<typename T>inline bool Max(T &a,T b){return a<b?a=b,1:0;}
template<typename T>inline bool Min(T &a,T b){return b<a?a=b,1:0;}
const int N=1e6 + 7,inf=0x3f3f3f3f;
int m,len,ans=inf;
int fa[N][21],mn[N];
struct data{
    int l,r;
    bool operator <(const data &rhs)const{
        if(r!=rhs.r) return r<rhs.r;
        return l<rhs.l;
    }
}t[N];
int main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
    len=gi(),m=gi();
    rep(i,1,m) {
        t[i].l=gi(),t[i].r=gi();
        if(t[i].r<t[i].l) t[i].r+=len;
    }
    sort(t+1,t+1+m);
    mn[m+1]=inf;
    for(int i=m;i;i--) mn[i]=min(t[i].l,mn[i+1]);
    for(int i=1,j=1;i<=m;++i){
        while(j+1<=m&&mn[j+1]-1<=t[i].r)++j;
        if(i!=j) fa[i][0]=j;
    }
    for(int i=m;i;--i)
    for(int j=1;j<=20;++j) fa[i][j]=fa[fa[i][j-1]][j-1];
    
    for(int i=1;i<=m;++i){
        int s=1,x=i;
        for(int j=20;~j;--j) if(fa[x][j]&&t[fa[x][j]].r-t[i].l+1<len) x=fa[x][j],s+=1<<j;
        if(fa[x][0]&&t[x].r-t[i].l+1<len) ++s,x=fa[x][0];
        if(t[x].r-t[i].l+1>=len) Min(ans,s);
    }
    if(ans==inf) puts("impossible");
    else printf("%d\n",ans);
    return 0;
}
