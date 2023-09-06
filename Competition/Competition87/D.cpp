#include<iostream>
#include<vector>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,m,k;
long long rowDrop[100005];
struct CAVE{
    int xFrom;
    int yFrom;
    int xTo;
    int yTo;
    long long gainVal;
};
CAVE cave[100005];
vector<int>rowCaveId[100005];
long long ans=-9223372036854775807ll - 1;
bool canEsc=false;
void dfs(int x,int y,long long val){
    if(x==n&&y==m){
        canEsc=true;
        ans=max(ans,val);
        return;
    }
    if(x==n){
        dfs(n,m,val-1LL*abs(y-m)*rowDrop[n]);
    }
    for(auto id:rowCaveId[x]){
        dfs(cave[id].xTo,cave[id].yTo,val+1LL*cave[id].gainVal-1LL*abs(y-cave[id].yFrom)*rowDrop[x]);
    }
}
int main(){
    freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
    int t=read();
    while(t--){
        n=read(),m=read(),k=read();
        for(int i = 1;i<=n;i++){
            rowDrop[i]=read();
            rowCaveId[i].clear();
        }
        for(int i = 1;i<=k;i++){
            cave[i].xFrom=read(),
            cave[i].yFrom=read(),
            cave[i].xTo=read(),
            cave[i].yTo=read(),
            cave[i].gainVal=read();
            rowCaveId[cave[i].xFrom].push_back(i);
        }
        dfs(1,1,0);
        if(canEsc==true)printf("%lld\n",-ans);
        else printf("NO ESCAPE\n");
        ans=-9223372036854775807ll - 1,canEsc=false;
    }
    return 0;
}