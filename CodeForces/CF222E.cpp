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
const int mod = 1e9+7;
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,k,ans=0;
vector<int>lim[53];
int getPos(char x){return (x>='a'? x-'a'+1:x-'A'+27);}
void dfs(int pos,int last){
    if(pos==n+1){return (ans+=1)%=mod,void();}
    bool canGo[53];for(int i = 1;i<=52;i++)canGo[i]=true;
    if(last)for(int i:lim[last])canGo[i]=false;
    for(int i = 1;i<=m;i++)if(canGo[i])dfs(pos+1,i);
}
int main(){
    n=read(),m=read(),k=read();
    for(int i = 1;i<=k;i++){
        char a1,a2;
        cin>>a1>>a2;
        lim[getPos(a1)].push_back(getPos(a2));
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}