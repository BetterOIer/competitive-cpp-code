#include<iostream>
#include<map>
#include<cmath>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int qpow(int a,int b){
    int res=1;
    while(b){
        if(b&1)res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
map<int,int>m;
int solve(int n){
    int backup=n;
    if(m.find(n)!=m.end())return m[n];
    /* cout<<"solve "<<backup<<endl; */
    n-=((int)(log2(n))+1);int ans=-1;
    /* cout<<n<<endl; */
    for(int i = 1;i<31;i++){
        int cnt=qpow(2,i)-1;
        if(n>=cnt){/* cout<<cnt<<" "<<n<<endl; */ans*=solve(cnt),n-=cnt;}
        else break;
    }
    ans*=solve(n);
    return m[backup]=ans;
}
int main(){
    m[1]=-1,m[2]=1,m[0]=1;
    int t=read();
    while(t--){
        int n=read();int ans=solve(n);
        cout<<(ans==1? "ysgh\n":"cqz\n");
    }
    return 0;
}