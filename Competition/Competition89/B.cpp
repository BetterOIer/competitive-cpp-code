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
namespace Problem1{
    int n,k;
    int main(){
        n=read(),k=read();
        cout<<0<<endl;
        return 0;
    }
    
}
namespace Problem2{
    map<int,int>m;
    int solve(int n){
        int backup=n;
        if(m.find(n)!=m.end())return m[n];
        n-=((int)(log2(n))+1);int ans=-1;
        for(int i = 1;i<31;i++){
            int cnt=qpow(2,i)-1;
            if(n>=cnt)ans*=solve(cnt),n-=cnt;
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
}
int main(){
    int opt=read();
    if(opt&1) Problem1::main();
    else Problem2::main();
    return 0;
}