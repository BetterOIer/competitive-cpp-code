#include<iostream>
#include<bitset>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int a[5005],b[5005];
int dp[5005];
bitset<5005>pre[5005];
int n,c;
void out(int x,int y){
    if(x==y&&x==1){
        return;
    }
    if(pre[x][y]==1){
        out(x,y-1);
        cout<<"R";
    }else{
        out(x-1,y);
        cout<<"D";
    }
}
int main(){
    n=read(),c=read();
    for(int i = 1;i<=n;i++) a[i]=read();
    for(int i = 1;i<=n;i++) b[i]=read();
    for(int i =  1;i<=n;i++){
        for(int j =  1;j<=n;j++){
            if(dp[j-1]>dp[j]){
                dp[j]=dp[j-1]+a[i]*b[j]%c;
                pre[i][j]=1;
            }else{
                dp[j]=dp[j]+a[i]*b[j]%c;
                pre[i][j]=0;
            }
        }
    }
    out(n,n);
    return 0;
}