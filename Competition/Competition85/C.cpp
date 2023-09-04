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
string s;
int len;
int k=2147483600,num=0;
bool valid(int l,int r){
    int hal = (r-l+1)>>1;
    for(int i = 1;i<=hal;i++){
        string s1 = s.substr(l,i),s2 = s.substr(l,r-l+1);
        while(s2.length()%i!=0)s2+=' ';
        bool flag=true;
        for(int j = 0;j<=r-l-i+1&&flag;j+=i){
            if(s2.substr(j,i)!=s1) flag=false;
        }
        if(flag) return false;
    }
    return true;
}
void dfs(int step,int last,int cut){
    if(step==len){
        if(cut==0) return;
        if(cut==k)num++;
        else if(cut<k)k=cut,num=1;
        return;
    }
    if(cut>k)return;
    if(valid(last,step)){
        dfs(step+1,step+1,cut+1);
    }
    dfs(step+1,last,cut);
}
int main(){
    cin>>s;len=s.length();
    dfs(0,0,0);
    cout<<k+1<<"\n"<<num;
    return 0;
}