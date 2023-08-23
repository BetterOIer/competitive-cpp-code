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
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long x1,y1,x2,y2,a1,a2;
long long gcd(long long m, long long n){
    while (n != 0){
        long long t = m % n;
	    m = n;
	    n = t;
	}
    return m;
}
long long main(){
    while(cin>>x1>>y1>>x2>>y2){
        if(gcd(abs(x1-x2),abs(y1-y2))==1){
            cout<<"YE5\n";
            a1++;
        }else{
            cout<<"NO\n";
            a2++;
        }
    }
    if(a1>a2) cout<<"Poor xshen!";
    else if(a1==a2) cout<<"Friend Ship.";
    else cout<<"Yahoo!";
    return 0;
}