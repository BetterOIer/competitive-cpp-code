#include<iostream>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
int fa[55];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
char s[55][55];
vector<int> to[55];
int ok[3],ans[3];
int w[55];
int ind[55],oud[55];
int cmp(int x,int y){
	return x>y?0:x==y?1:2;
}
bool check(){
	for(int i=1;i<=n;++i)if(w[i]){
		if(!w[find(i)])w[find(i)]=w[i];
		else if(w[find(i)]!=w[i])return 0;
	}
	for(int i=1;i<=n;++i)if(find(i)==i&&!w[i]&&!ind[i])w[i]=1;
	for(int i=1;i<=n;++i)if(find(i)==i&&!w[i]&&!oud[i])w[i]=3;
	for(int i=1;i<=n;++i)if(find(i)==i&&!w[i])w[i]=2;
	for(int i=1;i<=n;++i)for(auto j:to[i])if(w[j]<=w[i])return 0;
	return 1;
}
int main(){
    #ifndef LOCAL
    freopen("alittletoo.in","r",stdin);
    freopen("alittletoo.out","w",stdout);
    #else
    freopen("B/ex_B3.in","r",stdin);
    freopen("B/ex_B3.out","w",stdout);
    #endif
    n=read();
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(s[i][j]=='=')fa[find(i)]=find(j);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(s[i][j]=='+'){
		to[find(j)].push_back(find(i));
		++ind[find(i)];++oud[find(j)];
	}
	int x,y;
	x=read(),y=read();
	for(int i=1;i<=n;++i)if(i!=x&&i!=y)
		for(int j=i+1;j<=n;++j)if(j!=x&&j!=y){
			ok[0]=ok[1]=ok[2]=0;
			for(int a1=1;a1<=3;++a1)for(int a2=1;a2<=3;++a2)for(int a3=1;a3<=3;++a3)for(int a4=1;a4<=3;++a4){
				for(int k=1;k<=n;++k)w[k]=0;
				w[x]=a1;w[y]=a2;w[i]=a3;w[j]=a4;
				if(check()){
					ok[cmp(a1+a2,a3+a4)]=1;
				}
			}
			if(ok[0]+ok[1]+ok[2]==1){
				for(int j=0;j<=2;++j)ans[j]+=ok[j];
			}
		}
	for(int i=0;i<=2;++i)printf("%d\n",ans[i]);
    return 0;
}