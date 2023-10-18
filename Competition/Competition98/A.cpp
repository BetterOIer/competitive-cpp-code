#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,h,w,K;
bool b[2005][2005];
int a[2][2005][2005],ans;
inline int get(bool o,int x1,int y1,int x2,int y2){
    if(x1>x2||y1>y2)return 0;
    return a[o][x2][y2]-a[o][x2][y1-1]-a[o][x1-1][y2]+a[o][x1-1][y1-1];
}
int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>h>>w>>K;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        char c;cin>>c;
        b[i][j]=(c=='1');
        a[0][i][j]=a[0][i-1][j]+a[0][i][j-1]-a[0][i-1][j-1]+(b[i][j]!=b[i][j-1]);
        a[1][i][j]=a[1][i-1][j]+a[1][i][j-1]-a[1][i-1][j-1]+(b[i][j]!=b[i-1][j]);
    }
    for(int i=h;i<=n;i++)
        for(int j=w;j<=m;j++)
            ans+=((get(0,i-h+1,j-w+2,i,j)+get(1,i-h+2,j-w+1,i,j))>=K);
    cout<<ans;
    return 0;
}