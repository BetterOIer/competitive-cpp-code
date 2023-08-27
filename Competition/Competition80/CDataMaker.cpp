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
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
/* int main(){
    int n=20;
    cout<<n<<endl;
    for(int i = 1;i<=n;i++){
        cout<<rnd()%1000000007<<" ";
    }
    return 0;
} */
int main(){
    freopen("C_20.in","w",stdout);
    int n=1000000;
    cout<<n<<endl;
    for(int i = 1;i<=n;i++){
        cout<<rnd()%(1152921504606846976LL)<<" ";
    }
    return 0;
}