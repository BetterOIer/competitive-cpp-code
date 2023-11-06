#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int a[3005],n,d,ans=0;
bool hav[3005];
int main(){
    #ifndef LOCAL
    freopen("extreme.in","r",stdin);
    freopen("extreme.out","w",stdout);
    #else
    freopen("C/ex_C3.in","r",stdin);
    freopen("C/ex_C3.out","w",stdout);
    #endif
    n=read(),d=read();int maxn = (1<<(n*2))-1;
    for(int i = 1;i<=n;i++)a[i]=read();
    for(int i = 1;i<=n;i++)a[i+n]=read();
    for(int i = 0;i<=maxn;i++){
        int now = i;
        for(int j= 0;j<=(n<<1);j++)hav[j]=false;
        while(now){
            int pla = __lg(now&-now);
            hav[pla]=true;
            now^=(now&-now);
        }
        int res = 0;
        for(int j = 1,canSee=false;j<=n;j++){
            if(hav[j])continue;
            canSee=false;
            for(int k = max(1,j-d);k<=min(n,j+d);k++){
                if(hav[k+n]){canSee=true;break;}
            }
            if(canSee){
                res+=a[j];
            }
        }
        for(int j = 1,canSee=false;j<=n;j++){
            if(hav[j+n])continue;
            canSee=false;
            for(int k = max(1,j-d);k<=min(n,j+d);k++){
                if(hav[k]){canSee=true;break;}
            }
            if(canSee){
                res+=a[j+n];
            }
        }
        ans=max(ans,res);
    }
    cout<<ans;
    return 0;
}