#include<iostream>
#include<vector>
#include<stack>
#include<ctime>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int t;
int n;
struct node{
    long long s;
    long long k;
    int r;
    vector<int>son;
}mos[200005];
stack<int>stk;
long long minCost = 9223372036854775807ll;
void dfs(long long cost){
    if(stk.empty()){
        minCost=min(minCost,cost);
        cout<<minCost<<endl;
        return;
    }
    #ifdef ONLINE 
    if(clock()-t<750){
        return;
    }
    #endif
    int popOut = stk.top();stk.pop();
    dfs(cost+mos[popOut].k);
    for(int i:mos[popOut].son){
        stk.push(i);
        #ifdef ONLINE
        if(clock()-t<750){
            return;
        }
        #endif
    }
    dfs(cost+mos[popOut].s);
}
int main(){
    freopen("atm.in","r",stdin);
    freopen("atm.out","w",stdout);
    n=read();
    for(int i = 1;i<=n;i++){
        mos[i].s=read();
        mos[i].k=read();
        mos[i].r=read();
        for(int j = 1,x;j<=mos[i].r;j++){
            x=read();mos[i].son.push_back(x);
        }
    }
    
    cout<<mos[1].k<<endl;
    return 0;
}