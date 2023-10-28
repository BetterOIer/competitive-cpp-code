#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int t[5005];
int ans=0;
bool cmp(int a,int b){return a>b;}
int main(){
    #ifndef LOCAL
    freopen("songfen.in","r",stdin);
    freopen("songfen.out","w",stdout);
    #endif
    int n=read(),k=read(),A=read(),B=read();
    for(int i = 1;i<=n;i++){
        t[i]=read();ans+=t[i];
    }
    if(!B){
        ans=0;
        sort(t+1,t+n+1,cmp);
        for(int i = 1;i<=n;i+=k){
            int cnt =0;
            for(int j = i;j<=min(i+k-1,n);j++){
                cnt+=t[j];
            }
            ans+=min(cnt,A);
        }
    }
    cout<<ans;
    return 0;
}
//10pts