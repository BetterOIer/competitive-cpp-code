#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int num,n,m,curA=0;
int a[100005],b[100005];
int timTag[100005];
long long busyB[100005];
int allFinTim=0;
struct node{
    int id;
    int finB;
};
bool operator < (node a,node b){
    return a.finB<b.finB;
}
vector<node>finBTim;
long long calA(long long tim){
    long long ans=0;
    for(int i = 1;i<=n;i++){
        ans+=(long long)tim/a[i];
    }
    return ans;
}
long long searchA(long long l,long long r){
    while(l<=r){
        long long mid = (l+r)>>1;
        long long finNum = calA(mid);
        if(finNum<num)l = mid+1;
        else r = mid-1;
    }
    return r+1;
}
void searchB(int curA,int getTim){
    if(!curA)return ;
    finBTim.clear();
    for(int i = 1,leiB;i<=m;i++){
        if(getTim>busyB[i]){
            leiB=getTim;
        }else{
            leiB=busyB[i];
        }
        finBTim.push_back((node){i,leiB+b[i]});
    }
    sort(finBTim.begin(),finBTim.end());
    for(node i:finBTim){
        busyB[i.id] = i.finB;
        allFinTim=max(allFinTim,i.finB);
        curA--;
        if(!curA)break;
    }
}
int main(){
    num=read(),n=read(),m=read();
    for(int i = 1;i<=n;i++) a[i]=read();
    for(int i = 1;i<=m;i++) b[i]=read();
    long long finA = searchA(1,(long long)1e18);
    for(int i  =1;i<=n;i++){
        for(int j = a[i];j<=finA;j+=a[i]){
            timTag[j]++;
        }
    }
    for(int i = 1;i<=finA;i++){
        curA=timTag[i];
        searchB(curA,i);
    }
    cout<<allFinTim<<endl;
    return 0;
}