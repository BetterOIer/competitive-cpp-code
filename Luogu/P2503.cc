/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<random>
#include<ctime>
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m;
vector<int> validBit;
int a[22];
int sum[22];
int mVal[7];
double ans=1e9;
mt19937 eng(time(0));
double getMin(int x){
    int last = 0,now=0,cnt=0,cnt2=0;
    while(x){
        ++cnt;
        if(x&1){
            now = cnt;
            mVal[++cnt2]=sum[now]-sum[last];
            last=now;
        }
        x>>=1;
    }
    mVal[++cnt2]=sum[n]-sum[last];
    double aveX= 1.0*sum[n]/m;
    double cnt3=0;
    for(int i = 1;i<=m;i++){
        cnt3+=(aveX-mVal[i])*(aveX-mVal[i]);
    } 
    cnt3 = 1.0*cnt3/m;
    return __builtin_sqrt(cnt3);
}
void SA(){
    double temp=3000,down=1e-10,delta=0.99,res=ans;
    while(temp>down){
        int
        x = eng()%n+1,
        y = eng()%n+1;
        while(y==x)y = eng()%n+1;
        swap(a[y],a[x]);
        for(int i = 1;i<=n;i++){
            sum[i]=a[i]+sum[i-1];
        }
        for(auto i:validBit){
            res = min(res,getMin(i));
        }
        if(res<ans){
            ans=res;
        }else{
            if(-exp((res-ans)/temp)*RAND_MAX>rand()){
                swap(a[y],a[x]);
            }
        }
        temp*=delta;
    }
}
int main(){
    int t = clock();
    n=read(),m=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
    }
    for(int i = 1;i<=((1<<(n-1))-1);i++){
        if(__builtin_popcount(i)==m-1)validBit.push_back(i);
    }
    SA();SA();SA();SA();SA();SA();
    printf("%.2lf",ans);
    return 0;
}