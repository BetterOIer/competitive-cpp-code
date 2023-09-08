#include<iostream>
using namespace std;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
long long a[1000005],k;
bool isLucky(long long x){
    long long temp=0;
    while(x){
        if((temp>>(x%10))&1){
            return false;
        }
        temp+=1LL<<(x%10);
        x/=10;
    }
    return true;
}
void getArr(long long n){
    for(long long i = 1;i<=n;i++){
        if(isLucky(i)){
            a[i]=++k;
        }
        else a[i]==0;
    }
}
int main(){
    long long q=read(),n=read();
    getArr(n);
    for(long long i = 1;i<=q;i++){
        long long x=read();
        if(!a[x]){
            printf("not exist!\n");
        }else{
            printf("%lld\n",a[x]);
        }
    }
    return 0;
}