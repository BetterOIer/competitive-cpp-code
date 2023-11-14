#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}

int main(){
    #ifndef LOCAL
    freopen("masses.in","r",stdin);
    freopen("masses.out","w",stdout);
    #else
    freopen("exmasses_2.in","r",stdin);
    freopen("exmasses_2.res","w",stdout);
    #endif
    
    return 0;
}