#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m,tot=0,used=0;
long long ans=0;
struct node{
    int a1;
    int a2;
    int val;
}Edge[200005];
int be[5005];
bool cmp(node a,node b){
    return a.val<b.val;
}
int find(int x){
    return x==be[x]? x:be[x]=find(be[x]);
}
void join(int x,int y){
    be[find(x)]=find(y);
}
void Kruskal(){
    sort(Edge+1,Edge+m+1,cmp);
    for(int i = 1;i<=n;i++){
        be[i]=i;
    }
    for(int i = 1;i<=m;i++){
        if(find(Edge[i].a1)==find(Edge[i].a2))continue;
        else{
            join(Edge[i].a1,Edge[i].a2);
            ans+=Edge[i].val;
            used++;
        }     
    }
}
int main(){
    n=read(),m=read();
    for(int i = 1;i<=m;i++){
        Edge[i].a1=read(),Edge[i].a2=read(),Edge[i].val=read();
    }
    Kruskal();
    if(used==n-1)cout<<ans;
    else cout<<"orz";
    return 0;
}