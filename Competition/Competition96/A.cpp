#include<bits/stdc++.h>
#define maxn 100010
using namespace std;
typedef long long ll;
ll ans,n,m,x,a[maxn],tot,num;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
//	freopen("1.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x%2==0)a[++tot]=x;
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>x;
		if(x%2==1)num++; 
	}
	sort(a+1,a+1+tot,cmp);
//	for(int i=1;i<=tot;i++)
//		cout<<a[i]<<" ";
//	cout<<endl;
	for(int i=num+1;i<=tot;i++)ans+=a[i];
	cout<<ans<<endl;
	return 0;
}