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
struct node{
    int a;
    int b;
    int c;
}tr[1000005];
int main(){
    freopen("ex_dream.in","r",stdin);
    freopen("ex_dream1.in","w",stdout);
    int n=read(),q=read();
    for(int i = 1,opt,l,r;i<=q;i++){
        tr[i].a=read(),tr[i].b=read(),tr[i].c=read();
        if(tr[i].a==3||tr[i].a==4)i--,q--;
    }
    cout<<n<<" "<<q<<endl;
    for(int i = 1;i<=q;i++){
        cout<<tr[i].a<<" "<<tr[i].b<<" "<<tr[i].c<<endl;
    }
    return 0;
}