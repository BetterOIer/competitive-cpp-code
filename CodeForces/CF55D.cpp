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
const long long mod = 2520;
inline long long read(){register long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long a, b;
long long num[20],len,book[mod+1];
long long dp[20][mod+1][51];
inline long long gcd(register long long x,register long long y){
    if(!y) return x;
    return gcd(y,x%y);
}
inline long long dfs(register long long pos,register long long ori,register long long lcm,bool lim){
    if(!pos) return ori%lcm==0;
    if((!lim)&&(~dp[pos][ori][book[lcm]])) return dp[pos][ori][book[lcm]];
    register long long high = lim? num[pos]:9,ans=0;
    for(register long long i = 1;i<=high;i++){
        register long long n_lcm = lcm*i/gcd(lcm,i);
        ans+=dfs(pos-1,(ori*10+i)%mod,n_lcm,lim&&i==high);
    }
    ans+=dfs(pos-1,ori*10%mod,lcm,lim&&0==high);
    if(!lim)dp[pos][ori][book[lcm]]=ans;
    return ans;
}
inline long long solve(register long long x){
    register long long cnt =x;len=0;
    while(cnt){
        num[++len]=cnt%10;
        cnt/=10;
    }
    return dfs(len,0,1,1);
}
void init(){
    memset(dp,-1,sizeof dp);
	register long long num=0;
	for(register long long i=1;i<=mod;i++){
		if(mod%i==0){
			num++;
			book[i]=num;
		}
	}
}

int main(){
    init();
    register long long t=read();
    while(t--){
        a=read(),b=read();
        cout<<solve(b)-solve(a-1)<<endl;
    }
    return 0;
}