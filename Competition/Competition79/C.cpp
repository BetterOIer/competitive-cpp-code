/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n;
vector<long long>v;
long long get_max(long long n){
    long long _sqrt = __builtin_sqrt(n);
    for(long long i = 2;i<=_sqrt;i++){
        if(n%i==0){
            return n/i;
        }
    }
    return 1;
}
int main(){
    long long t=read();
    while(t--){
        n=read();v.clear();
        while(n){
            v.push_back(n);
            long long minus = get_max(n);
            n -=minus;
        }
        cout<<v.size()<<endl;
        for(long long i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}