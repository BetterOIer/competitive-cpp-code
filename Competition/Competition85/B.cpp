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
long long l,n,m,ans;
long long a[100005],b[100005];
priority_queue<pair<long long, long long>, vector<pair<long long, long long > >, greater<pair<long long,long long> > > q1,q2;
vector<long long> tim;
int main(){
    l=read();n=read();m=read();
    for(long long i = 1;i<=n;i++)a[i]=read(),q1.push(make_pair(a[i],i));
    for(long long i = 1;i<=m;i++)b[i]=read(),q2.push(make_pair(b[i],i));
    tim.push_back(0);
    for(long long i = 1; i <= l; i++) {
		pair<long long,long long> u = q1.top(); q1.pop();
		long long t = u.first, id = u.second;
		q1.push(make_pair(t + a[id], id));
		tim.push_back(t);
	}
    for(long long i = l; i >= 1; i--) {
		pair<long long,long long> u = q2.top(); q2.pop();
		long long t = u.first, id = u.second;
		q2.push(make_pair(t + b[id], id));
		ans = std::max(ans, tim[i] + t);
	}
    cout<<ans;
    return 0;
}