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
long long x1,y1,x2,y2,a1,a2;
__int128 gcd(__int128 m, __int128 n){
    while (n != 0){
        __int128 t = m % n;
	    m = n;
	    n = t;
	}
    return m;
}
__int128 mabs(__int128 a){
    return a<0? -a:a;
}
int main(){
    while(cin>>x1>>y1>>x2>>y2){
        __int128 f=x1,g=y1,h=x2,j=y2;
        if(gcd(mabs(f-h),mabs(g-j))<=1){
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