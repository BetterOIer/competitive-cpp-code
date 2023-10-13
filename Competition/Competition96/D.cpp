#include<iostream>
#include<cstdlib>
using namespace std;
int tot=0;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
long long getAns(long long num){
    for(long long i = num-2;i>=1;i--){
        if(i*i%num==1)return i;
    }
    return 0;
}
int main(){
    long long t=read();
    while(t--){
        long long n=read();
        cout<<getAns(n)<<endl;
    }
    return 0;
}