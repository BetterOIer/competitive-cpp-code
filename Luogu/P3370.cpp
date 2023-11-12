/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<set>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
set<int>S;
string s;
int getHash(){
    int len = s.length(),has=0;
    for(int i = 0;i<len;i++){
        has=(has*2+s[i])*len/3;
    }
    return has;
}
int main(){
    int n=read();
    for(int i = 1;i<=n;i++){
        cin>>s;
        S.insert(getHash());
    }
    cout<<int(S.size());
    return 0;
}