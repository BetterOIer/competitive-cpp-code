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
    #else
    /* freopen("C/ex_he4.in","r",stdin);
    freopen("C/ex_he4.res","w",stdout); */
    #endif
    n=read(),q=read();
    for(long long i = 1;i<=q;i++){
        base[i]=base[i-1]*233%mod;
    }
    for(long long i = 1;i<=n;i++)a[i]=b[i]=read();
    cin>>query;
    cdq(1,n);
    for(long long i = 1;i<=q;i++){
        if(query[i-1]-'0'==0){
            long long cnt = 0;
            for(long long j = 2;j<=n;j++){
                if(a[1]>a[j])++cnt;
            }
            scr = scr-cnt+(n-1-cnt);cnt=a[1];
            for(long long j = 1;j<n;j++){
                a[j]=a[j+1];
            }
            a[n]=cnt;
        }else{
            scr = (n-1)*n/2-scr;
            for(long long j = 1;j<(n>>1);j++)swap(a[j],a[n-j+1]);
        }
        ans=(ans+(scr*base[q-i])%mod)%mod;
    }
    cout<<ans;
    return 0;
}