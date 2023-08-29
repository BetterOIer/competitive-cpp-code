#include<bits/stdc++.h>
using namespace std;
struct node { int t,v,op,next; }a[4000010];

vector<int> h[500010];
stack<int> st;

int head[500010],dfn[500010],low[500010],n,m,cl,cnt,tot;

inline int rd(){
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void add(int x,int y){
	a[++tot].t=y;a[tot].op=tot+1;a[tot].next=head[x];head[x]=tot;
	a[++tot].t=x;a[tot].op=tot-1;a[tot].next=head[y];head[y]=tot;
}

inline void dfs(int x,int y){
	dfn[x]=low[x]=++cl;st.push(x);
	bool flag=false;
	for (int i=head[x];i;i=a[i].next){
		int t=a[i].t;
		if (!dfn[t]){
			dfs(t,a[i].op);
			low[x]=min(low[x],low[t]);
			if (low[t]>=dfn[x]){
				cnt++;
				h[cnt].push_back(x);
				while (233){
					int hh=st.top();st.pop();
					h[cnt].push_back(hh);
					if (hh==t) break;
				}
			}
			flag=true;
		}
		else if (i!=y) low[x]=min(low[x],dfn[t]);
	}
	if (!y){
		if (!flag) h[++cnt].push_back(x);
		st.pop();
	}
}

int main(){
	n=rd();m=rd();
	for (int i=1;i<=m;i++){
		int x=rd(),y=rd();
		add(x,y);
	}
	for (int i=1;i<=n;i++) if (!dfn[i]) dfs(i,0);
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++){
		printf("%d ",h[i].size());
		for (int t:h[i]) printf("%d ",t);
		putchar('\n');
	}
	return 0;
}