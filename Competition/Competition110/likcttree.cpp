#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
struct node{
    int to;
    int val;
    int id;
};
vector<node>ro[205];
int tot;
bitset<205>a;
int main(){
    #ifndef LOCAL
    freopen("likcttree.in","r",stdin);
    freopen("likcttree.out","w",stdout);
    #else
    #endif
    n=read();
    for(int i = 2,u,w;i<=n;i++){
        u=read(),w=read();
        ro[u].push_back((node){i,w,tot});    
        ro[i].push_back((node){u,w,tot});    
    }a.reset();
    for(int i = 0;i<(1<<tot);i++){
        a^=i;
    }
    return 0;
}