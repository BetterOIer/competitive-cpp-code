#include<iostream>
#include<vector>
using namespace std;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
long long n,q,sum;
long long val[100005];
vector<long long>ro[100005];

long long qpow(long long a,long long b,int v){
    long long res=1;
    while(b){
        if(b&1) res=1ll*res*a;
        a=1ll*a*a;
        b>>=1;
    }
    return res;
}
void calCtrb(long long pos,long long fa,long long v,long long p,long long d){
    for(auto i:ro[pos]){
        if(i==fa)continue;
        calCtrb(i,pos,v,p,d+1);
    }
    long long add =v;
    while(add&&d--) add/=p;
    val[pos]+=add;sum+=add;
}
void addMkt(long long pos,long long v,long long p){
    calCtrb(pos,0,v,p,0);
}

long long calAns(long long pos,long long fa){
    long long ans= 0;
    for(auto i:ro[pos]){
        if(i==fa)continue;
        ans+=calAns(i,pos);
    }
    return ans+val[pos];
}
void calVal(long long u,long long v){
    long long 
    ans1 = calAns(u,v),
    ans2 = sum-ans1;
    cout<<ans1<<" "<<ans2<<endl;
}
int main(){
    freopen("street.in","r",stdin);
    freopen("street.out","w",stdout);
    n=read(),q=read();
    for(long long i = 1,u,v;i<n;i++){
        u=read(),v=read();
        ro[u].push_back(v);
        ro[v].push_back(u);
    }
    for(long long i = 1,opt,u,w,p,v;i<=q;i++){
        opt=read(),u=read();
        if(opt&1){
            w=read(),p=read();
            addMkt(u,w,p);
        }else{
            v=read();
            calVal(u,v);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}