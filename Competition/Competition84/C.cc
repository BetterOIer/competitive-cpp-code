#include<iostream>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long x,p;
long long fac[1000005];
long long get_fac(long long N){
    long long t = __builtin_sqrt(N),tot=0;
    if(p*p==N){
        fac[++tot]=1;
        fac[++tot]=p;
        fac[++tot]=N;
        return tot;
    }
    if(p*p*2LL==N){
        fac[++tot]=1;
        fac[++tot]=p;
        fac[++tot]=p*p;
        fac[++tot]=2;
        fac[++tot]=2*p;
        fac[++tot]=N;
        return tot;
    }
    for(long long i = 1;i<t;i++){
        if(N%i==0)fac[++tot]=i,fac[++tot]=1ll*N/i;
    }
    if(N%t==0)fac[++tot]=t;
    return tot;
}
void work(){
    x=read(),p=read();long long N = 1LL*x*p*p;
    long long tot = get_fac(N);
    for(long long cidx = 1;cidx<= tot;cidx++){
        long long maxb = 1ll*(N-fac[cidx])/(fac[cidx]+1LL);
        for(long long b = fac[cidx];b<=maxb;b+=fac[cidx]){
            if(1ll*(N/fac[cidx]-b)%(b/fac[cidx]+1LL)==0){
                cout<<1ll*(N/fac[cidx]-b)/(b/fac[cidx]+1LL)<<" "<<b<<" "<<fac[cidx]<<endl;
                return ;
            }
        }
    }
    cout<<"-1\n";
}
int main(){
    long long t=read();
    while(t--){
        work();
    }
    return 0;
}