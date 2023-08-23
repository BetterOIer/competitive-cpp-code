/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e5+5;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m;
int x[N],y[N],c[N],sa[N],rk[N],height[N];
string s;
void get_sa(){
    int i ,j, k;
    for(i = 1;i<=n;i++) c[x[i]=s[i]]++;
    for(i = 1;i<=m;i++) c[i]+=c[i-1];
    for(i = n;i;i--) sa[c[x[i]]--]=i;
    for(k=1;k<=n;k<<=1){
        memset(c,0,sizeof c);
        for(i = 1;i<=n;i++)y[i]=sa[i];
        for(i = 1;i<=n;i++)c[x[y[i]+k]]++;
        for(i = 1;i<=m;i++)c[i]+=c[i-1];
        for(i = n;i;i--)sa[c[x[y[i]+k]]--]=y[i];

        memset(c,0,sizeof c);
        for(i = 1;i<=n;i++)y[i]=sa[i];
        for(i = 1;i<=n;i++)c[x[y[i]]]++;
        for(i = 1;i<=m;i++)c[i]+=c[i-1];
        for(i = n;i;i--)sa[c[x[y[i]]]--]=y[i];

        for(i = 1;i<=n;i++)y[i]=x[i];
        for(m=0,i=1;i<=n;i++){
            if(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])x[sa[i]]=m;
            else x[sa[i]]=++m;
        }
        if(m==n)break;
    }
}
void get_height(){
    for(int i = 1;i<=n;i++)rk[sa[i]]=i;
    for(int i = 1,k=0;i<=n;i++){
        if(rk[i]==1)continue;
        if(k)k--;
        int j = sa[rk[i]-1];
        while(i+k<=n&&j+k<=n && s[i+k]==s[j+k])k++;
        height[rk[i]]=k;
    }
}
int main(){
    
    return 0;
}