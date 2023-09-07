/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<queue>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
struct MOS{
    long long s;
    long long k;
    int r;
    vector<int>son,fa;
}mos[200005];
bool inQ[200005];
void spfa(){
    queue<int>q;
    for(int i = 1;i<=n;i++)q.push(i),inQ[i]=1;
    while(!q.empty()){
        int now = q.front();q.pop();inQ[now]=0;
        long long costS=mos[now].s;
        for(int to:mos[now].son){
            costS+=mos[to].k;
        }
        if(costS>mos[now].k) continue;
        mos[now].k = costS;
        for(int to:mos[now].fa){
            if(!inQ[to])inQ[to]=1,q.push(to);
        }
    }
}
#define LOCAL
int main(){
    #ifndef LOCAL
    freopen("atm.in","r",stdin);
    freopen("atm.out","w",stdout);
    #endif
    n=read();
    for(int i = 1;i<=n;i++){
        mos[i].s=read();
        mos[i].k=read();
        mos[i].r=read();
        for(int j = 1,x;j<=mos[i].r;j++){
            x=read();
            mos[i].son.push_back(x);
            mos[x].fa.push_back(i);
        }
    }
    spfa();
    cout<<mos[1].k;
    return 0;
}