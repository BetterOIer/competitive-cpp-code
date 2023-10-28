#include<iostream>
#include<cmath>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int a[2000005];
long long ans=0;
long long cal(int l,int mid,int r){
    int rlim = (mid-l-1+mid),rOff = r-rlim;
    if(rOff>=0)return 1LL*(mid-l)*(mid-l+1)/2;
    else return 1LL*(r-mid+1)*(-rOff)+(r-mid+1)*(r-mid+2)/2;
}
int main(){
    #ifndef LOCAL
    freopen("qiandao.in","r",stdin);
    freopen("qiandao.out","w",stdout);
    #else
    freopen("ex_segmin3.in","r",stdin);
    freopen("ex_segmin3.out","w",stdout);
    #endif
    int n = read();
    bool flag1=true,flag2=true;
    for(int i = 1;i<=n;i++){
        a[i]=read();
        if(i>1&&a[i-1]<=a[i])flag1=false;
        if(i>1&&a[i-1]>=a[i])flag2=false;
    }
    if(flag1){
        cout<<1LL*(n-1)*n/2;
        return 0;
    }
    if(flag2){
        cout<<0;
        return 0;
    }
    int l = 0,r = 0;
    for(int i = 1;i<=n;i++){
        r=l=i;
        while(a[l-1]>=a[i]&&l-1>=1)l--;
        while(a[r+1]>a[i]&&r+1<=n)r++;
        /* cout<<i<<" "<<l<<" "<<r<<" "<<cal(l,i,r)<<" \n"; */
        ans+=cal(l,i,r);
    }
    cout<<ans;
    return 0;
}