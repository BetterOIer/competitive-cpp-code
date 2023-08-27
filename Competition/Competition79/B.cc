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
int n,k;
string s;
void solve(){
    string s1,s2;
    for(int i = 0;i<n;i++){
        if(i&1)s2+=s[i];
        else s1+=s[i];
    }
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    s="";
    for(int i=0,j=0,k=0;i<n;i++){
        if(i&1)s+=s2[k++];
        else s+=s1[j++];
    }
}
int main(){
    int t=read();
    while(t--){
        n=read(),k=read();
        cin>>s;
        if(k&1)solve();
        else sort(s.begin(),s.end());
        cout<<s<<endl;
    }
    return 0;
}