#include<bits/stdc++.h>
using namespace std;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
long long gcd(long long x,long long y){
    while(y^=x^=y^=x%=y);
    return x;
}
inline long long ksc(unsigned long long x, unsigned long long y, unsigned long long p){  
    return(x * y -(unsigned long long)((long double)x / p * y) * p + p) % p;
}
inline long long ksm(long long x, long long y, long long p){  
    long long res=1;
    while(y){
        if(y&1) res=ksc(res, x, p);
        x=ksc(x, x, p);
        y >>= 1;
    }
    return res;
}

inline bool mr(long long x, long long p){              
    if(ksm(x, p-1, p)!=1) return 0;  
    long long y=p-1, z;
    while(!(y&1)){  
        y >>= 1;
        z=ksm(x, y, p);
        if(z!=1&&z!=p-1) return 0;
        if(z==p-1) return 1;
    }
    return 1;
}
inline bool prime(long long x){
    if(x<2) return 0;  
    if(x==2||x==3||x==5||x==7||x==43) return 1;
    return mr(2, x)&&mr(3, x)&&mr(5, x)&&mr(7, x)&&mr(43, x);
}
inline long long rho(long long p){  
    long long x, y, z, c, g;
    long long i, j;                 
    while(1){              
        y=x=rand() % p;  
        z=1;
        c=rand() % p;                  
        i=0, j=1;                    
        while(++i){                    
            x =(ksc(x, x, p) + c) % p;  
            z=ksc(z, abs(y-x), p);  
            if(x==y||!z)
                break;  
            if(!(i % 127)||i==j){  
                g=gcd(z, p);
                if(g > 1) return g;
                if(i==j)
                    y=x, j <<= 1;  
            }
        }
    }
}

long long x,p,n,a,b,c;
bool valid=true;
bool solve(){
	for(a=1;a<=5;a++){
		for(b=a;a*b<n;b++){
			if((n-a*b)%(a+b)==0){
				c=(n-a*b)/(a+b);
                return true;
			}
		}
	}
	return false;
}

int main(){
	srand(time(0));
    long long t=read();
	while(t--){
        x=read(),p=read();n=x*p*p;valid=true;
		if(x+1>p){
			a=p,b=x+1-p,c=p*p-p;
		}else if(!prime(x+1)){
			long long cnt=rho(x+1);
			a=p,b=(cnt-1)*p,c =((x+1)/cnt-1)*p;
		}else if(x+1==p){
			if(n<=18)valid=solve();
			else a=6LL,b=p-3LL, c=p*p-4LL*p+6LL;
		}else{
			long long g =(x+1),k=p/g,r=p-k*g;
			a=r,b=g-r, c=k*k*g*(g-1LL)+2LL*k*r*(g-1LL)+r*r-r;
		}
		if(valid)printf("%lld %lld %lld\n",a,b,c);
		else printf("-1\n");
	}
	return 0;
}