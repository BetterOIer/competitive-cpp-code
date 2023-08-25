/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<stack>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m;
bool sta[50005];
struct node{
    int val;
}tr[50005<<2];
stack<int>s;
void pushup(int pos){
    tr[pos].val = tr[pos<<1].val+tr[pos<<1|1].val;
}
void build(int pos,int l,int r){
    if(l==r){
        tr[pos].val=1;
        sta[l]=1;
        return;
    }
    int mid = (l+r)>>1;
    build(pos<<1,l,mid);build(pos<<1|1,mid+1,r);
    pushup(pos);
}
void update(int pos,int l,int r,int x,int val){
    if(l==r){
        tr[pos].val=val;
        sta[l]=(bool)(val);
        return;
    }
    int mid = (l+r)>>1;
    if(mid>=x)update(pos<<1,l,mid,x,val);
    else update(pos<<1|1,mid+1,r,x,val);
    pushup(pos);
}
int query(int pos,int l,int r,int x,int y){
    if(x<=l&&r<=y)return tr[pos].val;
    int mid = (l+r)>>1,ans=0;
    if(mid>=x)ans+=query(pos<<1,l,mid,x,y);
    if(mid<y)ans+=query(pos<<1|1,mid+1,r,x,y);
    return ans;
}
int queryL(int l,int r){
    if(l==r)return l;
    int mid = (l+r)>>1;
    if(query(1,1,n,mid+1,r)<r-mid) return queryL(mid+1,r);
    else return queryL(l,mid);
}
int queryR(int l,int r){
    if(l==r)return l;
    int mid = (l+r)>>1;
    if(query(1,1,n,l,mid)<mid-l+1) return queryR(l,mid);
    else return queryR(mid+1,r);
}
int main(){
    cin>>n>>m;
    build(1,1,n);
    for(int i = 1,x;i<=m;i++){
        char opt;
        cin>>opt;
        if(opt=='D'){
            cin>>x;
            update(1,1,n,x,0);
            s.push(x);
        }else if (opt=='R'){
            x = s.top();s.pop();
            update(1,1,n,x,1);
        }else{
            cin>>x;
            if(!sta[x])cout<<0<<endl;
            else{
                int 
                l=queryL(0,x-1),
                r=queryR(x+1,n+1);
                cout<<r-l-1<<endl;;
            }
        }
    }
    return 0;
}