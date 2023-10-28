#include<iostream>
#include<vector>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
vector<int>ro[100005];
int n,q;
int ans = 0;
void dfs(int pos,int l,int r,int hav){
    for(int i:ro[pos]){
        dfs(i,l,r,hav+(l<=i&&i<=r));
    }
    if((l<=pos&&pos<=r))ans+=hav;
}
int main(){
    #ifndef LOCAL
    freopen("easy.in","r",stdin);
    freopen("easy.out","w",stdout);
    #else
    freopen("ex_tree3.in","r",stdin);
    freopen("ex_tree3.out","w",stdout);
    #endif
    n=read();
    ro[0].push_back(1);
    for(int i = 1,fa;i<n;i++){
        fa=read();
        ro[fa].push_back(i+1);
    }
    q=read();
    for(int i = 1,l,r;i<=q;i++){
        l=read(),r=read();
        l=(l^ans)%n+1;
        r=(r^ans)%n+1;
        if(l>r)swap(l,r);
        ans=0;
        dfs(0,l,r,0);
        cout<<ans<<endl;
    }
    return 0;
}

//40pts