#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n;
int main(){
    srand((unsigned int)time(NULL));
    freopen("railway.in","r",stdin);
    freopen("railway.out","w",stdout);
    n=read();
    int cnt=rand()%10;
    printf("%d\n",n*n/4+cnt);
    for(int i = 1,j=n+1-i;i<j;i++,j=n+1-i){
        for(int k = i+1;k<=j;k++){
            printf("%d %d %d %d\n",i,k,j,j);
        }
    }
    for(int i = 1;i<=cnt;i++){
        printf("1 1 1 1\n");
    }
    return 0;
}