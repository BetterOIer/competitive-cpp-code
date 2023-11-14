/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https:
* FileStation: https:
* OnlineJudge: http:
=================================================*/
#include<iostream>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
const int MAX=100010;
int n,m,u,v,del[MAX];
int du[MAX][2];
stack<int>st;
vector<int>G[MAX];
void dfs(int now){
	for(int i=del[now];i<G[now].size();i=del[now]){ 
		del[now]=i+1;
		dfs(G[now][i]);
	}st.push(now);
}
int main(){
    n=read(),m=read();
    for(int i=1;i<=m;i++) u=read(),v=read(),G[u].push_back(v),du[u][1]++,du[v][0]++;  
    for(int i=1;i<=n;i++) sort(G[i].begin(),G[i].end());
    int S=1,cnt[2]={0,0}; 
    bool flag=1; 
    for(int i=1;i<=n;i++){
        if(du[i][1]!=du[i][0]){
            flag=0;
            if(du[i][1]-du[i][0]==1) cnt[1]++,S=i;
            else if(du[i][0]-du[i][1]==1) cnt[0]++;
            else return puts("No"),0;
        }
    }
    if((!flag)&&!(cnt[0]==cnt[1]&&cnt[0]==1)) return !puts("No"),0;
    dfs(S);
    while(!st.empty()) printf("%d ",st.top()),st.pop();
    return 0; 
}