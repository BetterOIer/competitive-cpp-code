/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: http://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
int n;
long double l,r,a[23];
/* long double qpow(long double x,int p){
    long double ans = 1;
    while(p){
        if(p&1) ans*=x;
        x*=x;
        p>>=1;
    }
    return ans;
}
long double cal1(long double x){
    long double ans=0;
    for(int i = 1;i<=n+1;i++){
        ans+=1.0*a[i]*qpow(x,i-1);
    }
    return ans;
} */
long double cal(long double x){
	long double S=0;
	for(int i=n;i>=0;i--) S=S*x+a[i];
	return S;
}
int main(){
    cin>>n>>l>>r;
    for(int i = n;i>=0;i--){
        cin>>a[i];
    }
    long double mid ;
    while(r-l>=1e-6){
        mid = (l+r)/2.0;
        if(cal(mid-(1e-6))>cal(mid)) r=mid;else l=mid;
    }
    /* for(long double t = r-l;t>=1e-6;t*=0.99998){
        if(pos+t<=r){
            if(ans<cal(pos+t)){
                ans=cal(pos+t),pos+=t;
                continue;
            }
        }
        if(pos-t>=l){
            if(ans<cal(pos-t)){
                ans=cal(pos-t),pos-=t;continue;
            }
        }
    } */ 
    printf("%.13Lf", l);
    return 0;
}