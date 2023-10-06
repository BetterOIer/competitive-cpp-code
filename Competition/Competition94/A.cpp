/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,a[1000005];
struct QUERY{
    int l;
    int r;
    int ans;
    int idx;
}que[1000005];
bool cmp1(const QUERY a, const QUERY b){
    if(a.l==b.l) return a.r<b.r;
    return a.l<b.l;
}
bool cmp2(const QUERY a, const QUERY b){
    return a.idx<b.idx;
}
vector<int>inQue;
int main(){
    freopen("pair.in","r",stdin);
    freopen("pair.out","w",stdout);
    n=read(),m=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
    }
    for(int i  =1;i<=m;i++){
        que[i].l=read(),que[i].r=read(),que[i].idx=i;
    }
    sort(que+1,que+m+1,cmp1);
    for(int i = 1,l=1,r = 1,ans=0;i<=m;i++){
        if(que[i].l>l){
            inQue.clear();
            l=que[i].l;
            r = que[i].l-1;
            ans=0;
        }
        for(int j = r+1;j<=que[i].r;j++){
            auto iter = upper_bound(inQue.begin(),inQue.end(),a[j])--;
            ans+= inQue.end()-iter;
            inQue.insert(iter,a[j]);
        }
        que[i].ans=ans;
        r = que[i].r;
    }
    sort(que+1,que+m+1,cmp2);
    for(int i = 1;i<=m;i++){
        printf("%d\n",que[i].ans);
    }
    return 0;
}