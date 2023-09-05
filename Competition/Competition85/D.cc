#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N = 3005;
const int mod = 1e9 + 7;
inline int read(){
    int x = 0,f = 1;char c = getchar();
    for(;!isdigit(c);c = getchar())if(c == '-')f = -1;
    for(;isdigit(c);c = getchar())x = ( x << 1 ) + ( x << 3 ) + c - '0';
    return x * f;
}
int h,w,n;
int fac[N*N];
int f[N* 3];
struct node{
    int x,y;
    inline bool operator <  (const node &a)const{
        if(x == a.x)return  y < a.y;
        return x < a.x;
    }
}a[N];
inline int qpow(int a,int b){
    int ret = 1;
    while( b ){
        if( b & 1 )ret = 1ll*ret * a % mod;
        b >>= 1;a = 1ll*a * a % mod;
    }
    return (ret+mod)%mod;
}
int getInv(int x){
    return qpow(x,mod-2);
}
inline int C(int x,int y){return 1ll*fac[x] * getInv(fac[y]) % mod * getInv(fac[x - y]) % mod;}
inline void init(){
    fac[0] = 1;
    for(int i = 1;i <= n*n+15;i ++)fac[i] = 1ll*fac[i - 1] * i % mod;
    for(int i = 1;i <= n;i ++)f[i] = 1ll*C(a[i].x + a[i].y - 2,a[i].x - 1)%mod;
    //for(int i=1;i<=n;i++)cout << f[i] << ' ';
}
signed main(){
    h = read();
    w = read();
    n = read();
    for(int i = 1;i <= n;i ++){
        a[i].x = read();
        a[i].y = read();
    }
    a[++n].x = h;
    a[n].y = w;
    sort(a + 1,a + n + 1);
    init();
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j < i;j ++){
            if(a[j].x <=  a[i].x && a[j].y <= a[i].y){
                f[i] -= 1ll*f[j] * C(a[i].x - a[j].x + a[i].y - a[j].y,a[i].x - a[j].x);
                f[i] = 1ll*( f[i] + mod ) % mod;
            } 
        }
    }
    printf("%lld\n",(f[n]+mod)%mod);
    return 0;
}