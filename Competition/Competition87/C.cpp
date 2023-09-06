#include<iostream>
using namespace std;
const int mod = 998244353;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
long long perm[30]={1, 1, 2, 6, 24, 60, 150, 399, 1145, 3132, 8420, 22716, 62128, 169536, 460885, 1251777, 3406238, 9272354, 25229036, 68622196, 186682470, 507925571, 1381929921, 3759616968, 10228269080, 27827267544, 75707898304, 205971928848, 560368255081, 1524544463441};
long long qpow(long long x,long long p){
    long long res=1;
    while(p){
        if(p&1)res=res*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return (res+mod)%mod;
}
long long inv(int x){
    return (long long)qpow(x,mod-2);
}
int main(){
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    int t=read();
    while(t--){
        int n=read();
        cout<<perm[n]%mod;
    }
    return 0;
}

//(x-1)*(x+1)/(-x^8-5*x^7-2*x^6+8*x^5+12*x^4+2*x^3+2*x^2+x+1)