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
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
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


/* ======= 线段树部分 ========= */
int root[100005];
struct node{
    int sum,tag=-1;
}tr[100005*20];
void pushDown(int pos,int l,int r){
    if(tr[pos].tag==-1)return;
    int mid = (l+r)>>1;
    tr[pos<<1].sum=(mid-l+1)*tr[pos].tag;
    tr[pos<<1|1].sum=(r-mid)*tr[pos].tag;
    tr[pos<<1].tag=tr[pos<<1|1].tag=tr[pos].tag;
    tr[pos].tag=-1;
}
void update(int pos,int l,int r,int x,int y,int val){
    if(x<=l&&r<=y)return tr[pos].sum=(r-l+1)*val,tr[pos].tag=val,void();
    int mid = (l+r)>>1;pushDown(pos,l,r);
    if(mid>=x)update(pos<<1,l,mid,x,y,val);
    if(mid<y)update(pos<<1|1,mid+1,r,x,y,val);
    return tr[pos].sum=tr[pos<<1].sum+tr[pos<<1|1].sum,void();
}
void updateSeg(int u,int v,int val){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        update(1,1,n,dfn[top[u]],dfn[u],val);
        u=fa[top[u]];
    }
    if(dep[u]<dep[v])swap(u,v);
    update(1,1,n,dfn[v],dfn[u],val);
}
int main(){
    totRoot=0;
    n=read();
    for(int i = 2,u;i<=n;i++){
        u=read()+1;
        ro[u].emplace_back(i);
        ro[i].emplace_back(u);
    }
    dfs1(1,0);dfs2(1,1);
    m=read();
    while(m--){
        cin>>s;int x=read()+1,last=tr[1].sum;;
        if(s=="install"){
            updateSeg(1,x,1);
            cout<<abs(last-tr[1].sum)<<endl;
        }else if(s=="uninstall"){
            update(1,1,n,dfn[x],dfn[x]+siz[x]-1,0);
            cout<<abs(last-tr[1].sum)<<endl;
        }
    }
    return 0;
}