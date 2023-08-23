#include<bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;

int n,m;
int a[5005][5005];
int dist[5005];
bool be[5005];

int prim(){
    
    memset(dist,0x3f,sizeof(dist));
    int res=0;
    for(int i=0;i<n;i++){
        int t=-1;
        for(int j=1;j<=n;j++){
            if(!be[j] && (t==-1 || dist[t]>dist[j])) t=j;
        }
        be[t]=1;
        if(i && dist[t]==INF) return INF;
        if(i) res+=dist[t];
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],a[t][j]);
        }
        
    }
    return res;

}
int main(){
    cin>>n>>m;
    memset(a,0x3f,sizeof(a));
    while(m--){
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y]=a[y][x]=min(a[x][y],z);
    }
    
    int ans=prim();
    
    if(ans==INF) cout<<"orz";
    else cout<<ans;
    return 0;
}