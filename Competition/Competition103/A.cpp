#include<iostream>
#include<queue>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m;
vector<int>ro[500005];
int in[500005],cnt;
bool out[500005];
queue<int>Q;
int main(){
    #ifdef LOCAL
    freopen("ex_data4.in","r",stdin);
    freopen("ex_data4.res","w",stdout);
    #endif
    n=read(),m=read();
    for(int i = 1,u,v;i<=m;i++){
        u=read(),v=read();if(u==v)continue;
        ro[u].push_back(v);
        in[v]++;
    }
    cnt=n;
    for(int i = 1;i<=n;i++){
        if(!in[i]){
            Q.push(i);
            cnt--;
            out[i]=true;
        }
    }
    while(Q.size()){
        int now = Q.front();Q.pop();
        for(int i:ro[now]){
            if(out[i])continue;
            in[i]--;
            if(!in[i]){
                Q.push(i);
                cnt--;
                out[i]=true;
            }
        }
    }
    if(cnt){
        cout<<"Yes"<<endl;
    }else cout<<"No"<<endl;
    return 0;
}