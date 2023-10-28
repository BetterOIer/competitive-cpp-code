#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int stk[2000004],pos,a[2000004];
int l[2000004],r[2000004];
long long sum[2000004],s[2000004];
int n;
int main(){
    #ifndef LOCAL
    freopen("qiandao.in","r",stdin);
    freopen("qiandao.out","w",stdout);
    #else
    freopen("ex_segmin3.in","r",stdin);
    freopen("ex_segmin3.out","w",stdout);
    #endif
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)s[i]=s[i-1]+i;
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+s[i];
    for(int i=1;i<=n;i++){
        int x=a[i];
        while(pos&&a[stk[pos]]>=x)pos--;
        if(!pos)l[i]=1;
        else l[i]=stk[pos]+1;
        stk[++pos]=i;
    }
    pos=0;
    for(int i=n;i;i--){
        int x=a[i];
        while(pos&&a[stk[pos]]>x)pos--;
        if(!pos)r[i]=n;
        else r[i]=stk[pos]-1;
        stk[++pos]=i;
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        int tmpL=l[i], tmpR=r[i], rlen=tmpR-i+1, llen=i-tmpL;
        ans+=1ll*llen*min(llen, rlen)-s[min(llen, rlen)-1];
    }
    cout<<ans<<endl;                          
    return 0;
}