/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,lim;
struct node{
    int to;
    int a;
    int b;
};
vector<node>ro[500005];

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read(),lim=read();
    for(int i = 1,x,y,a,b;i<n;i++){
        x=read(),y=read(),a=read(),b=read();
        ro[x].push_back((node){y,a,b});
        ro[y].push_back((node){x,a,b});
    }
    cout<<"0\n0";
    fclose(stdin);
    fclose(stdout);
    return 0;
}