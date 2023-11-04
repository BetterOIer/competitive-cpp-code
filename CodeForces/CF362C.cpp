/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
int a[5005],b[5005],c[5005],f[5005][5005],g[5005][5005],sum,ans,num;
void cdq(int l,int r){
    if(l==r) return ;
    int mid=(l+r)>>1;
    cdq(l,mid),cdq(mid+1,r);
    int i,j,num=l-1;
    for(i=mid+1,j=l;i<=r;i++){
        while(b[j]<b[i]&&j<=mid) c[++num]=b[j++];
        sum+=mid-j+1;
        c[++num]=b[i];
    }
    while(j<=mid) c[++num]=b[j++];
    for(int i=l;i<=r;i++) b[i]=c[i];
}
int main(){
    n=read();
    for(int i = 1;i<=n;i++) a[i]=b[i]=read()+1;
    for(int i = 1;i<=n;i++)for(int j = 1;j<=n;j++) f[j][i]=f[j-1][i]+(a[i]<a[j]),g[j][i]=g[j-1][i]+(a[i]>a[j]);
    cdq(1,n);
    for(int l = 1;l<=n;l++){
        for(int r = l+1;r<=n;r++){
            if(f[r][l]-f[l][l]-g[r][l]+g[l][l]-f[r][r]+f[l][r]+g[r][r]-g[l][r]<ans){
                ans=f[r][l]-f[l][l]-g[r][l]+g[l][l]-f[r][r]+f[l][r]+g[r][r]-g[l][r];
                num=1;
            }else if(f[r][l]-f[l][l]-g[r][l]+g[l][l]-f[r][r]+f[l][r]+g[r][r]-g[l][r]==ans)num++;
        }
    }
    ans+=sum;
    cout<<ans<<" "<<num;
    return 0;
}