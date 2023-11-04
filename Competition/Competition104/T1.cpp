#include<iostream>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,ans=0;
int main(){
    #ifndef LOCAL
    freopen("signin.in","r",stdin);
    freopen("signin.out","w",stdout);
    #endif
    n=read();
    while(n){
        ans+=n%60;n/=60;
    }
    cout<<ans;
    return 0;
}