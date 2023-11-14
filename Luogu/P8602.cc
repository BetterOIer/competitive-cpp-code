#include<bits/stdc++.h>
using namespace std;
int hd[101],go[100],nxt[100],cst[100],dis[101],l;
void Add(int u,int v,int t)
{
	nxt[++l]=hd[u],hd[u]=l,go[l]=v,cst[l]=t;
}
void dfs(int s,int f,int d)
{
	dis[s]=d;
	for(int i=hd[s];i;i=nxt[i])
	{
		if(go[i]==f) continue;
		dfs(go[i],s,d+cst[i]);
	}
}
int main()
{
	int n,m,u,v,w,s=1,i;
	cin>>n;m=n-1;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		Add(u,v,w);
		Add(v,u,w);
	}
	dfs(1,0,0);
	for(i=2;i<=n;i++)
	if(dis[s]<dis[i]) s=i;
	dfs(s,0,0);
	for(i=1;i<=n;i++)
	if(dis[s]<dis[i]) s=i;
	printf("%d\n",dis[s]*10+(dis[s]+1)*dis[s]/2);
	return 0;
}