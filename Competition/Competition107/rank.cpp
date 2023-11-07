#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,k,rnd;
long long pgs[505][65];
long long rnk[505][505];
long long scr[505];
struct node{long long scr,id;}tScr[505];
bool operator <(const node a,const node b){
    if(a.scr==b.scr)return a.id<b.id;
    return a.scr>b.scr;
}
int main(){
    #ifndef LOCAL
    freopen("rank.in","r",stdin);
    freopen("rank.out","w",stdout);
    #else
    freopen("rank/ex_rank4.in","r",stdin);
    freopen("rank/ex_rank4.out","w",stdout);
    #endif
    long long t = clock();
    n=read(),k=read();
    for(long long i = 1;i<=n;i++)for(long long j = 0;j<=k;j++) pgs[i][j]=read();
    for(long long i = 1;i<=n;i++)scr[i]=pgs[i][0];
    rnd= k==1? 1:(k==2? 2:(k==3? 6:(k==4? 12:(k==5? 60:0))));
    long long tmpPro[6];
    for(long long whi = 1;whi<=n;whi++){
        for(long long i = 1;i<=k;i++)tmpPro[i]=pgs[whi][i];
        for(long long i = 1,cnt=2*i;i<=k;i++,cnt=2*i){
            while(cnt<=rnd){
                pgs[whi][cnt]+=tmpPro[i];
                cnt+=i;
            }
        }
    }
    for(long long i = 1;i<=n;i++)tScr[i].id=i,tScr[i].scr=scr[i];
    sort(tScr+1,tScr+n+1);long long tmp=1;
    for(long long i = 1;i<=n;i++){
        if(tScr[i].scr!=tScr[i-1].scr)tmp=i;
        rnk[tScr[i].id][tmp]++;
    }
    long long day=1;
    while(clock()-t<=1950){
        for(long long i = 1;i<=n;i++)scr[i]+=pgs[i][(day-1)%rnd+1],tScr[i].id=i,tScr[i].scr=scr[i];
        sort(tScr+1,tScr+n+1);long long tmp=1;
        if(clock()-t<=1950)for(long long i = 1;i<=n;i++){
            if(tScr[i].scr!=tScr[i-1].scr)tmp=i;
            rnk[tScr[i].id][tmp]++;
        }
        else for(long long i = 1;i<=n;i++)rnk[tScr[i].id][i]=-1;
        day++;
    }
    for(long long i = 1;i<=n;i++)for(long long j = 1;j<=n;j++)cout<<rnk[i][j]<<" \n"[j==n];
    return 0;
}