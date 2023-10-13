#include<iostream>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n;
int tot=0;
unsigned short ans[10000005][5],low[3005];
bool chkAns(int pos){
    if(!low[pos])return false;
    int cnt=4;++tot;
    for(int p = pos;cnt;p=low[p]--){
        if(!low[p]){
            ans[tot][cnt--]=p;
            break;
        }
        ans[tot][cnt--]=p;
    }
    while(cnt)ans[tot][cnt]=ans[tot][cnt+1],cnt--;
    return true;
}
int main(){
    n=read();
    int pos = n;
    for(int i = 1;i<=n;i++)low[i]=i-1;
    while(pos){
        if(!chkAns(pos))pos--;
    }
    printf("%d\n",tot);
    for(int i = 1;i<=tot;i++){
        printf("%d %d %d %d\n",ans[i][1],ans[i][2],ans[i][3],ans[i][4]);
    }
    return 0;
}