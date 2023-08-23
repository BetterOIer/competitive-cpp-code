#include<iostream>
#include<vector>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m;
vector<int>po[200004];
deque<int>stk;
int dfn[200004],low[200004],tot=0,cnt=0;
bool instack[200004];
void Tarjan(int pos){
    //入
    dfn[pos]=low[pos]=++tot;
    stk.push_front(pos);
    instack[pos]=true;
    //回
    for(int to:po[pos]){
        if(!dfn[to]){
            Tarjan(to);
            low[pos]=min(low[pos],low[to]);
        }else if(instack[to]){
            low[pos]=min(low[pos],dfn[to]);
        }
    }
    //离
    if(dfn[pos]==low[pos]){
        int y;++cnt;
        do{
            y=stk.front();stk.pop_front();
            instack[y]=false;
        }while(y!=pos);
    }
}
int main(){
    n=read(),m=read();
    for(int i = 1,x,y;i<=m;i++){
        x=read(),y=read();
        po[x].push_back(y);
    }
    for(int i = 1;i<=n;i++){
        if(dfn[i])continue;
        Tarjan(i);
    }
    cout<<cnt;
}