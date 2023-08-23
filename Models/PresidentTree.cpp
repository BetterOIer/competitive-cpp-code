#include<bits/stdc++.h>
using namespace std;
int sz=0;
struct node{
    int l;
    int r;
    int val;
}tree[40000005];
int a[1000005];
int root[100005];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
void update(int pre,int &now,int l,int r,int x,int val){
    now=++sz;
    tree[now]=tree[pre];
    if(l==r){
        tree[now].val=val;
        return ;
    }
    int mid = (l+r)>>1;
    if(x<=mid) update(tree[pre].l,tree[now].l,l,mid,x,val);
    else update(tree[pre].r,tree[now].r,mid+1,r,x,val);
    return ;
}
int query(int now,int l,int r,int x){
    if(l==r)return tree[now].val;
    int mid=(r+l)>>1;
    if(mid>=x) return query(tree[now].l,l,mid,x);
    else return query(tree[now].r,mid+1,r,x);
}
int build(int l,int r){
    int pos=++sz;tree[pos].val=0;
    if(l==r){
        tree[pos].val=a[l];
        return pos;
    }
    int mid=(l+r)>>1;
    tree[pos].l=build(l,mid);
    tree[pos].r=build(mid+1,r);
    return pos;
}
int main(){
    int n,m,rt,mode,x,y;
    n=read(),m=read();
    for(int i = 1;i<=n;i++) a[i]=read();
    root[0]=build(1,n);
    for(int i=1;i<=m;i++){
		rt=read(),mode=read(),x=read();
		if(mode==1){
			y=read();
			update(root[rt],root[i],1,n,x,y);
		}
		else{
			printf("%d\n",query(root[rt],1,n,x));
			root[i]=root[rt];
		}
	}
}