#include<iostream>
#include<cstring>
#include<assert.h>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
int a[200],nxd[200];
int b[200],c[200],scr=0;
void cdq(long long l,long long r){
    if(l==r) return ;
    long long mid=(l+r)>>1;
    cdq(l,mid),cdq(mid+1,r);
    long long i,j,num=l-1;
    for(i=mid+1,j=l;i<=r;i++){
        while(b[j]<b[i]&&j<=mid) c[++num]=b[j++];
        scr+=mid-j+1;
        c[++num]=b[i];
    }
    while(j<=mid) c[++num]=b[j++];
    for(long long i=l;i<=r;i++) b[i]=c[i];
}
struct node{
    int val=0;
    int tag=0;
}tr[200<<2];
void pushDown(int pos,int l,int r){
    int mid =(l+r)>>1;
    if(!tr[pos].tag)return ;
    tr[pos<<1].val+=tr[pos].tag*(mid-l+1);
    tr[pos<<1].tag+=tr[pos].tag;
    tr[pos<<1|1].val+=tr[pos].tag*(r-mid);
    tr[pos<<1|1].tag+=tr[pos].tag;
    return tr[pos].tag=0,void();
}
void pushUp(int pos){
    tr[pos].val=tr[pos<<1].val+tr[pos<<1|1].val;
}
void update(int pos,int l,int r,int x,int y,int val){
    if(x<=l&&r<=y) return tr[pos].val+=(r-l+1)*val,tr[pos].tag+=val,void();
    pushDown(pos,l,r);int mid = (l+r)>>1;
    if(mid>=x)update(pos<<1,l,mid,x,y,val);
    if(mid<y)update(pos<<1|1,mid+1,r,x,y,val);
    pushUp(pos);
}
int query(int pos,int l,int r,int x){
    if(l==r)return tr[pos].val;
    pushDown(pos,l,r);
    int mid = (l+r)>>1;
    if(mid>=x)return query(pos<<1,l,mid,x);
    else return query(pos<<1|1,mid+1,r,x);
}
void out(){
    for(int i = 1;i<=n;i++){
        cout<<query(1,1,n,i)<<" \n"[i==n];
    }
}
int main(){
    #ifndef LOCAL
    freopen("essenceoftwilight.in","r",stdin);
    freopen("essenceoftwilight.out","w",stdout);
    #else
    freopen("essenceoftwilight/essenceoftwilight1.in","r",stdin);
    freopen("essenceoftwilight/essenceoftwilight1.out","w",stdout);
    #endif
    //cout<<500000*__lg(50000)*2;
    int t=read(),o=read();
    while(t--){
        memset(tr,0,sizeof tr);
        memset(nxd,0,sizeof nxd);
        n=read(),scr=0;
        for(int i = 1;i<=n;i++){
            a[i]=read();
        }
        int tot=0;
        for(int i = 1;i<=n;i++){
            //out();
            nxd[i]=a[i]-1-query(1,1,n,a[i]);
            tot+=nxd[i];
            update(1,1,n,a[i],n,1);
        }
        int maxx=0,minx=n,minp,maxp;
        for(int i = 1;i<=n;i++){
            if(nxd[i]>maxx)maxx=nxd[i],maxp=i;
            if(nxd[i]<=minx)minx=nxd[i],minp=i;
        }swap(a[maxp],a[minp]);
        for(int i = 1;i<=n;i++){
            b[i]=a[i];
        }
        cdq(1,n);
        cout<<min(tot,scr)<<endl;
    }
    return 0;
}