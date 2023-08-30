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
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,ori,tmp,q;
string s;
int main(){
    int t=read();
    while(t--){
        n=read(),ori=tmp=read(),q=read();
        cin>>s;
        for(int i = 0;i<q;i++){
            if(ori>=n){
                cout<<"YES\n";
                goto en;
            }
            if(s[i]=='+'){
                tmp++;
                ori++;
            }else{
                ori--;
            }
        }
        if(ori>=n){
            cout<<"YES\n";
        }else if(tmp<n){
            cout<<"NO\n";
        }else if(tmp>=n&&ori<n){
            cout<<"MAYBE\n";
        }
        en:
        n=0;
    }
    return 0;
}