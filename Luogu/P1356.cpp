#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
struct node{
    int cvT,len;
    int sum;
    bool cvL,cvR;
}tr[10005<<3];
struct LINE{
    int l,r,y;
    int tag;
}line[10005];
int X[10005];
int n;
bool operator < (const LINE a,const LINE b){
    if(a.y==b.y)return a.tag>b.tag;
    return a.y<b.y;
}
void pushUp(int pos,int l,int r){
    if(tr[pos].cvT){
        tr[pos].len=X[r+1]-X[l];
        tr[pos].sum=2;
        tr[pos].cvL=tr[pos].cvR=true;
    }else{
        tr[pos].len=tr[pos<<1].len+tr[pos<<1|1].len;
        tr[pos].sum=tr[pos<<1].sum+tr[pos<<1|1].sum;
        tr[pos].cvL=tr[pos<<1].cvL;
        tr[pos].cvR=tr[pos<<1|1].cvR;
        if(tr[pos<<1].cvR&&tr[pos<<1|1].cvL){
            tr[pos].sum-=2;
        }
    }
}
void update(int pos,int l,int r,int x,int y,int tag){
    if(x<=l&&r<=y){
        tr[pos].cvT+=tag;
        return pushUp(pos,l,r);
    }
    int mid = (l+r)>>1;
    if(mid>=x)update(pos<<1,l,mid,x,y,tag);
    if(mid<y)update(pos<<1|1,mid+1,r,x,y,tag);
    return pushUp(pos,l,r);
}
void build(int pos,int l,int r){
    if(l==r)return;
    int mid = (l+r)>>1;
    build(pos<<1,l,mid);build(pos<<1|1,mid+1,r);
}

int main(){
    n=read();
    for(int i = 1,xLD,yLD,xRU,yRU;i<=n;i++){
        xLD=read(),yLD=read(),xRU=read(),yRU=read();
        line[i]={xLD,xRU,yLD,1},line[n+i]={xLD,xRU,yRU,-1};
        X[i]=xLD,X[n+i]=xRU;
    }
    n<<=1;
    sort(line+1,line+n+1);
    sort(X+1,X+n+1);
    int len = unique(X+1,X+n+1)-X-1;
    build(1,1,len-1);

    int res = 0,last=0;
    for(int i = 1;i<n;i++){
        int l = lower_bound(X+1,X+len+1,line[i].l)-X;
        int r = lower_bound(X+1,X+len+1,line[i].r)-X;
        update(1,1,len-1,l,r-1,line[i].tag);
        res+=abs(tr[1].len-last);
        last=tr[1].len;
        res+=tr[1].sum*(line[i+1].y-line[i].y);
    }
    res+=line[n].r-line[n].l;
    cout<<res<<endl;
    return 0;
}