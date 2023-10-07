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
int main(){
    freopen("bloom.in","r",stdin);
    freopen("bloom.out","w",stdout);
    long long n=read(),s1=read(),s2=read(),s3=read();
    Gen(n,s1,s2,s3);
    int killed = 0,pPre=1, pNow=2, pSub=3, pNex = 4,ans=0,minWhi;
    while(killed<n){
        ans++;
        if(a[pPre]==1&&a[pNow]==1&&a[pSub]==1)minWhi = 2;
        else if(a[pPre]==1&&a[pNow]==1&&a[pSub]==2)minWhi = 2;
        else if(a[pPre]==1&&a[pNow]==2&&a[pSub]==1)minWhi = 2;
        else if(a[pPre]==2&&a[pNow]==1&&a[pSub]==1)minWhi = 1;
        else if(a[pPre]==1&&a[pNow]==2&&a[pSub]==2)minWhi = 2;
        else if(a[pPre]==2&&a[pNow]==2&&a[pSub]==1)minWhi = 2;
        else if(a[pPre]==2&&a[pNow]==1&&a[pSub]==2)minWhi = 1;
        else if(a[pPre]==2&&a[pNow]==2&&a[pSub]==2)minWhi = 2;
        if(minWhi==1){
            a[pPre]-=2;
            a[pNow]--;
        }else{
            a[pPre]--;
            a[pNow]-=2;
            a[pSub]--;
        }
        while(a[pPre]<=0){
            pPre = pNow;
            pNow = pSub;
            pSub = pNex;
            if(!a[pNex])goto en;
            pNex++;
            killed++;
        }while(a[pNow]<=0){
            pNow = pSub;
            pSub = pNex;
            if(!a[pNex])goto en;
            pNex++;
            killed++;
        }while(a[pSub]<=0){
            pSub = pNex;
            if(!a[pNex])goto en;
            pNex++;
            killed++;
        }
    }
    en:
    if(a[pPre]==1&&a[pNow]==1)ans+=1;
    else if(a[pPre]==1&&a[pNow]==2)ans+=1;
    else if(a[pPre]==2&&a[pNow]==1)ans+=1;
    else if(a[pPre]==2&&a[pNow]==2)ans+=2;
    else if(a[pPre]==1&&a[pNow]<=0)ans+=1;
    else if(a[pPre]==2&&a[pNow]<=0)ans+=1;
    else if(a[pPre]<=0&&a[pNow]==1)ans+=1;
    else if(a[pPre]<=0&&a[pNow]==2)ans+=1;
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}