#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}
long long a[15],b[15],c[15],plaDead[15],n;
vector<long long>ro[15];
priority_queue<pair<long long, long long> >Q;
bool operator < (pair<long long, long long> a, pair<long long, long long > b){
    return a.second<b.second;
}
bool vis[15];
long long cal1(long long las,long long b,long long c,__int128 a){
    __int128 h2=b+las*c;
    if(h2>=a)return n;
    long long l=0,r=n;
    while(l<r){
        long long mid=((l+r+1)>>1);
        if((__int128)(h2+b+c*mid)*(las-mid+1)>=a*2)l=mid;//A.P
        else r=mid-1;
    }
    return l;
}
long long cal2(long long las,long long b,long long c,__int128 a){
    long long o=(b-1)/(-c);
    long long l=0,r=n;
    while(l<r){
        long long mid=((l+r+1)>>1);
        __int128 S;
        if(mid>o)S=las-mid+1;
        else if(las>o)S=(__int128)((__int128)b*2+c*(o+mid))*(o-mid+1)/2+(las-o);
        else S=(__int128)((__int128)b*2+c*(las+mid))*(las-mid+1)/2;
        if(S>=a)l=mid;
        else r=mid-1;
    }
    return l;
}
long long calDead(long long pos,long long deadLine){
    if(c[pos]>=0){
        return cal1(deadLine,b[pos],c[pos],a[pos]);
    }else{
        return cal2(deadLine,b[pos],c[pos],a[pos]);
    }
}
long long dfs(long long pos,long long fa,long long deadLine){
    long long myDead = calDead(pos,deadLine);
    for(long long i:ro[pos]){
        if(i==fa)continue;
        myDead = min(myDead,dfs(i,pos,deadLine)-1);
    }
    return plaDead[pos]=myDead;
}
bool vaild(long long deadLine){
    for(long long i = 1;i<=n;i++)vis[i]=0;
    dfs(1,0,deadLine);long long cnt = 1;
    Q.push(make_pair(1,1));
    while(Q.size()){
        pair<long long,long long> now = Q.top();Q.pop();
        if(vis[now.first])continue;
        vis[now.first]=true;
        if(cnt>now.second)return false;
        for(long long i:ro[now.first]){
            Q.push(make_pair(i,plaDead[i]));
        }
        cnt++;
    }
    return true;
}
int main(){
    freopen("tree1.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read();
    for(long long i  = 1;i<=n;i++){
        a[i]=read(),b[i]=read(),c[i]=read();
    }
    for(long long i  =1,u,v;i<n;i++){
        u=read(),v=read();
        ro[u].push_back(v);
        ro[v].push_back(u);
    }
    long long l = n,r = 1e9;
    while(l<r){
        long long mid = (l+r)>>1;
        if(vaild(mid)){
            r = mid;
        }else l = mid+1;
        /* cout<<l<<" "<<r<<endl; */
    }
    cout<<l+1;
    fclose(stdin);
    fclose(stdout);
}