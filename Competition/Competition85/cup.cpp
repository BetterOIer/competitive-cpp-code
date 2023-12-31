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
int n,m,k;
int a[2005],b[2005],gcd[2005],pri[1000005],val[1000005],priNum;
bool vis[2000005]={1,1};
int GCD(int x,int y){
    while(y^=x^=y^=x%=y);
    return x;
}
int get_pri(int maxx){
    int p = 1;
    for(int i=2;i<=maxx;i++){
		if (vis[i]==0){
            pri[++k]=i;
            if(i==b[p])val[k]=-1,p++;
            else val[k]=1;
        }
		for(int j=1;j<=k;j++){
			if(i*pri[j]>maxx)break;
			vis[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}	
	}
    return k;
}
int cal2(int cnt){
    int ans=0;
    for(int j = 1;j<=priNum&&cnt>=pri[j];j++){
        while(cnt%pri[j]==0){
            cnt/=pri[j];
            ans+=val[j];
        }
    }
    if(cnt>1){
        for(int i = m;i>=1;i--){
            if(cnt==b[i]) return ans-1;
        }
        return ans+1;
    }
    return ans;
}
int main(){
    n=read(),m=read();
    for(int i = 1;i<=n;i++) a[i]=read();
    for(int i = 1;i<=m;i++) b[i]=read();
    priNum = get_pri(1e6);
    gcd[0]=a[1];
    int div=1,ans=0;
    for(int i = 1;i<=n;i++) gcd[i]=GCD(a[i],gcd[i-1]),ans+=cal2(a[i]);
    for(int i=n,o;i;i--){
        if((o=cal2(gcd[i]/div))<0)ans-=o*i,div=gcd[i];
    }
    cout<<ans;
    return 0;
}