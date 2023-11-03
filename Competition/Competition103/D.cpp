#include<bits/stdc++.h>
using namespace std;
const int N=1e5,AD=50,INF=1e9;
int T,li[N+10],ri[N+10],t,ap[15],td[N+AD+15],TIM[N+AD+15],tim;
int si,ti,ta;
vector<int>d[N+10],rd[N+10],e[N+AD+15],re[N+AD+15];
queue<int>q;
void bfs(vector<int>&v,int x,int l,int r){
    while(!q.empty())q.pop();
    v.resize(r-l+1);
    q.push(x),td[x]=0,TIM[x]=++tim;
    int tt=1;
    while(!q.empty()&&tt<r-l+1){
        t=q.front(),q.pop();
        for(int j:e[t])if(TIM[j]!=tim){
            if(j>r+AD||j<l-AD)continue;
            TIM[j]=tim;
            td[j]=td[t]+1;
            q.push(j);
            if(l<=j&&j<=r)++tt;
        }
    }
    for(int i=l;i<=r;++i)v[i-l]=(TIM[i]==tim?td[i]:INF);
}
void rbfs(vector<int>&v,int x,int l,int r){
    while(!q.empty())q.pop();
    v.resize(r-l+1);
    q.push(x),td[x]=0,TIM[x]=++tim;
    int tt=1;
    while(!q.empty()&&tt<r-l+1){
        t=q.front(),q.pop();
        for(int j:re[t])if(TIM[j]!=tim){
            if(j>r+AD||j<l-AD)continue;
            TIM[j]=tim;
            td[j]=td[t]+1;
            q.push(j);
            if(l<=j&&j<=r)++tt;
        }
    }
    for(int i=l;i<=r;++i)v[i-l]=(TIM[i]==tim?td[i]:INF);
}
void Init(int l,int r){
    if(l>r)return;
    int mid=(l+r>>1);
    for(int i=max(0,mid-4);i<=mid+4;++i)li[i]=min(li[i],l),ri[i]=max(ri[i],r);
    Init(l,mid-1),Init(mid+1,r);
}
int Query(int l,int r,int x,int y){
    int mid=(l+r>>1);
    if((x<=mid&&mid<=y)||(y<=mid&&mid<=x)){
        int ret=1e9;
        for(int i=max(0,mid-4);i<=mid+4;++i)ret=min(ret,rd[i][x-li[i]]+d[i][y-li[i]]);
        return ret;
    }
    return x<mid?Query(l,mid-1,x,y):Query(mid+1,r,x,y);
}
int main(){
    cin.sync_with_stdio(0),cin.tie(0);
    for(int i=1;i<=N+AD;++i){
        for(int tmp=i,g;tmp;tmp/=10)if(ap[g=tmp%10]!=i){
            ap[g]=i;
            e[i].push_back(i-g);
            e[i].push_back(i+g);
            re[i-g].push_back(i);
            re[i+g].push_back(i);
        }
    }
    for(int i=0;i<=N+4;++i)li[i]=ri[i]=i;
    Init(0,N);
    for(int i=0;i<=N+4;++i)bfs(d[i],i,li[i],ri[i]),rbfs(rd[i],i,li[i],ri[i]);
    cin>>T;
    while(T--){
        cin>>si>>ti;
        si^=ta+1,ti^=ta+1;
        if(!si){
            cout<<(ta=-1)<<"\n";
            continue;
        }
        ta=Query(0,N,si,ti);
        cout<<(ta<INF?ta:(ta=-1))<<"\n";
    }
    return 0;
}