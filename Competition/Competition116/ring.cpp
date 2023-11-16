#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m;
int a[2000005];
struct EDGE{
    int l;
    int r;
};
int main(){
    #ifndef LOCAL
    freopen("ring.in","r",stdin);
    freopen("ring.out","w",stdout);
    #else
    freopen("ex_ring4.in","r",stdin);
    freopen("ex_ring4.out","w",stdout);
    #endif
    n=read(),m=read();
     for(int i = 1,l,r;i<=m;i++){
        l=read(),r=read();
        if(l>r)r+=n;

     }
    return 0;
}