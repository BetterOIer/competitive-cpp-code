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
int n,m;
int a[500005];
int lowbit(int pos){return pos&-pos;}
void add(int pos,int val){
    for(;pos<=n;pos+=lowbit(pos)){
        a[pos]+=val;
    }
}
long long sum(long long pos){
    long long ans=0;
    for(;pos>0;pos-=lowbit(pos)) ans+=a[pos];
    return ans;
}
long long query(int l,int r){
    return sum(r)-sum(l-1);
}
int main(){
    n=read(),m=read();
    for(int i = 1;i<=n;i++)add(i,read());
    for(int i = 1,opt,x,k;i<=m;i++){
        opt=read(),x=read(),k=read();
        if(opt&1)add(x,k);
        else cout<<query(x,k)<<endl;
    }
    return 0;
}