/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/

//Violent Version

/* #include<iostream>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,ans=0;
long long a[200005];
long long sum[200005];
long long main(){
    freopen("sumII.in","r",stdin);
    freopen("sumII.out","w",stdout);
    n=read();
    for(long long i = 1;i<=n;i++){
        a[i]=sum[i]=read();
        ans+=(a[i]==1);
    }
    for(long long k = 1;k<=n;k++){
        for(long long sta = 1;sta<=n-k;sta++){
            long long enp = sta+k;
            sum[sta]+=a[enp];
            if(sum[sta]&&(k+1)%sum[sta]==0) ans++;
        }
    }
    cout<<ans;
    return 0;
} */

//Segment Tree record the Furthest right node

//Umm so slow...

/* #include<iostream>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,ans=0;
long long val[300005],a[300005];
void pushup(long long pos){
    val[pos] = val[pos<<1]+val[pos<<1|1];
}
void build(long long pos,long long l,long long r){
    if(l==r){
        a[l]=val[pos]=read();
        return;
    }
    long long mid = (l+r)>>1;
    build(pos<<1,l,mid);build(pos<<1|1,mid+1,r);
    pushup(pos);
}
long long query(long long pos,long long l,long long r,long long x,long long y){
    if(x<=l&&r<=y)return val[pos];
    long long mid = (l+r)>>1,ans=0;
    if(mid>=x)ans+=query(pos<<1,l,mid,x,y);
    if(mid<y)ans+=query(pos<<1|1,mid+1,r,x,y);
    return ans;
}
long long queryL(long long l,long long r){
    if(l>=r)return l;
    long long mid = (l+r)>>1;
    if(query(1,1,n,l,mid)>0) return queryL(l,mid);
    else return queryL(mid+1,r);
}
long long main(){
    freopen("sumII4.in","r",stdin);
    freopen("sumII.out","w",stdout);
    n=read();
    build(1,1,n);
    for(long long i = 1;i<=n;i++){
        long long l1,num1,last;
        for(l1 = queryL(i,n),num1=0,last=i;l1<=n;l1=queryL(l1,n)){
            if(l1==n&&!a[l1]) goto nex;
            if((l1-i)&&num1){
                ans+=(l1-i)/num1-(last-i)/num1;
            }
            num1++;
            last=l1;
            nex:
            l1++;
        }
        if((l1-i)&&num1){
            ans+=(l1-i)/num1-(last-i)/num1;
        }
    }
    cout<<ans<<endl;
} */

//Replace Segment Tree to nex array


#include<iostream>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,ans=0;
long long a[300005],nex[300005],sum=0;
long long queryL(long long l){
    return nex[l];
}
int main(){
    freopen("sumII.in","r",stdin);
    freopen("sumII.out","w",stdout);
    n=read();
    for(long long i = 1;i<=n;i++)a[i]=read(),sum+=a[i];
    if(sum==n){
        ans=(n+1)*n/2;
        cout<<ans<<endl;
        return 0;
    }else if(sum==0){
        ans=0;
        cout<<ans<<endl;
        return 0;
    }
    for(long long i = n,cnt=n+1;i>=0;i--){
        nex[i]=cnt;
        if(a[i])cnt=i;
    }
    for(long long i = 1;i<=n;i++){
        long long l1,num1,last;
        for(l1 = queryL(i-1),num1=0,last=i;l1<=n;l1=queryL(l1)){
            if((l1-i)&&num1){
                ans+=(l1-i)/num1-(last-i)/num1;
            }
            num1++;
            last=l1;
        }
        if((l1-i)&&num1){
            ans+=(l1-i)/num1-(last-i)/num1;
        }
    }
    cout<<ans<<endl;
    return 0;
}