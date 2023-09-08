#include<iostream>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,c;
int a[100001],b[100001];
void dfs(int x,int y){
    if(x==n&&y==n)return ;
    if(a[x+1]*b[y]%c>a[x]*b[y+1]%c){
        cout<<"R";
        dfs(x+1,y);
    }else{
        cout<<"D";
        dfs(x,y+1);
    }
}
int main(){
    n=read(),c=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
    }
    for(int i = 1;i<=n;i++){
        b[i]=read();
    }
    dfs(1,1);
    return 0;
}