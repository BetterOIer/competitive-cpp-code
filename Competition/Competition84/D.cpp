#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int mod1 = 1e9+9;
const int mod2 = 1e9+7;
const int mod = 998244353;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
priority_queue<int,vector<int> > q1;
priority_queue<int,vector<int>,greater<int> > q2;
int p[10000005],a[10000005],p19[10000005]={1},ans=0;
void init(int n,int a0){
    a[0]=a0;
    for(int i = 1;i<=n;i++) a[i] = (((long long)a[i-1]*(long long)mod)%(long long)mod1+(long long)mod2)%(long long)mod1;
    for(int i = 1;i<=n;i++) p[i]=i;
    for(int i = 1;i<=n;i++) swap(p[i],p[a[i]%i+1]);
    for(int i = 1;i<=n;i++) p19[i]=((long long)p19[i-1]*19ll)%mod;
}
int cal(int x,int i){
    return (long long)x*p19[i]%mod;
}
int main(){
    int n=read(),a0=read();
    init(n,a0);
	q1.push(p[1]);
    (ans+=cal(p[1],1))%=mod;
	for (int i=2;i<=n;i++){
		if (p[i]>q1.top()) q2.push(p[i]);
		else q1.push(p[i]);
		while (abs(int(q1.size()-q2.size()))>1){
			if (q1.size()>q2.size()){q2.push(q1.top());q1.pop();}
			else{q1.push(q2.top());q2.pop();}
        }
		if (i%2){
            int ret = q1.size()>q2.size()?q1.top():q2.top();
            (ans+=cal(ret,i))%=mod;
        }
        else{
            (ans+=cal(q1.top(),i))%=mod;
        }
	}
    cout<<ans;
	return 0;
}