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
int a[100005];
string s;
/* void solve(){
    n=read(),k=read();bool flag=true;
    cin>>s;
    while(flag){
        flag=false;
        for(int i = 0;i<=n-3;i++){
            if(s[i]>s[i+2]){
                swap(s[i],s[i+2]);
                flag=true;
            }
        }
    }
    flag=true;
    while(flag){
        flag=false;
        for(int i = 0;i<=n-k;i++){
            string tmp=s.substr(i,k),cha=tmp;
            reverse(cha.begin(),cha.end());
            if(tmp>cha){
                s=s.substr(0,i)+cha+s.substr(i+k,n-i-k);
                flag=true;
            }
        }
    }
    cout<<s<<endl;
} */
bool cmp(int a,int b){
    return s[a]<s[b];
}
void solve(){
    n=read(),k=read();
    cin>>s;
    for(int i= 0;i<n;i++)a[i]=i;
    sort(a,a+n,cmp);
    
}
int main(){
    int t=read();
    while(t--){
        solve();
    }
    return 0;
}