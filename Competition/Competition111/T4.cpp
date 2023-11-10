/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cmath>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
bool isPrime(int n) {  
    if (n <= 1) {  
        return false;  
    }  
    for (int i = 2; i <= sqrt(n); i++) {  
        if (n % i == 0) {  
            return false;  
        }  
    }  
    return true;  
}  
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        int cnt=i,coutt=0;
        for(int j = 1;coutt<i*i;j++){
            if(!isPrime('A'+cnt-1+j))cout<<" ";
            else {cout<<char('A'+cnt-1),cnt++,coutt++;if(cnt>26)cnt=1;}
        }
        cout<<endl;
    }
    return 0;
}