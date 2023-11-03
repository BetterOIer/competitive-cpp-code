#include<bits/stdc++.h>
using namespace std;
#define N 100125
int n=100000,m,x,y,i,j;
bool vis[N][10];
vector<int> G[N],G2[N],Q[N],dis1[N],dis2[N];
void init(){
	for(i=1;i<=n+82;i++){
		memcpy(vis[i],vis[i/10],sizeof(vis[i]));
		if(i%10) vis[i][i%10]=1;
		for(j=1;j<10;j++)
		if(vis[i][j]){
			if(i+j<=n+82) G[i].emplace_back(i+j),G2[i+j].emplace_back(i);
			G[i].emplace_back(i-j),G2[i-j].emplace_back(i);
		}
	}
}
int ans;
int q[N],L,R;
void bfs1(int s,int l,int r){
	dis1[s].resize(r-l+1,1<<29);
	dis1[s][(q[L=R=1]=s)-l]=0;
	while(L<=R){
		for(auto j:G[q[L]]) if(j>=l&&j<=r&&dis1[s][j-l]>dis1[s][q[L]-l]+1) q[++R]=j,dis1[s][j-l]=dis1[s][q[L]-l]+1;
		L++;
	}
}
void bfs2(int s,int l,int r){
	dis2[s].resize(r-l+1,1<<29);
	dis2[s][(q[L=R=1]=s)-l]=0;
	while(L<=R){
		for(auto j:G2[q[L]]) if(j>=l&&j<=r&&dis2[s][j-l]>dis2[s][q[L]-l]+1) q[++R]=j,dis2[s][j-l]=dis2[s][q[L]-l]+1;
		L++;
	}
}
void solv(int l,int r){
	if(l>r) return;
	int mid=l+r>>1;
	solv(l,mid-5),solv(mid+5,r);
	for(i=max(mid-4,l);i<=mid+4&&i<=r;i++)
	bfs1(i,max(l-82,0),r+82),bfs2(i,max(l-82,0),r+82);
}
void ins(int l,int r){
	int mid=l+r>>1;
	if(1ll*(min(x,y)-mid-4)*(max(x,y)-mid+4)<=0){
		for(i=max(mid-4,l);i<=mid+4&&i<=r;i++)
		ans=min(ans,dis1[i][y-max(l-82,0)]+dis2[i][x-max(l-82,0)]);
		return;
	}
	if(y<mid) ins(l,mid-5);
	else ins(mid+5,r);
}
int main(int argc,char *argv[]){
    freopen(argv[1],"r",stdin);
    freopen(argv[2],"w",stdout);
	init();
	scanf("%d",&m);
	solv(0,n);
	while(m--){
		scanf("%d%d",&x,&y);
		x^=ans+1,y^=ans+1;
		ans=1<<30,ins(0,n);
		if(ans>>25) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}