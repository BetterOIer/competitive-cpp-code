#include<iostream>
using namespace std;
const int maxn = 5e5+5;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,q;
struct node{
    int val;
    int tag=0;
}tr[maxn<<2];
int tag[maxn];
void pushUp(int pos){
    tr[pos].val=tr[pos<<1].val+tr[pos<<1|1].val;
}
void build(int pos,int l,int r){
    if(l==r){
        tr[pos].val = 500000;
        tag[l]=-1;
        return ;
    }
    int mid = (l+r)>>1;
    build(pos<<1,l,mid);build(pos<<1|1,mid+1,r);
    pushUp(pos);
}
void pushDown(int pos,int l,int r,int mid){
    if(!tr[pos].tag)return;
    tr[pos<<1].tag+=tr[pos].tag;
    tr[pos<<1|1].tag+=tr[pos].tag;
    tr[pos<<1].val+=tr[pos].tag*(mid-l+1);
    if(mid-l+1==1) if(tr[pos<<1].val<tag[l])tag[l]=-1;
    tr[pos<<1|1].val+=tr[pos].tag*(r-mid);
    if(r-mid==1) if(tr[pos<<1|1].val<tag[r])tag[r]=-1;
    tr[pos].tag=0;
}
void updateArea(int pos,int l,int r,int x,int y,int val){
    if(x<=l&&r<=y){
        tr[pos].val+=(r-l+1)*val;
        tr[pos].tag+=val;
        return ;
    }
    int mid = (l+r)>>1;
    pushDown(pos,l,r,mid);
    if(mid>=x)updateArea(pos<<1,l,mid,x,y,val);
    if(mid<y)updateArea(pos<<1|1,mid+1,r,x,y,val);
    pushUp(pos);
}
void updatePoint(int pos,int l,int r,int x,int val){
    if(l==r){
        return tr[pos].val=val,void();
    }
    int mid = (l+r)>>1;
    pushDown(pos,l,r,mid);
    if(mid>=x) updatePoint(pos<<1,l,mid,x,val);
    else updatePoint(pos<<1|1,mid+1,r,x,val);
    pushUp(pos);
}
int query(int pos,int l,int r,int x){
    if(l==r){
        return tr[pos].val;
    }
    int mid = (l+r)>>1;
    pushDown(pos,l,r,mid);
    if(mid>=x) return query(pos<<1,l,mid,x);
    else return query(pos<<1|1,mid+1,r,x);
}
void makeTag(int l,int r){
    for(int i = l;i<=r;i++){
        int val = query(1,1,n,i);
        tag[i]=min(tag[i],val);
    }
}
void jumpTag(int l,int r){
    for(int i = l;i<=r;i++){
        int val = query(1,1,n,i);
        if(val>tag[i])updatePoint(1,1,n,i,val);
        tag[i]=-1;
    }
}
int main(){
    freopen("ex_dream1.in","r",stdin);
    freopen("ex_dream.ans","w",stdout);
    n=read(),q=read();
    build(1,1,n);
    for(int i = 1,op,l,r;i<=q;i++){
        op=read(),l=read(),r=read();
        if(op==1){
            updateArea(1,1,n,l,r,1);
        }else if(op==2){
            updateArea(1,1,n,l,r,-1);
        }else if(op==3){
            makeTag(l,r);
        }else if(op==4){
            jumpTag(l,r);
        }else{
            cout<<query(1,1,n,l)<<endl;
        }
    }
    return 0;
}