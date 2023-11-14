#include<iostream>
#include<algorithm>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,x[1000005],y[1000005],z[1000005],xmin,xmax,ymin,ymax,zmin,zmax;
int main(){
    #ifndef LOCAL
    freopen("cube.in","r",stdin);
    freopen("cube.out","w",stdout);
    #else
    /* freopen("excube_2.in","r",stdin);
    freopen("excube_2.res","w",stdout); */
    #endif
    n=read();
    for(long long i = 1;i<=n;i++) x[i]=read(),y[i]=read(),z[i]=read();
    nth_element(x+1,x+1,x+n+1);xmin=x[1];
    nth_element(x+1,x+n,x+n+1);xmax=x[n];
    nth_element(y+1,y+1,y+n+1);ymin=y[1];
    nth_element(y+1,y+n,y+n+1);ymax=y[n];
    nth_element(z+1,z+1,z+n+1);zmin=z[1];
    nth_element(z+1,z+n,z+n+1);zmax=z[n];
    if((xmax-xmin+1LL)>n||(ymax-ymin+1LL)>n||(zmax-zmin+1LL)>n)cout<<"NO";
    else if(n==1LL*(xmax-xmin+1LL)*(ymax-ymin+1LL)*(zmax-zmin+1LL))cout<<"YES";
    else cout<<"NO";
    return 0;
}