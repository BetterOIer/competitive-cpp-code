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
int a[25],tmp[25];
int find(bool opt,int whi_st,int whi_en,int judge){
    for(int i = whi_st+1;i<=whi_en;i++){
        if(opt&&judge<a[i])return i;
        if((!opt)&&judge>=a[i])return i;
    }
    return whi_en+1;
}
int dfs(int l,int r){
    int mid= (l+r)>>1,i = find(0,l-1,r,mid),j=find(1,l-1,r,mid),p1=l-1,p2=mid;
    bool flag1 = true, flag2 = true;
    for(;i<=r&&j<=r;i = find(0,i,r,mid),j = find(1,j,r,mid)){
        tmp[++p1]=a[i];
        tmp[++p2]=a[j];
        if(p1!=a[i]) flag1 = false;
        if(p2!=a[j]) flag2 = false;
    }
    for(;i<=r;i = find(0,i,r,mid)){tmp[++p1]=a[i];if(p1!=a[i]) flag1 = false;}
    for(;j<=r;j = find(1,j,r,mid)){tmp[++p2]=a[j];if(p2!=a[j]) flag2 = false;}
    for(int o = l;o<=r;o++)a[o]=tmp[o],tmp[o]=0;
    int ans=1;
    if(flag1&&flag2)return 1;
    if(!flag1) ans+=dfs(l,mid);
    if(!flag2) ans+=dfs(mid+1,r);
    return ans;
}
int main(){
    int t=read();
    while(t--){
        n=read();
        for(int i = 1;i<=n;i++){
            a[i]=read();
        }
        int ans=0;
        for(int i = 1;i<=n;i++){
            if(a[i]!=i){ans=dfs(1,n);break;}
        }
        cout<<ans<<endl;
    }
    return 0;
}