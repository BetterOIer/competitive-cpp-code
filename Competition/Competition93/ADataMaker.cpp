/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<chrono>
#include<random>
#include<iostream>
#include<algorithm>
#include<assert.h>
using namespace std;
mt19937_64  engll(chrono::steady_clock::now().time_since_epoch().count());
mt19937  engi(chrono::steady_clock::now().time_since_epoch().count());
long long randll(long long l=LLONG_MIN,long long r=LLONG_MAX){
    /* generate a random number from [l,r] */
    if(l>r)swap(l,r);
    uniform_int_distribution<long long> rnd(l,r);
    return rnd(engll);
}
long long tRandll(long long l=LLONG_MIN,long long r=LLONG_MAX,long long t=0){
    /* random abs(t)+1 times and get the max(opposite)/min(negtive) value from [l,r], */
    if(l>r)swap(l,r);
    uniform_int_distribution<long long> rnd(l,r);
    long long ans;
    if(t>=0){
        ans = l;
        for(long long i = 1;i<=t+1;i++){
            ans=max((long long)rnd(engll),ans);
        }
    }else{
        t = abs(t);
        ans = r;
        for(long long i = 1;i<=t+1;i++){
            ans=min((long long)rnd(engll),ans);
        }
    }
    return ans;
}
int randi(int l=INT32_MIN,int r=INT32_MAX){
    /* generate a random number from [l,r] */
    if(l>r)swap(l,r);
    uniform_int_distribution<int> rnd(l,r);
    return rnd(engi);
}
int tRandi(int l=INT32_MIN,int r=INT32_MAX,int t=0){
    /* random abs(t)+1 times and get the max(opposite)/min(negtive) value from [l,r], */
    if(l>r)swap(l,r);
    uniform_int_distribution<int> rnd(l,r);
    int ans;
    if(t>=0){
        ans = l;
        for(int i = 1;i<=t+1;i++){
            ans=max((int)rnd(engi),ans);
        }
    }else{
        t = abs(t);
        ans = r;
        for(int i = 1;i<=t+1;i++){
            ans=min((int)rnd(engi),ans);
        }
    }
    return ans;
}
int main(int argc,char* argv[]){
    int maxn = 1000000;
    int t = atoi(argv[1]);
    printf("%d\n",t);
    int l1 = atoi(argv[2]);
    int r1 = atoi(argv[3]);
    int l2 = atoi(argv[4]);
    int r2 = atoi(argv[5]);
    while(t--){
        int n = randi(l1,r1);
        maxn-=n;
        printf("%d\n",n);
        for(int i = 1,x;i<=n;i++){
            x=tRandi(l2,r2,1);
            printf("%d ",x);

        }
        printf("\n");
    }
    assert(maxn>=0);
}