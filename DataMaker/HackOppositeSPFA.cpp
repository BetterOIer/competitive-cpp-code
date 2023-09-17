#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<random>
#include<chrono>
#include<algorithm>

#define IOFILE

using namespace std;

inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
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
