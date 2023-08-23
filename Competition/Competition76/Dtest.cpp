/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<bits/stdc++.h>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
mt19937_64  rnd(chrono::steady_clock::now().time_since_epoch().count());
int main(){
    freopen("D.in","w",stdout);
    cout<<"100 100\n";
    for(int i = 1;i<=100;i++){
        for(int j = 1;j<=100;j++){
            cout<<rnd()%10000+1<<" \n"[j==100];
        }
    }
    return 0;
}