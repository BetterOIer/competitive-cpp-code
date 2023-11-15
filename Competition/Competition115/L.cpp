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
int n,c[105],ans;
string s;
bool hav[105];
void add(int pos,int val){
    while(pos<=n){
        c[pos]+=val;
        pos+=(pos&-pos);
    }
}
int main(){
    int t=read();
    while(t--){
        n=read(),ans=0;
        cin>>s;
        for(int i = 1;i<=n;i++)hav[i]=s[i-1]-'0';
        for(int i = 1;i<=n;i++)c[i]=0;
        for(int i = 1;i<=n;i++){
            if(bool(c[i])!=hav[i]){
                if(c[i])add(i,-c[i]);
                else add(i,1);
                ans++;
            }
        }
        printf("%d\n",ans);
    }    
    return 0;
}