#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}
int a[100005],b[100005],c[100005],plaDead[100005];
vector<int>ro[100005];
int calDead(int pos,int deadLine){
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
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n=read();
    for(int i  = 1;i<=n;i++){
        a[i]=read(),b[i]=read(),c[i]=read();
    }
    for(int i  =1,u,v;i<n;i++){
        u=read(),v=read();
        ro[u].push_back(v);
        ro[v].push_back(u);
    }
    int l = 1,r = 1e9;
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