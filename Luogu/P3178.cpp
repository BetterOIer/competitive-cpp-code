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
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,m,cnt;
string s;
long long val[100005],fa[100005],dep[100005],siz[100005],hvSon[100005],dfn[100005],top[100005],rdfn[100005];
vector<long long>ro[100005];

/* ======= 树链剖分部分 ========= */
void dfs1(long long pos,long long fat){
    fa[pos]=fat,dep[pos]=dep[fat]+1,siz[pos]=1;
    for(long long i:ro[pos]){
        if(i==fat)continue;
        dfs1(i,pos);
        siz[pos]+=siz[i];
        if(!hvSon[pos]||siz[hvSon[pos]]<siz[i])hvSon[pos]=i;
    }
}
void dfs2(long long pos,long long nTop){
    dfn[pos]=++cnt,rdfn[cnt]=pos;top[pos]=nTop;
    if(hvSon[pos])dfs2(hvSon[pos],nTop);
    for(long long i:ro[pos]){
        if(i==fa[pos]||i==hvSon[pos])continue;
        dfs2(i,i);
    }
}

/* ======= 线段树部分 ========= */
struct node{
    long long sum,tag;
}tr[100005*20];
void pushUp(long long pos){
    tr[pos].sum=tr[pos<<1].sum+tr[pos<<1|1].sum;
}
void pushDown(long long pos,long long l,long long r){
    if(!tr[pos].tag)return;
    int mid =(l+r)>>1;
    tr[pos<<1].sum+=tr[pos].tag*(mid-l+1);
    tr[pos<<1|1].sum+=tr[pos].tag*(r-mid);
    tr[pos<<1].tag+=tr[pos].tag;
    tr[pos<<1|1].tag+=tr[pos].tag;
    tr[pos].tag=0;
}
void build(long long pos,long long l,long long r){
    if(l==r)return tr[pos].sum=val[rdfn[l]],void();
    long long mid = (l+r)>>1;
    build(pos<<1,l,mid);build(pos<<1|1,mid+1,r);
    pushUp(pos);
}
void update(long long pos,long long l,long long r,long long x,long long y,long long val){
    if(x<=l&&r<=y) return tr[pos].sum+=val*(r-l+1),tr[pos].tag+=val,void();
    long long mid = (l+r)>>1;pushDown(pos,l,r);
    if(mid>=x)update(pos<<1,l,mid,x,y,val);
    if(mid<y)update(pos<<1|1,mid+1,r,x,y,val);
    return pushUp(pos);
}
long long segSum(long long pos,long long l,long long r,long long x,long long y){
    if(x<=l&&r<=y)return tr[pos].sum;
    long long mid = (l+r)>>1,ans=0;pushDown(pos,l,r);
    if(mid>=x)ans+=segSum(pos<<1,l,mid,x,y);
    if(mid<y)ans+=segSum(pos<<1|1,mid+1,r,x,y);
    return ans;
}
long long querySum(long long u,long long v){
    long long ans =0;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        ans+=segSum(1,1,n,dfn[top[u]],dfn[u]);
        u=fa[top[u]];
    }
    if(dep[u]<dep[v])swap(u,v);
    ans+=segSum(1,1,n,dfn[v],dfn[u]);
    return ans;
}

int main(){
    n=read();m=read();
    for(long long i = 1;i<=n;i++) val[i]=read();
    for(long long i = 1,u,v;i<n;i++){
        u=read(),v=read();
        ro[u].emplace_back(v);
        ro[v].emplace_back(u);
    }dfs1(1,0);dfs2(1,1);
    //for(long long i = 1;i<=n;i++)cout<<dfn[i]<<" \n"[i==n];
    build(1,1,n);
    for(long long i = 1,opt,u,v;i<=m;i++){
        opt=read();u=read();
        if(opt==1){
            v=read();
            update(1,1,n,dfn[u],dfn[u],v);
        }else if(opt==2){
            v=read();
            update(1,1,n,dfn[u],dfn[u]+siz[u]-1,v);
        }else{
            cout<<querySum(u,1)<<endl;
        }
        //for(long long j = 1;j<=n;j++)cout<<querySum(j,j)<<" \n"[j==n];
    }
    return 0;
}