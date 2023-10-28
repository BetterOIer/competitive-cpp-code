/* #include<bits/stdc++.h>
using namespace std;
int n,i,j,a[2000005],st[22][2000005];
long long ans;
void solv(int l,int r){
	if(l>r) return;
	int t=__lg(r-l+1);
	int mid=a[st[t][l]]<a[st[t][r-(1<<t)+1]]?st[t][l]:st[t][r-(1<<t)+1];
	if(mid<=(l+r>>1)) ans+=1ll*(mid-l+1)*(mid-l)/2;
	else ans+=1ll*(mid-l+mid-l-r+mid)*(r-mid+1)/2;
	solv(l,mid-1),solv(mid+1,r);
}
int rd(){
	char c=getchar();
	int s=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') s=s*10+c-48,c=getchar();
	return s;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		a[i]=rd();
		st[0][i]=i;
	}
	for(i=1;i<=20;i++)
	for(j=1;j+(1<<i)-1<=n;j++)
	st[i][j]=a[st[i-1][j]]<a[st[i-1][j+(1<<i-1)]]?st[i-1][j]:st[i-1][j+(1<<i-1)];
	solv(1,n);
	printf("%lld",ans);
	return 0;
} */

#include<bits/stdc++.h>

const int N=2000005;

using namespace std;

int n,a[N],l[N],r[N],st[N],top;
long long ans;

inline int read(){
	int t=1,x=0;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') t=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	return t*x;
}

long long cal(int x){
	return 1ll*x*(x+1)/2;
}

bool cmp(int x,int y){
	return a[x]<a[y]||a[x]==a[y]&&x>y;
}

int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		while(top && cmp(i,st[top])) top--;
		if(top) l[i]=st[top]+1;
		else l[i]=1;
		st[++top]=i;
	}
	top=0;
	for(int i=n;i>=1;i--){
		while(top && cmp(i,st[top])) top--;
		if(top) r[i]=st[top]-1;
		else r[i]=n;
		st[++top]=i;
	}
	for(int i=1;i<=n;++i){
		int ll=i-l[i],rr=r[i]-i;
		ans+=cal(min(ll,rr+1));
		if(ll>rr+1){
			ans+=1ll*(ll-rr-1)*(rr+1);
		}
	}
	cout<<ans;
	return 0;
}