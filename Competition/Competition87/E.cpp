#include<iostream>
using namespace std;
const long long mod = 1e9+7;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,m;
struct node{
    long long tagAdd=0;
    long long tagMul=1;
    long long val;
}tr[200005<<2];
void pushUp(int pos){
    tr[pos].val=(tr[pos<<1].val+tr[pos<<1|1].val)%mod;
}
void pushDown(int pos,int l,int r){
    if(tr[pos].tagAdd||tr[pos].tagMul!=1){
        int mid = (l+r)>>1;
        tr[pos<<1].tagMul=(tr[pos<<1].tagMul*tr[pos].tagMul)%mod;
		tr[pos<<1|1].tagMul=(tr[pos<<1|1].tagMul*tr[pos].tagMul)%mod;
		tr[pos<<1].tagAdd=(tr[pos<<1].tagAdd*tr[pos].tagMul)%mod;
		tr[pos<<1|1].tagAdd=(tr[pos<<1|1].tagAdd*tr[pos].tagMul)%mod;
		tr[pos<<1].val=(tr[pos<<1].val*tr[pos].tagMul)%mod;
		tr[pos<<1|1].val=(tr[pos<<1|1].val*tr[pos].tagMul)%mod;
		tr[pos].tagMul=1;
		tr[pos<<1].val=(tr[pos<<1].val+tr[pos].tagAdd*(mid-l+1))%mod;
		tr[pos<<1|1].val=(tr[pos<<1|1].val+tr[pos].tagAdd*(r-mid))%mod;
		tr[pos<<1].tagAdd=(tr[pos].tagAdd+tr[pos<<1].tagAdd)%mod;
		tr[pos<<1|1].tagAdd=(tr[pos].tagAdd+tr[pos<<1|1].tagAdd)%mod;
		tr[pos].tagAdd=0;
    }
}
void build(int pos,int l,int r){
    if(l==r)return tr[pos].val=read(),void();
    int mid = (l+r)>>1;
    build(pos<<1,l,mid),build(pos<<1|1,mid+1,r);
    pushUp(pos);
}
void updateAdd(int pos,int l,int r,int x,int y,long long val){
    if(x<=l&&r<=y){
        (tr[pos].val+=(r-l+1)*val)%=mod;
        (tr[pos].tagAdd+=val)%=mod;
        return ;
    }
    pushDown(pos,l,r);
    int mid = (l+r)>>1;
    if(x<=mid)updateAdd(pos<<1,l,mid,x,y,val);
    if(y>mid)updateAdd(pos<<1|1,mid+1,r,x,y,val);
    pushUp(pos);
}
void updateMul(int pos,int l,int r,int x,int y,long long val){
    if(x<=l&&r<=y){
        (tr[pos].val*=val)%=mod;
        (tr[pos].tagAdd*=val)%=mod;
        (tr[pos].tagMul*=val)%=mod;
        return ;
    }
    pushDown(pos,l,r);
    int mid = (l+r)>>1;
    if(x<=mid)updateMul(pos<<1,l,mid,x,y,val);
    if(y>mid)updateMul(pos<<1|1,mid+1,r,x,y,val);
    pushUp(pos);
}
long long query(int pos,int l,int r,int x,int y){
    if(x<=l&&r<=y) return tr[pos].val%mod;
    pushDown(pos,l,r);
    int mid = (l+r)>>1;
    long long res=0;
    if(x<=mid)(res+=query(pos<<1,l,mid,x,y))%=mod;
    if(y>mid)(res+=query(pos<<1|1,mid+1,r,x,y))%=mod;
    return res%mod;
}


long long valid[200005];
void setInvalid(int l,int r,long long x){
    for(int i = l;i<=r;i++){
        valid[i]=max(valid[i],x);
    }
}
void doAdd(int id,int l,int r,long long x){
    bool about=true;
    int lLim,rLim;
    for(int i = l;i<=r;i++){
        if(valid[i]<id){
            if(about){
                lLim=i,rLim=i;
                about=false;
            }
            else rLim++;
        }
        else{
            if(!about){
                about=true;
                updateAdd(1,1,n,lLim,rLim,x);
            }
        }
    }
    if(!about) updateAdd(1,1,n,lLim,rLim,x);
}
void doMul(int id,int l,int r,long long x){
    bool about=true;
    int lLim,rLim;
    for(int i = l;i<=r;i++){
        if(valid[i]<id){
            if(about){
                lLim=i,rLim=i;
                about=false;
            }
            else rLim++;
        }
        else{
            if(!about){
                about=true;
                updateMul(1,1,n,lLim,rLim,x);
            }
        }
    }
    if(!about) updateMul(1,1,n,lLim,rLim,x);
}

#ifdef DEBUG
void out(){
    cout<<"num ";
    for(int i = 1;i<=n;i++){
        cout<<query(1,1,n,i,i)<<" \n"[i==n];
    }
    cout<<"valid ";
    for(int i = 1;i<=n;i++){
        cout<<valid[i]<<" \n"[i==n];
    }
}
#endif

int main(){
    freopen("stress.in","r",stdin);
    freopen("stress.out","w",stdout);
    n=read(),m=read();
    build(1,1,n);
    #ifdef DEBUG
    out();
    #endif
    for(int i = 1,opt,l,r,x;i<=m;i++){
        opt=read(),l=read(),r=read();
        if(opt<4)x=read();
        /* if(opt==1) doAdd(i,l,r,x);
        else if(opt==2) doMul(i,l,r,x); */
        if(opt==1) updateAdd(1,1,n,l,r,x);
        else if(opt==2) updateMul(1,1,n,l,r,x);
        else if(opt==3) setInvalid(l,r,x+i);
        else printf("%lld\n",query(1,1,n,l,r));
        #ifdef DEBUG
        out();
        #endif
    }
    return 0;
}