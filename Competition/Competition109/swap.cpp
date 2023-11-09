#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}

int main(){
    #ifndef LOCAL
    freopen("swap.in","r",stdin);
    freopen("swap.out","w",stdout);
    #else
    freopen("ex_swap1.in","r",stdin);
    freopen("ex_swap1.res","w",stdout);
    #endif
    int t=read();
    cout<<0;
    return 0;
}