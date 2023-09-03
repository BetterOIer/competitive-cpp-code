/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
long long x,p,n,a,b,c;
void solve(){
	for(a=1;a<=5;a++){
		for(b=a;a*b<n;b++){
			if((n-a*b)%(a+b)==0){
				c=(n-a*b)/(a+b);
                return printf("%lld %lld %lld\n",a,b,c),void();
			}
		}
	}
	printf("-1\n");
}
int main(){
    int t=read();
	while(t--){
        x=read(),p=read();
		n=x*p*p;
		if(n<=20) solve();
		else{
			if(x>=p) b=p,c=p*(p-1),a=(n-b*c)/(b+c);
			else if(x==p-1) a=6,b=p-3,c=p*p-4*p+6;
			else a=p%(x+1),b=x+1-a,c=(n+a*a)/(x+1)-a;
			printf("%lld %lld %lld\n",a,b,c);
		}
	}
	return 0;
}