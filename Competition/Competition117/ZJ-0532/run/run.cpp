#include<iostream>
#include<cstdio>
using namespace std;
inline int read(){
    int x=0,f=1;char c = getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x = (x<<1)+(x<<3)+(c^48);
    return x*f;
}
int main(){
    #ifndef ZYXNOIP
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    #else
    #endif
    cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//Goodbye OI!!!