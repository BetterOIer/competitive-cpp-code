/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int a[9];
int main(){
    for(int i = 1;i<=8;i++){
        a[i]=read();
    }
    sort(a+1,a+8+1);
    if(a[8]>=118)return cout<<10,0;
    else if(a[5]>=63) return cout<<8,0;
    else if(a[5]>=41) return cout<<3,0;
    else cout<<1;
    return 0;
}