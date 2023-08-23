#include<iostream>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int dfn[200004],low[200004],n,m;
int tot,cnt,root;
bool cut[200004];
int num[200004];
vector<int>ro[200004];
void Tarjan(int pos){
    dfn[pos]=low[pos]=++tot;
    int child=0;
    for(int to:ro[pos]){
        if(!dfn[to]){
            Tarjan(to);
            low[pos]=min(low[to],low[pos]);
            if(low[to]>=dfn[pos]){
                child++;
                if(pos!=root||child>1)cut[pos]=true;
            }
        }else{
            low[pos]=min(dfn[to],low[pos]);
        }
    }
}
int main(){
    n=read(),m=read();
    for(int i = 1,x,y;i<=m;i++){
        x=read(),y=read();
        ro[x].push_back(y);
        ro[y].push_back(x);
    }
    for(int i = 1;i<=n;i++){
        if(dfn[i])continue;
        root=i;
        Tarjan(i);
    }
    int nu=0;
    for(int i = 1;i<=n;i++){
        if(!cut[i])continue;
        num[++nu]=i;
    }
    cout<<nu<<endl;
    for(int i = 1;i<=nu;i++){
        cout<<num[i]<<" ";
    }
    return 0;
}
