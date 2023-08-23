#include<iostream>
#include<vector>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int to;
    int val;
};
vector <node> ro[1000001];
bool vis[1000001];
int fl,r1,r2;
inline void find(int now,int root){
    vis[now]=1;
    for(auto i:ro[now]){
        int v=i.to;
        if(v==root)continue;
        fl = 1;
        r1 = now;
        r2 = v;
    }
}
inline void dfs(){
    
}
int main(){
    int n=read(),v,w;
    for(int i = 1;i<=n;i++){
        v=read(),w=read();
        ro[i].push_back((node){v,w});
        ro[v].push_back((node){i,w});
    }
    
}