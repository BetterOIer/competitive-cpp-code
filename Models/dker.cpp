#include<iostream>
#include<stack>
using namespace std;
const long long N=10000005;
long long ls[N],rs[N],a[N],n;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
stack <long long> ST;
void buildtree(){
    for(long long i = 1;i<=n;i++){
        while(!ST.empty()&&a[ST.top()]>a[i]){
            ls[i]=ST.top();ST.pop();
        }
        if(!ST.empty())rs[ST.top()]=i;
        ST.push(i);
    }
    return;
}
signed main(){
    n=read();
    for(long long i = 1;i<=n;i++){
        a[i]=read();;
    }
    buildtree();
    long long ans1=0,ans2=0;
    for(long long i = 1;i<=n;i++){
        ans1^=i*(ls[i]+1);
        ans2^=i*(rs[i]+1);
    }
    cout<<ans1<<" "<<ans2;
}