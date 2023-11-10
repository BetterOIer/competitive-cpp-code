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
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long t;
long long len;
string s;
long long vaild(char a,char b){
    if(a>b)swap(a,b);
    if(a=='A'&&b=='T')return 1;
    if(a=='C'&&b=='G')return 1;
    if(a!='A'&&a!='T'&&a!='C'&&a!='G')return -1;
    if(b!='A'&&b!='T'&&b!='C'&&b!='G')return -1;
    return 0;
}
int main(){
    t=read();
    while(t--){
        long long ans=0;
        len=read();
        cin>>s;
        for(long long i  = 0;i<len;i++){
            long long chk=vaild(s[i],s[len-i-1]);
            if(chk==-1){ans=0;goto ne;}
            else if(chk==1)ans+=i+1;
        }
        ne:
        cout<<ans<<endl;
    }
    return 0;
}