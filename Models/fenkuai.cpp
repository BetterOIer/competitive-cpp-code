#include<iostream>
#define int long long
using namespace std;
long long a[1000005],tot;
struct node{
    long long sum=0;
    long long add;
    int l,r;
}sum[3005];
int rev[1000005];
void add(int x,int y,int data){
    int ll=sum[rev[x]].l==x?rev[x]:rev[x]+1,rr=sum[rev[y]].r==y?rev[y]:rev[y]-1;
    for(int j= ll;j<=rr;j++){
        sum[j].add+=data;
    }
    for(int i = x;i<=sum[ll-1].r;i++){
        a[i]+=data;
        sum[ll-1].sum+=data;
    }
    for(int i = sum[rr+1].l;i<=y;i++){
        a[i]+=data;
        sum[rr+1].sum+=data;
    }
}
long long query(int x,int y){
    long long ans=0;
    int ll=sum[rev[x]].l==x?rev[x]:rev[x]+1;
    int rr=sum[rev[y]].r==y?rev[y]:rev[y]-1;
    for(int j= ll;j<=rr;j++){
        ans=ans+(sum[j].r-sum[j].l+1)*sum[j].add+sum[j].sum;
    }
    for(int i = x;i<=sum[ll-1].r;i++){
        ans=ans+a[i]+sum[ll-1].add;
    }
    for(int i = sum[rr+1].l;i<=y;i++){
        ans=ans+a[i]+sum[rr+1].add;
    }
    return ans;
}
signed main(){
    int n,m,t;
    cin>>n>>m;
    t=__builtin_sqrt(n);
    for(int i = 1;i<=n;i++){
        scanf("%lld",a+i);
        if(i%t==1){
            sum[++tot].add=0;
            sum[tot].l=i;
            sum[tot-1].r=i-1;
        }
        sum[tot].sum+=a[i];
        rev[i]=tot;
    }
    sum[tot].r=n;
    sum[tot+1].l=n+1;
    for(int i = 1;i<=m;i++){
        int opt,x,y,z;
        cin>>opt>>x>>y;
        if(opt==1){
            cin>>z;
            add(x,y,z);
        }else if(opt==2){
            cout<<query(x,y)<<endl;
        }
    }
}