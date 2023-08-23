#include<iostream>
using namespace std;
long long x,y,ans;
long long gcd(long long a,long long b){
    return b==0? a:gcd(b,a%b);
}
int main(){
    cin>>x>>y;
    long long t=x*y;
    for(long long i=1;i*i<=t;i++)
        if(t%i==0 && gcd(i,t/i)==x)
        ans += 2;
    if(x==y) ans--;
    cout<<ans;
    return 0;
}