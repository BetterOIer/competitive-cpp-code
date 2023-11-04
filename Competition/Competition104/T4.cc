//Using binary
#include<iostream>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long a[7505];
long long n,m,ans=0;
int myPopCount(long long x){
    int res = 0;
    while(x){
        res++;
        x-=(x&(long long)(-x));
    }
    return res;
}
int main(){
    #ifndef LOCAL
    freopen("soldier.in","r",stdin);
    freopen("soldier.out","w",stdout);
    #else
    freopen("D/ex_zu4.in","r",stdin);
    freopen("D/ex_zu4.res","w",stdout);
    #endif
    n=read(),m=read();
    for(long long i = 1,len;i<=n;i++){
        len=read();
        for(long long j = 1,x;j<=len;j++){
            x=read();
            a[i]+=(1LL<<x);
        }
    }
    for(long long j = 1;j<=n;j++){
        for(long long i = 1;i<j;i++){
            long long cntj = a[j],cnti = a[i],cntAns=0;
            while((cnti&-cnti)<=cntj&&(cnti>0)){
                cntAns|=(cntj&cnti);
                cnti-=(cntj&cnti);
                cnti<<=1;
            }
            if(myPopCount(cntAns)&1){
                ans++;/* cout<<i<<" "<<j<<endl; */
            }
        }
    }
    cout<<ans;
    return 0;
}