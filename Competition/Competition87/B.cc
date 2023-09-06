#include<iostream>
#include<vector>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
struct node{
    long long s;
    long long k;
    int r;
    vector<int>son;
}mos[200005];
int to[200005];
int n;
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        mos[i].s=read();
        mos[i].k=read();
        mos[i].r=read();
        for(int j = 1,x;j<=mos[i].r;j++){
            x=read();mos[i].son.push_back(x);
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j:mos[i].son){
            to[i]+=mos[j].s;
        }
    }
    return 0;
}