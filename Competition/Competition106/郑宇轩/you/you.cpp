#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
uint64_t seed;
uint64_t next(){ //xorshift64
    seed^=seed<<13;
    seed^=seed>>7;
    seed^=seed<<17;
    return seed;
}
long long n,m,q;
long long c[5005],r[5005],refc[5005],refr[5005];
long long a[5005][5005];
long long basec[5005]={1},baser[5005]={1};
long long ans=0;
string s;
int main(){
    #ifndef LOCAL
    freopen("you.in","r",stdin);
    freopen("you.out","w",stdout);
    #else
    freopen("A/ex_A2.in","r",stdin);
    freopen("A/ex_A2.out","w",stdout);
    #endif
    cin>>n>>m>>q>>seed>>s;
    for(long long i = 0;i<n;i++)for(long long j = 0;j<m;j++)a[i][j] = i*m+j;
    for(long long i = 0;i<n;i++)refr[i]=r[i]=i;
    for(long long i = 0;i<m;i++)refc[i]=c[i]=i;
    for(long long i = 1;i<=n;i++)baser[i]=1LL*baser[i-1]*17%mod;
    for(long long i = 1;i<=m;i++)basec[i]=1LL*basec[i-1]*19%mod;
    for(long long i = 0;i<q;i++){
        if(s[i]=='r'){
            long long r1 = next()%n,r2 = next()%n;
            swap(r[refr[r1]],r[refr[r2]]);
            swap(refr[r1],refr[r2]);
        }else if(s[i]=='c'){
            long long c1 = next()%m,c2 = next()%m;
            swap(c[refc[c1]],c[refc[c2]]);
            swap(refc[c1],refc[c2]);
        }else{
            long long r1 = next()%n,c1=next()%m,r2=next()%n,c2=next()%m;
            swap(a[refr[r1]][refc[c1]],a[refr[r2]][refc[c2]]);
        }
    }
    for(long long i = 0;i<n;i++)for(long long j = 0;j<m;j++){
        ans = (ans+a[i][j]*baser[r[i]]%mod*basec[c[j]]%mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}