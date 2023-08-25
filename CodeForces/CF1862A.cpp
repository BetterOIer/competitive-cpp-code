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
int n,m;
int have[25];
int main(){
    int t=read();
    while(t--){
        for(int i = 1;i<=20;i++)have[i]=0;
        n=read(),m=read();
        for(int i = 1;i<=n;i++){
            string s;
            cin>>s;
            for(int j = 1;j<=m;j++){
                if(s[j-1]=='v')have[j]|=1;
                if(s[j-1]=='i')have[j]|=(1<<1);
                if(s[j-1]=='k')have[j]|=(1<<2);
                if(s[j-1]=='a')have[j]|=(1<<3);
            }
        }
        int cho=0;
        for(int i = 1;i<=m&&cho<4;i++){
            if(have[i]&(1<<cho)){
                cho++;
            }
        }
        cout<<(cho==4? "YES\n":"NO\n");
    }
    return 0;
}