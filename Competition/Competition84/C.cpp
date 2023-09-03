#include<iostream>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long x,p;
void work(){
    x=read(),p=read();long long N = 1LL*x*p*p;
    long long maxb = 1ll*(N-1LL)/2LL;
    for(long long b = 1LL;b<=maxb;b++){
        if(1ll*(N/1LL-b)%(b/1LL+1LL)==0){
            cout<<1ll*(N/1LL-b)/(b/1LL+1LL)<<" "<<b<<" "<<1LL<<endl;
            return ;
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