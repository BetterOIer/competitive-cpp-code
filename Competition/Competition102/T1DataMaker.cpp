#include<iostream>
#include<cstdlib>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int main(){
    freopen("ex_segmin4.in","w",stdout);
    cout<<"2000000\n";
    for(int i = 1;i<=2000000;i++){
        cout<<i<<" ";
    }
    return 0;
}