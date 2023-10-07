#include<iostream>
using namespace std;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int a[30000005];
void Gen(int n, unsigned s1, unsigned s2, unsigned s3) {
    for(int i = 1; i <= n; ++i) {
    s1 ^= s3;
    s3 += 3055373123u;
    a[i] = (1 << ((s1 >> s2) & 1));
    s2 = (s2 ^ s3) & 31;
    s3 = (s3 >> s2) | ((s3 << (31 ^ s2)) << 1);
    }
}
/* int main(){
    freopen("bloom.in","r",stdin);
    freopen("bloom.out","w",stdout);
    long long n=read(),s1=read(),s2=read(),s3=read();
    Gen(n,s1,s2,s3);
    int killed = 0,pPre=1, pNow=2, pSub=3, pNex = 4,ans=0;
    while(killed<n){
        int minNum = min(a[pPre],min(a[pNow]/2,a[pSub]));
        if(minNum){
            a[pPre]-=minNum;
            a[pNow]-=minNum*2;
            a[pNow]-=minNum;
        }else{
            minNum = min(a[pPre]/2,a[pNow]);
            a[pPre]-=minNum*2;
            a[pNow]-=minNum;
        }
        while(!a[pPre]){
            pPre = pNow;
            pNow = pSub;
            pSub = pNex;
            pNex++;
            killed++;
        }while(!a[pNow]){
            pNow = pSub;
            pSub = pNex;
            pNex++;
            killed++;
        }while(!a[pSub]){
            pSub = pNex;
            pNex++;
            killed++;
        }
        ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
} */
int main(){
    /* freopen("bloom.in","r",stdin);
    freopen("bloom.out","w",stdout); */
    long long n=read(),s1=read(),s2=read(),s3=read();
    Gen(n,s1,s2,s3);
    int killed = 0,pPre=1, pNow=2, pSub=3, pNex = 4,ans=0;
    while(killed<n){
        a[pPre]--;
        a[pNow]-=2;
        a[pSub]--;
        while(a[pPre]<=0){
            pPre = pNow;
            pNow = pSub;
            pSub = pNex;
            pNex++;
            killed++;
        }while(a[pNow]<=0){
            pNow = pSub;
            pSub = pNex;
            pNex++;
            killed++;
        }while(a[pSub]<=0){
            pSub = pNex;
            pNex++;
            killed++;
        }
        ans++;
    }
    cout<<ans;
    /* fclose(stdin);
    fclose(stdout); */
    return 0;
}