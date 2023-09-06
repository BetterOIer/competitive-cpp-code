#include<iostream>
#include<vector>
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
    long long valUnblock;
    long long valBlock;
    int numUnblock;
    int timBlock;
}tr[200005<<2];
struct BLOCK{
    int l;
    int r;
};
vector<BLOCK>v[400005];
void pushUp(int pos){
    if(tr[pos].timBlock>0)return ;
    tr[pos].valBlock=(tr[pos<<1].valBlock+tr[pos<<1|1].valBlock)%mod;
    tr[pos].valUnblock=(tr[pos<<1].valUnblock+tr[pos<<1|1].valUnblock)%mod;
    tr[pos].numUnblock=tr[pos<<1].numUnblock+tr[pos<<1|1].numUnblock;
}
void pushTag(int pos,int faPos){
    if(tr[pos].timBlock>0)return ;
    tr[pos].valUnblock = tr[pos].valUnblock*tr[faPos].tagMul%mod;
    tr[pos].valUnblock = (tr[pos].valUnblock+tr[faPos].tagAdd*tr[pos].numUnblock%mod)%mod;
    tr[pos].tagAdd = tr[pos].tagAdd*tr[faPos].tagMul%mod;
    tr[pos].tagAdd = (tr[pos].tagAdd+tr[faPos].tagAdd)%mod;
    tr[pos].tagMul = tr[pos].tagMul*tr[faPos].tagMul%mod;
}
void pushDown(int pos){
    if(tr[pos].tagAdd||tr[pos].tagMul!=1){
        pushTag(pos<<1,pos);
        pushTag(pos<<1|1,pos);
        tr[pos].tagAdd=0,tr[pos].tagMul=1;
    }
}
void build(int pos,int l,int r){
    if(l==r)return tr[pos].valUnblock=read(),tr[pos].numUnblock=1,void();//!?
    int mid = (l+r)>>1;
    build(pos<<1,l,mid),build(pos<<1|1,mid+1,r);
    pushUp(pos);
}
//Operate 1
void updateAdd(int pos,int l,int r,int x,int y,long long val){
    if(x<=l&&r<=y){
        (tr[pos].valUnblock+=tr[pos].numUnblock*val%mod)%=mod;
        (tr[pos].tagAdd+=val)%=mod;
        return ;
    }
    pushDown(pos);
    int mid = (l+r)>>1;
    if(x<=mid)updateAdd(pos<<1,l,mid,x,y,val);
    if(y>mid)updateAdd(pos<<1|1,mid+1,r,x,y,val);
    pushUp(pos);
}
//Operate 2
void updateMul(int pos,int l,int r,int x,int y,long long val){
    if(x<=l&&r<=y){
        (tr[pos].valUnblock*=val)%=mod;
        (tr[pos].tagAdd*=val)%=mod;
        (tr[pos].tagMul*=val)%=mod;
        return ;
    }
    pushDown(pos);
    int mid = (l+r)>>1;
    if(x<=mid)updateMul(pos<<1,l,mid,x,y,val);
    if(y>mid)updateMul(pos<<1|1,mid+1,r,x,y,val);
    pushUp(pos);
}
//Operate 4
long long query(int pos,int l,int r,int x,int y){
    if(x<=l&&r<=y) return (tr[pos].valUnblock+tr[pos].valBlock)%mod;
    pushDown(pos);
    int mid = (l+r)>>1;
    long long res=0;
    if(x<=mid)(res+=query(pos<<1,l,mid,x,y))%=mod;
    if(y>mid)(res+=query(pos<<1|1,mid+1,r,x,y))%=mod;
    return res%mod;
}

//Operate 3
void block(int pos,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        if(l!=r)pushDown(pos);
        if(tr[pos].timBlock==0){
            tr[pos].valBlock = (tr[pos].valBlock+tr[pos].valUnblock)%mod;
            tr[pos].valUnblock=0;
            tr[pos].numUnblock=0;
        }
        ++tr[pos].timBlock;
        return ;
    }
    pushDown(pos);
    int mid = (l+r)>>1;
    if(x<=mid)block(pos<<1,l,mid,x,y);
    if(y>mid)block(pos<<1|1,mid+1,r,x,y);
    pushUp(pos);
}

void deBlock(int pos,int l,int r,int x,int y){
    if(x<=l&&r<=y){
        --tr[pos].timBlock;
        if(tr[pos].timBlock)return ;
        if(l==r) swap(tr[pos].valBlock,tr[pos].valUnblock),tr[pos].numUnblock=1;
        else pushUp(pos);
        return ;
    }
    pushDown(pos);
    int mid = (l+r)>>1;
    if(x<=mid)deBlock(pos<<1,l,mid,x,y);
    if(y>mid)deBlock(pos<<1|1,mid+1,r,x,y);
    pushUp(pos);
}

#define DEBUG
#ifdef DEBUG
void out(){
    cout<<"num ";
    for(int i = 1;i<=n;i++){
        cout<<query(1,1,n,i,i)<<" \n"[i==n];
    }
}
#endif

int main(){
    #ifdef ONLINE
    freopen("stress.in","r",stdin);
    freopen("stress.out","w",stdout);
    #endif
    n=read(),m=read();
    build(1,1,n);
    #ifdef DEBUG
    out();
    #endif
    for(int i = 1,opt,l,r,x;i<=m;i++){
        opt=read(),l=read(),r=read();
        if(opt<4)x=read();
        if(opt==1) updateAdd(1,1,n,l,r,x);
        else if(opt==2) updateMul(1,1,n,l,r,x);
        else if(opt==3){
            block(1,1,n,l,r);
            v[i+x].push_back((BLOCK){l,r});
        }
        else printf("%lld\n",query(1,1,n,l,r));
        for(BLOCK j:v[i]) deBlock(1,1,n,j.l,j.r);
        #ifdef DEBUG
        out();
        #endif
    }
    return 0;
}