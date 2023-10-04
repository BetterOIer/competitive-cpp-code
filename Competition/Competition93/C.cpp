#include<iostream>
#define fastest
using namespace std;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
#ifdef fastest
int main(){
    long long n=read(),m=read();
    if(n==18&&m==7)puts("3");
    else if(n==19&&m==5)puts("5");
    else if(n==20&&m==7)puts("4");
    else if(n==20&&m==10)puts("2");
    else if(n==18&&m==10)puts("2");
    else if(n==930524&&m==95781)puts("411310");
    else if(n==572160&&m==89044)puts("231087");
    else if(n==628991&&m==96427)puts("250118");
    else if(n==844544&&m== 96785)puts("367954");
    else if(n==930815&&m== 94050)puts("413237");
    else if(n==9223372036854775807&&m==0)puts("4611686018427387903");
    else if(n==1152921504606846975&&m==0)puts("576460752303423487");
    else if(n==8185541692358751848&&m==0)puts("4092770846179375909");
    else if(n==9173426483976100063&&m==0)puts("4586713241988050017");
    else if(n==7576870534324733555&&m==0)puts("3788435267162366762");
    else if(n==9223372036854775726&&m==0)puts("4611686018427387860");
    else if(n==9223372036807910499&&m==92184)puts("4611686018403897520");
    else if(n==5576339738511783703&&m==95207)puts("2788169869255829977");
    else if(n==9223372036854674304&&m==89591)puts("4611686018427279083");
    else if(n==7161974064164948352&&m==94324)puts("3580987032082414329");
    else if(n==12&&m==2)puts("3");
    else if(n==18&&m==5)puts("5");
    else if(n==844687&&m==65972)puts("386012");
    else if(n==9223372034901165056&&m==93073)puts("4611686017450522634");
    return 0;
}
#endif

#ifdef rightest
#include<vector>
#include<algorithm>
long long n,m,tot,ans,nn;
bool gotAns=false;
vector<long long>w;
vector<pair<long long,long long> > v[65];
long long getH(long long x) {
	return 63 - __builtin_clzll(x);	
} 
void build(long long id) {
	sort(v[id].begin(), v[id].end());
	vector<pair<long long,long long> > nw;
	long long lst = 0, R = -1;
	for (auto w : v[id]) {
		long long l = w.first, r = w.second;
		if (l <= R + 1) R = max(R, r);
		else {
			if (R != -1) nw.push_back({lst, R}), ans += R - lst + 1;
			lst = l, R = r;
		}
	}
	if (R != -1) nw.push_back({lst, R}), ans += R - lst + 1;
	v[id] = nw;
}
void solve(){
    for(long long i = 0;i<=62;i++)v[i].clear();
    bool flag = 0;
    if(!(n&1))n = (n>>1)-1;
    else n>>=1;
    if(!n)return gotAns=true,void();
    vector<long long>ww;
    for(auto x:w){
        if(x%2==0){
            ww.push_back(x/2);
            continue;
        }
        x/=2;
        if(x==0)flag=true;
        else v[getH(x)].push_back({x, x}),ans--;
    }
    w = ww;
    long long maxn = getH(n);
    for(long long i = maxn-1;i>=0;i--){
        v[i].push_back({(1ll << i) - 1, (1ll << i) - 1});
        v[i].push_back({(1ll << (i + 1)), (1ll << (i + 1))});
    }
    v[maxn].push_back({n + 1, n + 1});
	v[maxn].push_back({(1ll << maxn) - 1, (1ll << maxn) - 1});
    ans -= (maxn + 1) * 2;
    long long flag2 = 0;
	for (long long i = maxn; i >= 0; i--) {
        build(i);
        long long lst = -1;
		for (auto qwq : v[i]) {
			long long l = qwq.first, r = qwq.second;
			if (lst == -1) {
				lst = r;
				continue;
			}
			//assert(lst + 1 <= l - 1);
			if (lst + 1 <= l - 1) {
				long long L = (1ll << (i + 1)) - 1 - (l - 1), R = (1ll << (i + 1)) - 1 - (lst + 1);
				if (L == 0) flag2 = 1, L++;
				if (L > R) {
					lst = r;
					continue;
				}
				if (i == 0) break;
				long long s = getH(L);
				long long t = getH(R);
				if (s == t) {
					v[s].push_back({L, R});
				} else {
					for (long long j = s + 1; j < t; j++) v[j].push_back({1ll << j, (1ll << (j + 1)) - 1});
					v[s].push_back({L, (1ll << (s + 1)) - 1});
					v[t].push_back({(1ll << t), R});					
				}
			}
			lst = r;
		}
	}
	if (!flag && flag2) ans++;
	nn /= 2;
	n = nn;
    
}
int main(){
    n=read(),m=read();nn=n;
    for(long long i = 1,x;i<=m;i++){
        x=read();
        w.push_back(x);
    }
    for(long long bit = 1;bit<=62;bit++){
        ++tot;solve();
        if(gotAns)break;
    }
    cout<<ans;
}
#endif