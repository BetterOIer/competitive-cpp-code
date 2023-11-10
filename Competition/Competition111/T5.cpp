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
int n,s,m;
int main(){
    n=read(),s=read(),m=read();
    for(int i = n;i>=0;i--){//manfen
        for(int j = 0;j<=i;j++){//extra
            for(int k =0;k<=n-i;k++){
                int o = n-i-k;
                if(o!=m-k)continue;
                if(int((10000000.0/n*i)+j+(5000000.0/n*k))==s){
                    return printf("p%d(+%d) f%d l%d",i,j,k,o),0;
                }
            }
        }
    }
    return 0;
}