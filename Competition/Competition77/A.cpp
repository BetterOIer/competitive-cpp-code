/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,k;
int team[100005][6];
set<int>s;
vector<int>del;
int check(int a,int b){
    int fg1=false,fg2=false;
    for(int i = 1;i<=k;i++){
        if(team[a][i]>team[b][i])fg1=1;
        else if(team[a][i]<team[b][i])fg2=2;
    }
    return fg1+fg2;
}
int main(){
    n=read(),k=read();
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=k;j++){
            team[i][j]=read();
        }
    }
    for(int i = 1;i<=n;i++){
        s.insert(i);del.clear();
        for(auto i:s){
            for(auto j:s){
                if(i>=j)continue;
                int res = check(i,j);
                if(res==1) del.push_back(j);
                else if(res==2) del.push_back(i);
            }
        }
        for(auto i:del)s.erase(i);
        cout<<s.size()<<" ";
    }
    return 0;
}