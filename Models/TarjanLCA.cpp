#include<iostream>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int N,M,S;
struct node{
    int to;
    int whi;
};
vector<int>ro[500005];
vector<node>query[500005];
bool vis[500005];
int fa[500005],ans[500005];
int find(int pos){return (pos==fa[pos]? pos:fa[pos]=find(fa[pos]));}
void Tarjan(int pos){
    vis[pos]=true;
    for(auto i:ro[pos]){
        if(vis[i])continue;
        Tarjan(i);
        fa[i]=pos;
    }
    for(auto i:query[pos]){
        if(vis[i.to])ans[i.whi]=find(i.to);
    }
}
int main(){
    N=read(),M=read(),S=read();
    for(int i = 1;i<=N;i++){
        fa[i]=i;
    }
    for(int i = 1,x,y;i<N;i++){
        x=read(),y=read();
        ro[x].push_back(y);
        ro[y].push_back(x);
    }for(int i = 1,x,y;i<=M;i++){
        x=read(),y=read();
        query[x].push_back((node){y,i});
        query[y].push_back((node){x,i});
    }
    Tarjan(S);
    for(int i = 1;i<=M;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}