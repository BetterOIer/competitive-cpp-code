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
#include<deque>
#include<cmath>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,k;
vector<int>ro[100005],b,w,s,rst;
deque<int>stk;
int dfn[200004],low[200004],tot=0,cnt=0;
bool instack[200004];
int minn = 2147483647,whi=0;
int dfs(int pos,int fa,int col){
    int ans=0;
    if(col)w.push_back(pos);
    else b.push_back(pos);
    for(int to:ro[pos]){
        if(to==fa)continue;
        ans+=dfs(to,pos,col^1);
    }
    return ans+col;
}
void Tarjan(int pos){
    //入
    dfn[pos]=low[pos]=++tot;
    stk.push_front(pos);
    instack[pos]=true;
    //回
    for(int to:ro[pos]){
        if(!dfn[to]){
            Tarjan(to);
            low[pos]=min(low[pos],low[to]);
        }else if(instack[to]){
            low[pos]=min(low[pos],dfn[to]);
        }
    }
    //离
    if(dfn[pos]==low[pos]){
        int y,size=0;++cnt;s.clear();
        do{
            y=stk.front();stk.pop_front();
            instack[y]=false;
            size++;
            s.push_back(y);
        }while(y!=pos);
        if(size<minn&&size>=3){
            minn=size;
            rst=s;
        }
    }
}
int main(){
    n=read(),m=read(),k=read();
    for(int i = 1,u,v;i<=m;i++){
        u=read(),v=read();
        ro[u].push_back(v);
        ro[v].push_back(u);
    }
    if(m==n-1){
        cout<<1<<endl;
        k = ceil(k*0.5);
        int ans = dfs(1,0,0);
        if(ans<k){
            for(int i = 0;i<k;i++){
                cout<<b[i]<<" ";  
            }
        }else{
            for(int i = 0;i<k;i++){
                cout<<w[i]<<" ";  
            }
        }
    }
    else{
        Tarjan(1);
        if(minn<=k){
            cout<<2<<endl;
            cout<<rst.size()<<endl;
            for(auto i:rst){
                cout<<i<<" ";
            }
        }else{
            cout<<1<<endl;
            k = ceil(k*0.5);
            for(int i = 0,j=1;j<=k;i+=2,j++){
                cout<<rst[i]<<" ";
            }
        }
    }
    return 0;
}