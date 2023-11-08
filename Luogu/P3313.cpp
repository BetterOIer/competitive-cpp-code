/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int totRoot/* 存储主席树的根的个数 */,n,m,cnt/* 记录dfs序 */;
string s;
int scr[100005],rlg[100005],fa[100005],dep[100005],siz[100005],hvSon[100005],dfn[100005],top[100005];
vector<int>ro[100005];

/* ======= 树链剖分部分 ========= */
void dfs1(int pos,int fat){
    fa[pos]=fat,dep[pos]=dep[fat]+1,siz[pos]=1;
    for(int i:ro[pos]){
        if(i==fat)continue;
        dfs1(i,pos);
        siz[pos]+=siz[i];
        if(!hvSon[pos]||siz[hvSon[pos]]<siz[i])hvSon[pos]=i;
    }
}
void dfs2(int pos,int nTop){
    dfn[pos]=++cnt;top[pos]=nTop;
    if(hvSon[pos])dfs2(hvSon[pos],nTop);
    for(int i:ro[pos]){
        if(i==fa[pos]||i==hvSon[pos])continue;
        dfs2(i,i);
    }
}


/* ======= 线段树部分部分 ========= */
int root[100005];
struct node{
    int l,r,maxn,sum;
}tr[100005*20];
void update(int &pos,int w,int l,int r,int pdfn){
    if(!pos)pos=++totRoot;
    tr[pos].maxn=max(tr[pos].maxn,w),tr[pos].sum+=w;
    if(l==r)return;
    int mid = (l+r)>>1;
    if(mid>=pdfn)update(tr[pos].l,w,l,mid,pdfn);
    else update(tr[pos].r,w,mid+1,r,pdfn);
}
void remove(int &pos,int l,int r,int pdfn){
    if(l==r) return tr[pos].sum=0,tr[pos].maxn=0,void();
    int mid = (l+r)>>1;
    if(mid>=pdfn)remove(tr[pos].l,l,mid,pdfn);
    else remove(tr[pos].r,mid+1,r,pdfn);
    tr[pos].sum=tr[tr[pos].l].sum+tr[tr[pos].r].sum;
    tr[pos].maxn=max(tr[tr[pos].l].maxn,tr[tr[pos].r].maxn);
}
int queryMax(int pos,int l,int r,int x,int y){
    if(x<=l&&r<=y)return tr[pos].maxn;
    int mid = (l+r)>>1,res=0;
    if(mid>=x)res=max(res,queryMax(tr[pos].l,l,mid,x,y));
    if(mid<y)res=max(res,queryMax(tr[pos].r,mid+1,r,x,y));
    return res;
}
int querySum(int pos,int l,int r,int x,int y){
    if(x<=l&&r<=y)return tr[pos].sum;
    int mid = (l+r)>>1,res=0;
    if(mid>=x)res+=querySum(tr[pos].l,l,mid,x,y);
    if(mid<y)res+=querySum(tr[pos].r,mid+1,r,x,y);
    return res;
}
int segMax(int u,int v,int prlg){
    int ans=0;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        ans=max(ans,queryMax(root[prlg],1,n,dfn[top[u]],dfn[u]));
        u=fa[top[u]];
    }
    if(dep[u]<dep[v])swap(u,v);
    ans=max(ans,queryMax(root[prlg],1,n,dfn[v],dfn[u]));
    return ans;
}
int segSum(int u,int v,int prlg){
    int ans=0;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        ans=ans+querySum(root[prlg],1,n,dfn[top[u]],dfn[u]);
        u=fa[top[u]];
    }
    if(dep[u]<dep[v])swap(u,v);
    ans=ans+querySum(root[prlg],1,n,dfn[v],dfn[u]);
    return ans;
}
int main(){
    totRoot=0;
    n=read(),m=read();
    for(int i = 1;i<=n;i++){
        scr[i]=read(),rlg[i]=read();
    }
    for(int i = 1,u,v;i<n;i++){
        u=read(),v=read();
        ro[u].emplace_back(v);
        ro[v].emplace_back(u);
    }
    dfs1(1,0);dfs2(1,1);
    for(int i = 1;i<=n;i++){
        update(root[rlg[i]],scr[i],1,n,dfn[i]);
    }
    while(m--){
        cin>>s;int x=read(),y=read();
        if(s=="CC"){
            remove(root[rlg[x]],1,n,dfn[x]);
            update(root[y],scr[x],1,n,dfn[x]);
            rlg[x]=y;
        }else if(s=="CW"){
            remove(root[rlg[x]],1,n,dfn[x]);
            update(root[rlg[x]],y,1,n,dfn[x]);
            scr[x]=y;
        }else if(s=="QS"){
            cout<<segSum(x,y,rlg[x])<<endl;
        }else if(s=="QM"){
            cout<<segMax(x,y,rlg[x])<<endl;
        }
    }
    return 0;
}