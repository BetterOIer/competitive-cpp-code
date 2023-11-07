/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<map>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=((x<<3)+(x<<1)+(c^48))%150000000;return x*f;}
map<long long,long long>m;
long long a,b,c,d;
long long dfs(long long a){
	if(a==1)return 1;
	if(a==2)return 1;
	if(m[a])return m[a];
	else return m[a]=a%2==0?(dfs(a/2)+2*dfs(a/2-1))*dfs(a/2)%100000000:(dfs(a/2)*dfs(a/2)+dfs(a/2+1)*dfs(a/2+1))%100000000;
}
int main(){
	a=read();
	cout<<dfs(a+1);
}