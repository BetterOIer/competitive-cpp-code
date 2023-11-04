#include<iostream>
#include<set>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,ans;
set<int>s[7505];
int num[55];
bool hav[55];
bool vaild(int a){
    for(int i = 0;i<=54;i++)num[i]=0;
    int p = 1;
    for(int i:s[a]){
        for(;p<=54;p++){
            if(hav[p]&&p>=i){num[p]++;break;}
        }
    }
    int res=0;
    for(int i = 0;i<=54;i++)if(num[i])res++;
    return res&1;
}
long long a[7505];
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
    freopen("D/ex_zu6.in","r",stdin);
    freopen("D/ex_zu6.res","w",stdout);
    #endif
    n=read(),m=read();
    if(n<=100){
        for(int i = 1,len;i<=n;i++){
            len=read();
            for(int j = 1;j<=len;j++){
                s[i].insert(read());
            }
        }
        for(int j = 1;j<=n;j++){
            for(int i = 0;i<=54;i++)hav[i]=0;
            for(int i:s[j]) hav[i]=true;
            for(int i = 1;i<j;i++){
                if(vaild(i))ans++;
            }
        }
        cout<<ans;
    }else{
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
    }
    return 0;
}