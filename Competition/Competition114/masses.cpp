#include<iostream>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,t,up,down;
int hap[100005];
vector<int>ro[100005];
int main(){
    #ifndef LOCAL
    freopen("masses.in","r",stdin);
    freopen("masses.out","w",stdout);
    #else
    freopen("exmasses_2.in","r",stdin);
    freopen("exmasses_2.res","w",stdout);
    #endif
    scanf("%d %d %d %d/%d",&n,&m,&t,&up,&down);
    for(int i = 1;i<=n;i++)hap[i]=read();
    for(int i = 1,u,v;i<=m;i++){
        u=read()
    }
    return 0;
}