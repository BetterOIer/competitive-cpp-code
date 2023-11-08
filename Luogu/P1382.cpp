/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
int Y[200005],xLen,yLen;
struct LINE{
    int x;
    int y;
    int tag;
}line[200005];
struct node{
    int cvT,len;
    int sum;
    bool cvL,cvR;
}tr[100005<<3];
struct ANS{
    int x,y;
};
vector<ANS>ans;
bool operator < (const LINE a,const LINE b){
    if(a.x==b.x)return a.tag>b.tag;
    return a.x<b.x;
}
void pushUp(int pos,int l,int r){
    if(tr[pos].cvT){
        tr[pos].len=Y[r+1]-Y[l];
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
    for(int i = 1,x1,x2,y2;i<=n;i++){
        y2=read(),x1=read(),x2=read();
        line[i].x=x1,line[i].y=y2,line[i].tag=1,line[n+i].x=x2,line[n+i].y=y2,line[n+i].tag=-1;
        Y[i]=0,Y[i+n]=y2;
    }
    sort(Y+1,Y+2*n+1);
    sort(line+1,line+2*n+1);
    yLen=unique(Y+1,Y+2*n+1)-Y-1;
    n<<=1;
    int last=0;
    for(int i= 1;i<=n;i++){
        int yl = lower_bound(Y+1,Y+yLen+1,0)-Y;
        int yr = lower_bound(Y+1,Y+yLen+1,line[i].y)-Y;
        update(1,1,yLen-1,yl,yr-1,line[i].tag);
        if(tr[1].len!=last){
            ans.push_back((ANS){line[i].x,last});
            ans.push_back((ANS){line[i].x,tr[1].len});
        }
        last=tr[1].len;
    }
    cout<<int(ans.size())<<endl;
    for(ANS i:ans){
        cout<<i.x<<" "<<i.y<<endl;
    }
    return 0;
}