#include<iostream>
#include<map>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n;
int a[100005];
int ans=0;
map<int,int>M;
/* bool operator < (pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
} */
int main(){
    freopen("watermelon.in","r",stdin);
    freopen("watermelon.out","w",stdout);
    n=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
        if(!M[a[i]])M[a[i]]=0;
        M[a[i]]++;
    }
    /* sort(M.begin(),M.end()); */
    while(M.size()>2){
        auto i = M.begin();
        auto j = M.end();j--;
        int minn = min(i->second,j->second);
        i->second-=minn;
        j->second-=minn;
        if(!i->second) M.erase(i);
        else M.erase(j);
        i = M.begin();
        j = M.end();j--;
        i->second+=minn;
        j->second+=minn;
        (ans+=minn*2)%=2;
    }
    auto j = M.end();j--;
    cout<<(ans? "郝哥\n":"华强\n")<<M.begin()->first<<" "<<j->first;
    return 0;
}