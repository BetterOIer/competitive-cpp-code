#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
int p[10],q[10],tmp[10],rnk[10];
bool ofF[10];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    #ifndef LOCAL
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    #else
    freopen("ex_perm4.in","r",stdin);
    freopen("ex_perm4.out","w",stdout);
    #endif
    n=read();
    for(int i = 1;i<=n;i++)tmp[i]=p[i]=read();
    for(int i = 1;i<=n;i++)q[i]=read();
    for(int i = 1;i<=n;i++)rnk[p[i]]=i;
    sort(tmp+1,tmp+n+1,cmp);
    int pp = 1;
    for(int i =0;i<n;i++){
        if(q[i]>=rnk[tmp[pp]]){
            /* update(1,1,n,rnk[tmp[pp]],0); */
            ofF[pp]=true;
            while(ofF[pp])pp++;
        }else if(q[i]<rnk[tmp[pp]]){
            ofF[p[q[i]]]=true;
        }
        cout<<tmp[pp]<<" ";
    }
}