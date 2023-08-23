/*=================================================
* Le vent se lève, il faut tenter de vivre! 
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: betteroier.site:1000 
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    __int128_t ans=n, cnt1=0;
    for(int j = 0;j<=2147483647;j++){
        if(j*j>n){
            cout<<j-1<<".";
            cnt1=j-1;
            ans-=(j-1)*(j-1);
            ans*=100;
            break;
        }
    }
    for(int i = 1;i<=35;i++){
        for(int j = 0;j<=10;j++){
            if(1LL*(cnt1*20+1LL*j)*1LL*j>ans){
                cout<<j-1;
                ans-=1LL*(cnt1*20+j-1)*(j-1);
                ans*=100;
                cnt1=1LL*(cnt1*10+j-1);
                break;
            }
        }
    }
}