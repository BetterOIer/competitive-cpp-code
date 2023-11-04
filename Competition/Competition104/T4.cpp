#include<iostream>
#include<set>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,ans;
set<int>s[7505];
bool vaild(int a,int b){
    int num[55];for(int i = 0;i<=54;i++)num[i]=0;
    bool hav[55];for(int i = 0;i<=54;i++)hav[i]=0;
    for(int i:s[b]) hav[i]=true;
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
int main(){
    #ifndef LOCAL
    freopen("soldier.in","r",stdin);
    freopen("soldier.out","w",stdout);
    #else
    freopen("D/ex_zu2.in","r",stdin);
    freopen("D/ex_zu2.res","w",stdout);
    #endif
    n=read(),m=read();
    for(int i = 1,len;i<=n;i++){
        len=read();
        for(int j = 1;j<=len;j++){
            s[i].insert(read());
        }
    }
    for(int j = 1;j<=n;j++){
        for(int i = 1;i<j;i++){
            if(vaild(i,j))ans++;
        }
    }
    cout<<ans;
    return 0;
}