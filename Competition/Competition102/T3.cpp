#include<iostream>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int main(){
    #ifndef LOCAL
    freopen("qiandao.in","r",stdin);
    freopen("qiandao.out","w",stdout);
    #endif
    return 0;
}