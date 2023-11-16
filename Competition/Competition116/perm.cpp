#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
int p[300005],q[300005];
bool tag[300005];
priority_queue<int>Q;
int main(){
    #ifndef LOCAL
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    #else
    freopen("ex_perm3.in","r",stdin);
    freopen("ex_perm3.out","w",stdout);
    #endif
    n=read();
    bool flag=true;
    for(int i = 1;i<=n;i++)p[i]=read();
    for(int i = 1;i<=n;i++)q[i]=read(),flag&=(q[i]==n-i+1);
    if(flag){
        sort(p+1,p+n+1);
        for(int i = n;i>=1;i--)cout<<p[i]<<" ";
        return (~0)-(~0);
    }
    for(int i = 0;i<n;i++){
        tag[q[i]]=true;
        while(Q.size())Q.pop();
        for(int j = 1;j<=n;j++){
            Q.push(p[j]);
            if(tag[j])Q.pop();
        }
        cout<<Q.top()<<" ";
    }
    return (~0)-(~0);
}