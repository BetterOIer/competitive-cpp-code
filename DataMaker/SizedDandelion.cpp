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

struct EDGE{int a,b;};
vector<EDGE>edge;

void makeTree1(int n,int l,vector<int> id){
    vector<int>fa(n);
    for(int i = 2;i<n;i++){
        fa[i] = i-1;
    }
    edge.push_back((EDGE){id[l],id[0]});
    for(int i = 2;i<n;i++){
        int fat = id[fa[i]+l-1],pos=id[i+l-1];
        if(randi()>0)swap(fat,pos);
        edge.push_back((EDGE){fat,pos});
    }
}
void makeTree2(int n,int l,vector<int> id){
    vector<int>fa(n);
    for(int i = 1;i<n;i++){
        int fat = id[0],pos=id[l+i-1];
        if(randi()>0)swap(fat,pos);
        edge.push_back((EDGE){fat,pos});
    }
}

int main(int argc,char* argv[]){
    int n = atoi(argv[1]);
    int root = atoi(argv[2]);
    int lian = atoi(argv[3]);
    int juhua = n-lian+1;
    #ifdef IOFILE
    ofstream fout;
    fout.open(argv[4]);
    #endif


    vector<int>id(n);
    for(int i = 0;i<n;i++)id[i]=i+1;
    shuffle(id.begin(),id.end(),engi);

    for(int i = 0;i<n;i++){
        if(id[i]==root){
            swap(id[i],id[0]);
            break;
        }
    }
    makeTree1(lian,1,id);
    makeTree2(juhua,lian,id);

    shuffle(edge.begin(),edge.end(),engi);
    #ifdef IOFILE
    fout<<n<<" "<<root<<"\n";
    for(EDGE i:edge){
        fout<<i.a<<" "<<i.b<<"\n";
    }
    #endif
    #ifndef IOFILE
    printf("%d %d\n",n,root);
    for(EDGE i:edge){
        printf("%d %d\n",i.a,i.b);
    }
    #endif
    return 0;
}