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
int a[20][100006];
int sum[2][20];
int ans=1e9+7;
string s;
int cal(int sit){
    int res=0;
    for(int i = 1;i<=n;i++){
        res+=sum[1-((sit>>(i-1))&1)][i];
    }
    return res;
}
int main(){
    freopen("array.in","r",stdin);
    freopen("array.out","w",stdout);
    n=read(),m=read();
    for(int i= 1;i<=n;i++){
        cin>>s;
        for(int j = 1;j<=m;j++){
            a[i][j]=(s[j-1]=='1');
            sum[1][i]+=a[i][j];
        }
        sum[0][i]=m-sum[1][i];
    }
    for(int o = 0;o<(1<<(n+1));o++){
        int num1 = cal(o);
        for(int j = 1;j<=m;j++){
            int cnt=0;
            for(int i= 1;i<=n;i++){
                cnt+= (o&(1<<(i-1))? 1-a[i][j]:a[i][j]);
            }
            num1-=(n-cnt<cnt? cnt+cnt-n:0);
        }
        ans=min(ans,num1);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}