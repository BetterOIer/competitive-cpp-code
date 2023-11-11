#include<iostream>
#include<cstring>
#include<assert.h>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
int a[500005];
int b[500005],c[500005],scr=0,tot=0;
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
    freopen("essenceoftwilight.in","r",stdin);
    freopen("essenceoftwilight.out","w",stdout);
    #else
    freopen("essenceoftwilight/essenceoftwilight1.in","r",stdin);
    freopen("essenceoftwilight/essenceoftwilight1.out","w",stdout);
    #endif
    //cout<<500000*__lg(50000)*2;
    int t=read(),o=read();
    while(t--){
        n=read(),scr=0;
        for(int i = 1;i<=n;i++){
            a[i]=read();
        }
        for(int i = 1;i<=n;i++){
            b[i]=a[i];
        }msort(1,n);tot=scr;
        for(int i = 1;i<=n;i++){
            for(int j = i+1;j<=n;j++){
                swap(a[i],a[j]);scr=0;
                for(int i = 1;i<=n;i++){
                    b[i]=a[i];
                }msort(1,n);tot=min(scr,tot);
                swap(a[i],a[j]);
            }
        }
        cout<<tot<<endl;
    }
    return 0;
}