#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long pos,neg,zero,one;
int main(){
    #ifndef LOCAL
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    #else
    freopen("ex_number1.in","r",stdin);
    freopen("ex_number1.out","w",stdout);
    #endif
    long long n=read(),ans=0;pos=neg=zero=one=0;
    for(long long i = 1,cur;i<=n;i++){
        cur=read();
        if(cur<=0)ans+=(pos);
        else if(cur==1)ans+=(pos+neg+zero);
        else ans+=(zero+neg+one);

        if(cur<0)neg++;
        else if(cur==0)zero++;
        else if(cur==1)pos++,one++;
        else pos++;
    }
    printf("%lld\n",ans);
    return 0;
}