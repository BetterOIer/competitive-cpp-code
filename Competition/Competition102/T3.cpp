#include<iostream>
#include<vector>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int fat[100005];
bool vis[100005];
int n,q;
int ans = 0;
int getAns(int pos,int l,int r){
    int res=0,cnt=1;vis[pos]=true;
    for(int i = pos;i;i = fat[i]){
        if(i<=r&&i>=l&&!(vis[i]))cnt++;
        if(i<=r&&i>=l)res+=cnt;
    }
    return res;
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
    for(int i = 1,fa;i<n;i++){
        fa=read();
        fat[i+1]=fa;
    }
    q=read();
    for(int i = 1,l,r;i<=q;i++){
        l=read(),r=read();
        l=(l^ans)%n+1;
        r=(r^ans)%n+1;
        if(l>r)swap(l,r);
        ans=0;
        for(int j = l;j<=r;j++)vis[j]=false;
        for(int j = l;j<=r;j++){
            if(!vis[j])ans+=getAns(j,l,r);
        }
        cout<<ans<<endl;
    }
    return 0;
}

//40pts