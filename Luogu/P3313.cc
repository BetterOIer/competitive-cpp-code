#include<bits/stdc++.h>
using namespace std;
struct node{
    int to,next;
}g[1000000];
int tot,n,m,cnt,w[100004],zj[100004],len,head[100004],dep[100004],wson[100004],top[100004],tpos[100004],fa[100004],siz[100004];
inline void made(int from,int to){
    g[++tot].to=to;
    g[tot].next=head[from];
    head[from]=tot;
}
inline void dfs1(int rt,int ff){
    fa[rt]=ff;dep[rt]=dep[ff]+1;siz[rt]=1;
    for (int i=head[rt];i;i=g[i].next){
        int v=g[i].to;
        if (v==ff) continue;
        dfs1(v,rt);
        siz[rt]+=siz[v];
        if (!wson[rt]||siz[wson[rt]]<siz[v]) wson[rt]=v;
    }
}
inline void dfs2(int rt,int tops){
    tpos[rt]=++cnt;top[rt]=tops;
    if (wson[rt]) dfs2(wson[rt],tops);
    for (int i=head[rt];i;i=g[i].next){
        int v=g[i].to;
        if (v==fa[rt]||v==wson[rt]) continue;
        dfs2(v,v);
    }
}
int root[100004];
struct Node{
    int l,r,max,tot;
}tree[20000110];
inline void update(int &rt,int w,int l,int r,int pos){
    if (!rt) rt=++len;
    tree[rt].max=max(tree[rt].max,w),tree[rt].tot+=w;
    if (l==r) return;
    int mid=(l+r)/2;
    if (mid>=pos) update(tree[rt].l,w,l,mid,pos);
    else update(tree[rt].r,w,mid+1,r,pos);
}
inline void remove(int &rt,int l,int r,int pos){
    if (l==r){ tree[rt].tot=0,tree[rt].max=0;return; }
    int mid=(l+r)/2;
    if (mid>=pos) remove(tree[rt].l,l,mid,pos);
    else remove(tree[rt].r,mid+1,r,pos);
    tree[rt].tot=tree[tree[rt].l].tot+tree[tree[rt].r].tot;
    tree[rt].max=max(tree[tree[rt].l].max,tree[tree[rt].r].max);
}
inline int querytot(int rt,int lb,int rb,int l,int r){
    if (r<lb||l>rb) return 0;
    if (r>=rb&&l<=lb) return tree[rt].tot;
    int mid=(lb+rb)/2;
    return querytot(tree[rt].l,lb,mid,l,r)+querytot(tree[rt].r,mid+1,rb,l,r);
}
inline int querymax(int rt,int lb,int rb,int l,int r){
    if (r<lb||l>rb) return 0;
    if (r>=rb&&l<=lb) return tree[rt].max;
    int mid=(lb+rb)/2;
    return max(querymax(tree[rt].l,lb,mid,l,r),querymax(tree[rt].r,mid+1,rb,l,r));
}
inline int sigmax(int u,int v,int zj){
    int ans=0;
    while (top[u]!=top[v]){
        if (dep[top[u]]<dep[top[v]]) swap(u,v);
        ans=max(ans,querymax(root[zj],1,n,tpos[top[u]],tpos[u]));
        u=fa[top[u]];
    }
    if (dep[u]<dep[v]) swap(u,v);
    ans=max(ans,querymax(root[zj],1,n,tpos[v],tpos[u]));
    return ans;
}
inline int sigtot(int u,int v,int zj){
    int ans=0;
    while (top[u]!=top[v]){
        if (dep[top[u]]<dep[top[v]]) swap(u,v);
        ans=ans+querytot(root[zj],1,n,tpos[top[u]],tpos[u]);
        u=fa[top[u]];
    }
    if (dep[u]<dep[v]) swap(u,v);
    ans=ans+querytot(root[zj],1,n,tpos[v],tpos[u]);
    return ans;
}
char s[100];
int main(){
    len=0;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%d%d",&w[i],&zj[i]);
    }
    int x,y;
    for (int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        made(x,y);made(y,x);
    }
    dfs1(1,0);dfs2(1,1);
    for (int i=1;i<=n;i++){
        update(root[zj[i]],w[i],1,n,tpos[i]);
    }		
    while (m--){
        scanf("%s",s);scanf("%d%d",&x,&y);
        switch (s[1]){
            case 'C':{
                remove(root[zj[x]],1,n,tpos[x]);
                update(root[y],w[x],1,n,tpos[x]);
                zj[x]=y;
                break;
            }
            case 'W':{
                remove(root[zj[x]],1,n,tpos[x]);
                update(root[zj[x]],y,1,n,tpos[x]);
                w[x]=y;
                break;
            }
            case 'S':{
                printf("%d\n",sigtot(x,y,zj[x]));
                break;
            } 
            case 'M':{
                printf("%d\n",sigmax(x,y,zj[x]));
                break;
            }
        }
    }
    return 0;
}