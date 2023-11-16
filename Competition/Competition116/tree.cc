#include<bits/stdc++.h>
using namespace std;
const int maxn=3010;
vector<int> ver[maxn];
inline void addedge(int a,int b)
{
    ver[a].push_back(b);ver[b].push_back(a);
}
int n;
int mxdep,rt,fa[maxn];
int size[maxn],st,sum[maxn],go[maxn][maxn],in[maxn],out[maxn],dfncnt,dep[maxn];
int stk[maxn],top;
// x is in y
inline void getsize(int x,int fat)
{
    size[x]=1;fa[x]=fat;dep[x]=dep[fat]+1;
    stk[++top]=x;in[x]=++dfncnt;
    for(int i=top-1;i;i--) go[stk[i]][x]=stk[i+1];
    for(int i=0;i<(int)ver[x].size();i++)
    {
        int y=ver[x][i];if(y==fat) continue;
        getsize(y,x);size[x]+=size[y];
    }
    top--;out[x]=dfncnt;
}
inline bool isin(int x,int a){return in[a]>=in[x]&&in[a]<=out[x];}
inline int Getsize(int x,int oth)
{
    if(isin(x,oth)) return n-size[go[x][oth]];
    return size[x];
}
long long f[maxn][maxn];
inline bool ison(int a,int x,int y)
{
    if(dep[x]>dep[y]) swap(x,y);
    if(isin(x,y))
    {
        return a==go[x][y]||a==fa[y];
    }
    return a==fa[x]||a==fa[y];
}
inline long long getdp(int x,int y)
{
    if(f[x][y]>=0) return f[x][y];
    long long ans=0;
    for(int i=0;i<(int)ver[x].size();i++)
    {
        int z=ver[x][i];if(ison(z,x,y)&&x!=y) continue;
        ans=max(ans,getdp(z,y)+1ll*Getsize(z,y)*Getsize(y,z));
    }
    for(int i=0;i<(int)ver[y].size();i++)
    {
        int z=ver[y][i];if(ison(z,x,y)&&x!=y) continue;
        ans=max(ans,getdp(x,z)+1ll*Getsize(x,z)*Getsize(z,x));
    }
    return f[x][y]=ans;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1,a,b;i<n;i++) scanf("%d%d",&a,&b),addedge(a,b);
    memset(f,-1,sizeof(f));getsize(1,0);
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,getdp(i,i));
    }
    printf("%lld\n",ans);
}
