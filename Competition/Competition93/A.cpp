#include<iostream>
using namespace std;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
long long a[1000005];
long long rerNegNum[1000005];
int main(){
    long long t=read();
    while(t--){
        long long n=read(),lBegin=1,rBegin=n,pos=1,lstNegNum=n+1;
        a[n+1]=-1;
        for(long long i =1;i<=n;i++) a[i]=read();
        for(long long i =n;i>=1;i--){
            rerNegNum[i]=lstNegNum;
            if(a[i]<0)lstNegNum=i;
        }
        bool flag=!(n==1&&a[1]<0);
        while(flag&&lBegin<rBegin&&lstNegNum!=n+1){
            if(a[pos]<0) {flag=false;break;}
            for(;a[pos]>=0&&(pos-lBegin+1)*2+lBegin-1<=lstNegNum;pos++);
            for(long long i = lBegin;i<=pos-1;i++){
                a[lBegin+2*(pos-lBegin)-i+lBegin-1]+=a[i];
            }
            lBegin=pos;
            while(a[lstNegNum]>=0)lstNegNum=rerNegNum[lstNegNum];
        }
        if(a[lBegin]>=0&&flag) puts("1");
        else puts("0");
    }
    return 0;
}