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
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
long long n,m,a[5000010],ans,pos[5000010],v;
bool done[5000010][2];
long long tou,wei,dp[5000010][2],las,tpos,top,now,mex;
struct node{
	long long pos,op;
};
bool operator <(node n1,node n2){
	return dp[n1.pos][n1.op]>dp[n2.pos][n2.op];
}
priority_queue<node>h;
long long rotate(long long x,long long y){
	if(x>y)swap(x,y);
	return min(y-x,x+n-y);
}
bool chkPos(long long pos,long long x,long long y){
	if(x<y) return (pos>=x&&pos<=y);
    return (pos<=y||pos>=x);
}
int main(){
	freopen("arrange.in","r",stdin);
	freopen("arrange.out","w",stdout);
	n=read(),m=read();
	for(long long i=1;i<=n;i++)a[i]=read(),pos[a[i]]=i;
	for(long long i=n+1;i<=2*n;i++)a[i]=a[i-n];
	now=n+1;
	for(long long i=1;i<=n;i++)
		if(pos[i]>m){
			now=i;
			break;
		}
	if(now==n+1){
		cout<<0<<endl;
		return 0; 
	}
	dp[now][0]=rotate(1,pos[now]);
	dp[now][1]=rotate(m,pos[now]);
	h.push(node{now,0});h.push(node{now,1});
	for(long long i=now+1;i<=n;i++) dp[i][0]=dp[i][1]=1145141919810;
	ans=1145141919810;
	while(h.size()){
		top=h.top().op;tpos=h.top().pos;h.pop();
		if(tpos==n+1)continue;
		if(done[tpos][top])continue;
		done[tpos][top]=1;
		if(top==0){
			tou=pos[tpos];
            wei=tou+m-1;
            if(wei>n) wei-=n;
			mex=tpos+1;
			while(chkPos(pos[mex],tou,wei)&&mex<=n) mex++;
			if(mex==n+1) ans=min(ans,dp[tpos][top]);
			else{
				dp[mex][0]=min(dp[mex][0],dp[tpos][0]+rotate(tou,pos[mex]));
				dp[mex][1]=min(dp[mex][1],dp[tpos][0]+rotate(wei,pos[mex]));
				h.push(node{mex,0});
                h.push(node{mex,1});	
			}
		}else{
			tou=pos[tpos]-m+1;
            wei=pos[tpos];
            if(tou<=0) tou+=n;
			mex=tpos+1;
			while(chkPos(pos[mex],tou,wei)&&mex<=n) mex++;
			if(mex==n+1) ans=min(ans,dp[tpos][top]);
			else{
				dp[mex][0]=min(dp[mex][0],dp[tpos][1]+rotate(tou,pos[mex]));
				dp[mex][1]=min(dp[mex][1],dp[tpos][1]+rotate(wei,pos[mex]));
				h.push(node{mex,0});
                h.push(node{mex,1});
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}