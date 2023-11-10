#include<iostream>
#include<bitset>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,k,val[100005];
bitset<100005>a,ansa;
int ans=-1;
string s;
int chkAns(int chgPos){
    int res=0;
    int cnt = chgPos;
    while(cnt){
        res+=val[__lg(cnt&-cnt)+1];
        cnt-=cnt&-cnt;
    }
    for(int i = 0;i<n;i++){
        for(int tmp = 1;tmp<=n/2;tmp++){
            if(a[((i-tmp)%n+n)%n]==a[((i+tmp)%n+n)%n]&&a[((i-tmp)%n+n)%n]==a[i])
            res+=k;
        }
    }
    return res;
}
int main(){
    #ifndef LOCAL
    freopen("table.in","r",stdin);
    freopen("table.out","w",stdout);
    #else
    #endif
    n=read(),k=read();
    for(int i = 1;i<=n;i++){
        val[i]=read();
    }
    cin>>s;
    for(int i = 0;i<n;i++){
        a[i]=s[i]-'0';
    }
    for(int i = 0;i<(1<<n);i++){
        a^=i;
        if(ans==-1)ans=chkAns(i);
        else ans = min(ans,chkAns(i));
        a^=i;
    }
    cout<<ans;
    return 0;
}