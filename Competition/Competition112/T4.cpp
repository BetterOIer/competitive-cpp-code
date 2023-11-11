#include<iostream>
#include<cstring>
const int mod = 998244353;
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,k,maxx,ans=0;
int a[5000005],tim[5000005];
void add(int &a,int b){
    if(a+b>=mod)a=0;
    else a = a+b;
}
long long qpow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=1ll*res*a;
        a=1ll*a*a;
        b>>=1;
    }
    return res;
}
bool chkAns(){
    /* memset(tim,0,sizeof tim);
    for(int i = 1;i<=n;i++){
        tim[a[i]]++;
        if(tim[a[i]]>1)return false;
    }
    memset(tim,0,sizeof tim);
    for(int i = 1;i<=n;i++){
        tim[a[i+n]]++;
        if(tim[a[i+n]]>1)return false;
    }
    for(int i = 1;i<=n;i++){
        if(a[i+n]==a[i])return false;
    } */
    int cnt=0;
    for(int i = 1;i<=(n<<1);i++){
        cnt^=a[i];
    }
    return cnt==0;
}
int app[2][100005];
void dfs(int whi){
    if(whi==(n<<1)+1){
        add(ans,chkAns());
        return ;
    }
    for(int i = 0;i<maxx;i++){
        if(whi>n&&a[(whi-1)%n+1]==i)continue;
        if(app[(whi-1)/n][i]==1)continue;
        a[whi]=i;
        app[(whi-1)/n][i]++;
        dfs(whi+1);
        app[(whi-1)/n][i]--;
    }
}
int main(){
    #ifndef LOCAL
    freopen("mouse.in","r",stdin);
    freopen("mouse.out","w",stdout);
    #else
    #endif
    n=read(),k=read();
    maxx=qpow(2,k);
    dfs(1);
    cout<<ans;
    return 0;
}