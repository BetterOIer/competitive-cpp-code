#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<3)+(s<<1)+ch-'0';
        ch=getchar();
    }
    return s*w;
}
int n,a[10000007],p[10000007];
bool cmp(int x,int y){
    return p[x]<p[y];
}
const int mod1=998244353,mod2=1e9+7,mod3=1e9+9;
priority_queue<int,vector<int>,greater<int> >q;
priority_queue<int,vector<int>,less<int> >pp;
long long ans;
long long qpow(long long x,int y){
    long long res=1;
    while(y){
        if(y&1)res*=x,res%=mod1;
        x*=x;
        x%=mod1;
        y>>=1;
    }
    return res;
}
int main(){
    n=read(),a[0]=read();
    for(int i=1;i<=n;i++){
        long long b=(1ll*a[i-1]*mod1%mod3+mod2)%mod3;
        a[i]=(int)b;
        p[i]=i;
    }
    for(int i=1;i<=n;i++){
        swap(p[i],p[(a[i]%i)+1]);
    }
    for(int i=1;i<=n;i++){
        int k=(i+1)/2;
        q.push(p[i]);
        pp.push(q.top());
        q.pop();
        while(q.size()<k){
            int t=pp.top();
            pp.pop();
            q.push(t);
        }
        ans+=1ll*q.top()*qpow(19,i)%mod1;
        ans%=mod1;
    }
    cout<<ans;
}