#include<iostream>
using namespace std;
const long long mod = 998244353;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,q;
long long a[500005],b[500005],c[500005];
long long base[500005]={1},scr=0;
long long ans=0;
string query;
void cdq(long long l,long long r){
    if(l==r) return ;
    long long mid=(l+r)>>1;
    cdq(l,mid),cdq(mid+1,r);
    long long i,j,num=l-1;
    for(i=mid+1,j=l;i<=r;i++){
        while(b[j]<b[i]&&j<=mid) c[++num]=b[j++];
        scr+=mid-j+1;
        c[++num]=b[i];
    }
    while(j<=mid) c[++num]=b[j++];
    for(long long i=l;i<=r;i++) b[i]=c[i];
}
int main(){
    #ifndef LOCAL
    freopen("river.in","r",stdin);
    freopen("river.out","w",stdout);
    #endif
    n=read(),q=read();
    for(long long i = 1;i<=q;i++){
        base[i]=1ll*base[i-1]*233%mod;
    }
    for(long long i = 1;i<=n;i++)a[i]=b[i]=read();
    cin>>query;
    cdq(1,n);
    for(long long i = 1,pla = 1,cnt=1;i<=q;i++){
        if(query[i-1]-'0'==0){
            scr = scr-(a[pla]-1)+(n-a[pla]);
        }else{
            scr = (n-1)*n/2-scr;
            cnt = -cnt;
        }
        pla=pla+cnt;
        if(pla==0)pla=n;
        else if(pla==n+1)pla=1;
        //cout<<scr<<endl;
        ans=(ans+(1LL*scr%mod*base[q-i])%mod)%mod;
    }
    cout<<ans;
    return 0;
}