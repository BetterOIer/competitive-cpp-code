#include<iostream>
#define release
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,ans=0;
long long a[200005];
long long t[205];
int main(){
    #ifdef release
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    #endif

    n=read();
    for(long long i = 1;i<=n;i++){
        a[i]=read();
    }

    //Version1
    /* 
    for(long long i = 1;i<=n;i++){
        for(long long j = i+1;j<=n;j++){
            if((a[i]-a[j])%200==0)ans++;
        }
    }
    cout<<ans; */

    //Version2
    for(int i = 1;i<=n;i++){
        t[(a[i]%200+200)%200]++;
    }
    for(int i = 0;i<=199;i++){
        ans+=(t[i]*(t[i]-1)/2);
    }
    cout<<ans;
    return 0;
}