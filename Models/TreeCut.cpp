#include<iostream>
#include<vector>
using namespace std;
struct node1{
	int fa;
	int son;
	int size;
	int depth;
	int top;
	int id; 
	int data;
	vector <int> sons;
}tree[55];
int rev[55],cnt=0,n,m,r,mod,e,u,v;
struct node2{
	int l;
	int r;
	int data;
	int f;
	int lazy=0;
}SMT[25];
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
void dfs1(int pos,int fa){
	tree[pos].size=1;
	tree[pos].fa=fa;
	int mson=0,msonid=0;
	for(int i = 0;i<=tree[pos].sons.size()-1;i++){
		if(tree[pos].sons[i]==fa)continue;
		dfs1(tree[pos].sons[i],pos);
		tree[pos].size+=tree[tree[pos].sons[i]].size;
		if(tree[tree[pos].sons[i]].size>mson){
			mson=tree[tree[pos].sons[i]].size;
			msonid=tree[pos].sons[i];
		}
	}
	tree[pos].son=msonid;
	tree[pos].depth=tree[fa].depth+1;
}
void dfs2(int pos,int top){
	tree[pos].top=top;
	tree[pos].id=++cnt;
	rev[cnt]=pos;
	if(!tree[pos].son) return;
	dfs2(tree[pos].son,top);
	for(int i=0;i<=tree[pos].sons.size()-1;i++){
		if(tree[pos].sons[i]==tree[pos].fa||tree[pos].sons[i]==tree[pos].son)continue;
		dfs2(tree[pos].sons[i],tree[pos].sons[i]);
	}
}

void pushup(int pos){
	SMT[pos].data=(SMT[pos<<1].data+SMT[pos<<1|1].data)%mod;
}
void pushdown(int pos){
	SMT[pos<<1].lazy+=SMT[pos].lazy;
	SMT[pos<<1|1].lazy+=SMT[pos].lazy;
	SMT[pos<<1].data=(SMT[pos<<1].data+SMT[pos].lazy*(SMT[pos<<1].r-SMT[pos<<1].l+1))%mod;
	SMT[pos<<1|1].data=(SMT[pos<<1|1].data+SMT[pos].lazy*(SMT[pos<<1|1].r-SMT[pos<<1|1].l+1))%mod;
	SMT[pos].lazy=0;
}
void listupdate(int pos,int l,int r,int x,int y,int data){
	if(SMT[pos].l>=x&&SMT[pos].r<=y){
		SMT[pos].lazy=(SMT[pos].lazy+data)%mod;
		SMT[pos].data=(SMT[pos].data+data*(r-l+1))%mod;
		return;
	}
	pushdown(pos);
	int mid=(SMT[pos].l+SMT[pos].r)>>1;
	if(x<=mid)listupdate(pos<<1,l,mid,x,y,data);
	if(mid<y)listupdate(pos<<1|1,mid+1,r,x,y,data);
	pushup(pos);
}
long long listquery(int pos,int x,int y){
	long long sum=0;
	if(SMT[pos].l>=x&&SMT[pos].r<=y){
		return SMT[pos].data%mod;
	}
	pushdown(pos);
	int mid=(SMT[pos].l+SMT[pos].r)>>1;
	if(x<=mid)sum+=listquery(pos<<1,x,y);
	if(mid<y)sum+=listquery(pos<<1|1,x,y);
	return sum;
}
void update(int x,int y,int data){
    while(tree[x].top!=tree[y].top){
        if(tree[tree[x].top].depth<tree[tree[y].top].depth)swap(x,y);
        listupdate(1,1,n,tree[tree[x].top].id,tree[x].id,data);
        x=tree[tree[x].top].fa;
    }
    if(tree[x].depth>tree[y].depth)swap(x,y);
    listupdate(1,1,n,tree[x].id,tree[y].id,data);
}
long long query(int x,int y){
	long long sum=0;
	while(tree[x].top!=tree[y].top){
		if(tree[tree[x].top].depth<tree[tree[y].top].depth) swap(x,y);
		sum=(sum+listquery(1,tree[tree[x].top].id,tree[x].id))%mod;
		x=tree[tree[x].top].fa;
	}
	if(tree[x].depth>tree[y].depth) swap(x,y);
	sum=(sum+listquery(1,tree[x].id,tree[y].id))%mod;
	return sum;
}
void build(int pos,int l,int r){
	SMT[pos].l=l;
	SMT[pos].r=r;
	if(l==r){
		SMT[pos].data=tree[rev[l]].data%mod;
		return;
	}
	int mid=(l+r)>>1;
	build(pos<<1,l,mid);
	build(pos<<1|1,mid+1,r);
	pushup(pos);
}
int main(){
	n=read();m=read();r=read();mod=read();
    for(int i=1;i<=n;i++)tree[i].data=read();
    for(int i=1;i<n;i++){
        u=read(),v=read();
		tree[u].sons.push_back(v);
		tree[v].sons.push_back(u);
    }
    dfs1(r,0);
    dfs2(r,r);
    build(1,1,n);
	//for(int i = 1; i <= n; ++i) printf("%lld ", query(i, i)); puts("");
    while(m--){
        int k,x,y,z;
        k=read();
        if(k==1){
            x=read();y=read();z=read();
            update(x,y,z);
        }
        else if(k==2){
            x=read();y=read();
            printf("%lld\n",query(x,y));
        }
        else if(k==3){
            x=read();y=read();
            listupdate(1,1,n,tree[x].id,tree[x].id+tree[x].size-1,y);
        }
        else{
            x=read();
            printf("%lld\n",listquery(1,tree[x].id,tree[x].id+tree[x].size-1));
        }
    }
}
