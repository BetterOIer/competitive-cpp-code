#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}
int a[100005],b[100005],c[100005],plaDead[100005],n;
vector<int>ro[100005];
priority_queue<pair<int, int> >Q;
bool operator < (pair<long long, long long> a, pair<long long, long long > b){
    return a.second<b.second;
}
/* int calDead(int pos,int deadLine){
    int hei = a[pos];
    int l = 1,r=deadLine;
    if(c[pos]>=0||deadLine<-b[pos]/c[pos]){
        while(l<=r){
            int mid = (l+r)>>1;
            if((mid+deadLine-1)*(deadLine-mid)/2*c[pos]+(deadLine-mid)*b[pos]>hei){
                r = mid;
            }else l = mid+1;
        }
    }else{
        int uptime = -b[pos]/c[pos];
        while(l<=r){
            int mid = (l+r)>>1;
            if((mid+deadLine-1)*(deadLine-mid)/2*c[pos]+(deadLine-mid)*b[pos]>hei){
                r = mid;
            }else l = mid+1;
        }
    }
} */
int cal1(int las,long long b,long long c,__int128 a){
    __int128 h2=b+las*c;
    if(h2>=a)return n;
    int l=0,r=n;
    while(l<r){
        int mid=(l+r+1>>1);
        if((__int128)(h2+b+c*mid)*(las-mid+1)>=a*2)l=mid;//A.P
        else r=mid-1;
    }
    return l;
}
int cal2(int las,long long b,long long c,__int128 a){
    long long o=(b-1)/(-c);
    int l=0,r=n;
    while(l<r){
        int mid=(l+r+1>>1);
        __int128 S;
        if(mid>o)S=las-mid+1;
        else if(las>o)S=(__int128)((__int128)b*2+c*(o+mid))*(o-mid+1)/2+(las-o);
        else S=(__int128)((__int128)b*2+c*(las+mid))*(las-mid+1)/2;
        if(S>=a)l=mid;
        else r=mid-1;
    }
    return l;
}
int calDead(int pos,int deadLine){
    if(c[pos]>=0){
        return cal1(deadLine,b[pos],c[pos],a[pos]);
    }else{
        return cal2(deadLine,b[pos],c[pos],a[pos]);
    }
}
int dfs(int pos,int fa,int deadLine){
    int myDead = calDead(pos,deadLine);
    for(int i:ro[pos]){
        if(i==fa)continue;
        myDead = min(myDead,dfs(i,pos,deadLine)-1);
    }
    return plaDead[pos]=myDead;
}
bool vaild(int deadLine){
    dfs(1,0,deadLine);
    Q.push(make_pair(1,1));
    while(Q.size()){
        
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read();
    for(int i  = 1;i<=n;i++){
        a[i]=read(),b[i]=read(),c[i]=read();
    }
    for(int i  =1,u,v;i<n;i++){
        u=read(),v=read();
        ro[u].push_back(v);
        ro[v].push_back(u);
    }
    int l = n,r = 1e9;
    while(l<=r){
        int mid = (l+r)>>1;
        if(vaild(mid)){
            r = mid;
        }else l = mid+1;
    }
    cout<<l;
    fclose(stdin);
    fclose(stdout);
}