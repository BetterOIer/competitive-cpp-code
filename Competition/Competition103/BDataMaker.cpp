#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<random>
#include<chrono>
#include<algorithm>
#include<assert.h>

using namespace std;

inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
mt19937_64  engll(chrono::steady_clock::now().time_since_epoch().count());
mt19937  engi(chrono::steady_clock::now().time_since_epoch().count());
/* mt19937_64  engll(1);
mt19937  engi(1); */
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
vector<int> ro[2000005];

int main(int argc,char* argv[]){
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int cases = atoi(argv[3]);
    int t = atoi(argv[4]);
    /* int n = 18;
    int m = 20;
    int cases = 0;
    int t = 0; */

    vector<int>fa(n);
    for(int i = 1;i<n;i++){
        fa[i] = tRandi(0,i-1,t);
        ro[fa[i]].push_back(i);
        ro[i].push_back(fa[i]);
    }

    vector<int>id(n);
    for(int i = 0;i<n;i++)id[i]=i+1;
    shuffle(id.begin(),id.end(),engi);

    struct EDGE{int a,b;};
    vector<EDGE>edge;

    for(int i = 1;i<n;i++){
        int fat = id[fa[i]],pos=id[i];
        /* if(randi()>0)swap(fat,pos); */ //让父亲只能到儿子
        edge.push_back((EDGE){fat,pos});
    }
    int mleft = m-edge.size();
    if((!cases)&&mleft>=2){
        int pos = randi(0,n-1);
        while(ro[fa[pos]].size()<=2)pos = randi(0,n-1);
        int pos2  = ro[fa[pos]][randi(0,ro[fa[pos]].size()-1)];
        while(pos2==fa[fa[pos]]||pos2==pos)pos2  = ro[fa[pos]][randi(0,ro[fa[pos]].size()-1)];
        edge.push_back((EDGE){id[pos],id[pos]});
        edge.push_back((EDGE){id[pos2],id[pos2]});
    }
    mleft = m-edge.size();
    if(cases){
        for(int i = 1;i<=mleft/4;i++){
            int pos = randi(0,n-1);
            int pos2 = ro[pos][ro[pos].size()-1];
            edge.push_back((EDGE){id[pos],id[pos]});
            edge.push_back((EDGE){id[pos2],id[pos2]});
        }
        int pos1 = randi(0,n-1);
        while(ro[pos1].size()<3)pos1 = randi(0,n-1);
        int cnt = 0;
        int pos2 = ro[pos1][cnt++];if(pos2==fa[pos1])pos2 = ro[pos1][cnt++];
        int pos3 = ro[pos1][cnt++];if(pos3==fa[pos1])pos3 = ro[pos1][cnt++];
        edge.push_back((EDGE){id[pos2],id[pos3]});
        edge.push_back((EDGE){id[pos3],id[pos1]});
    }
    while(int(edge.size())<m){
        int pos = randi(0,edge.size()-1);
        while(edge[pos].a==edge[pos].b)pos = randi(0,edge.size()-1);
        edge.push_back(edge[pos]);
    }
    assert(int(edge.size())==m);
    shuffle(edge.begin(),edge.end(),engi);
    #ifdef IOFILE
    fout<<n<<"\n";
    for(EDGE i:edge){
        fout<<i.a<<" "<<i.b<<"\n";
    }
    #endif
    #ifndef IOFILE
    printf("%d %d\n",n,m);
    for(EDGE i:edge){
        printf("%d %d\n",i.a,i.b);
    }
    #endif
    return 0;
}