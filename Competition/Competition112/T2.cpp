#include<iostream>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long scr=0,n,m;
long long a[100005],b[100005],c[100005];
void msort(long long l,long long r){
    if(l==r)  return;
    long long mid=(l+r)/2,i=l,j=mid+1,k=l;
    msort(l,mid),msort(mid+1,r);
    while(i<=mid&&j<=r)
    	if(b[i]<=b[j])
    		c[k++]=b[i++];
    	else
    		c[k++]=b[j++],scr+=mid-i+1;
    while(i<=mid)
    	c[k++]=b[i++];
    while(j<=r)
    	c[k++]=b[j++];
    for(long long f=l;f<=r;f++)
    	b[f]=c[f];
} 
int main(){
    #ifndef LOCAL
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    #else
    freopen("xor/xor2.in","r",stdin);
    freopen("xor/xor2.out","w",stdout);
    #endif
    n=read(),m=read();
    for(long long i = 1;i<=n;i++){
        a[i]=read();
    }
    for(long long i = 1,x;i<=m;i++){
        x=read();scr=0;
        for(long long j = 1;j<=n;j++){
            b[j]=(1LL*a[j])^(1LL*x);
        }
        msort(1,n);
        cout<<scr<<endl;
    }
    return 0;
}