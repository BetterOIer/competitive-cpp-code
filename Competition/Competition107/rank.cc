#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,k,rnd;
int pgs[505][65];
int rnk[505][505];
int scr[505];
int main(){
    int t = clock();
    n=read(),k=read();
    for(int i = 1;i<=n;i++)for(int j = 0;j<=k;j++) pgs[i][j]=read();
    rnd= k==1? 1:(k==2? 2:(k==3? 6:(k==4? 12:(k==5? 60:0))));
    for(int whi = 1;whi<=n;whi++)for(int i = 1,cnt=2*i;i<=k;i++,cnt=2*i){
        while(cnt<rnd){
            pgs[whi][cnt]+=pgs[whi][i];
        }
    }
    memset(rnk,-1,sizeof rnk);
    while(clock()-t<=1800){

    }
    return 0;
}