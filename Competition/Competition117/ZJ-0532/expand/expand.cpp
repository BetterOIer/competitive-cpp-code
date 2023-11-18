#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
inline int read(){
    int x=0,f=1;char c = getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x = (x<<1)+(x<<3)+(c^48);
    return x*f;
}
int c,n,m,q;
int seqX[100005],seqY[100005];
int copX[100005],copY[100005];
stack<int>stk;
stack<int>stkY;
int getPreBig(int px){
    while(stk.size()&&copX[stk.top()]<=copX[px])stk.pop();
    if(stk.empty())return -1;
    else {int now = stk.top();stk.pop();return now;}
}
int getPreSml(int py){
    while(stkY.size()&&copY[stkY.top()]>=copY[py])stkY.pop();
    if(stkY.empty())return -1;
    else {int now = stkY.top();stkY.pop();return now;}
}
void insert(int px){
    while(copX[stk.top()]<=copX[px])stk.pop();
    stk.push(px);
}
void insertY(int py){
    while(copY[stkY.top()]>=copY[py])stk.pop();
    stk.push(py);
}
bool vaild(){
    if(copX[1]>copY[1]&&copX[n]<copY[m])return false;
    if(copX[1]<copY[1]&&copX[n]>copY[m])return false;
    if(copX[1]==copY[1]||copX[n]==copY[m])return false;
    /* int flag = copX[1]>copY[1];
    int pX = 1,pY = 1,tmpX,tmpY;
    while(pX<n&&pY<m){
        while(flag&&copX[pX]<=copY[pY]){
            tmpX=getPreBig(pX);
            if(tmpX==-1){
                break;
            }pX=tmpX;
        }
        while(flag&&copX[pX]<=copY[pY]){
            tmpY=getPreSml(pY);
            if(tmpY==-1){
                return false;
            }pY=tmpY;
        }
        insert(pX);insertY(pY);
        pX++;pY++;
    } */
    return true;
}
int main(){
    #ifndef ZYXNOIP
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    #else
    freopen("expand6.in","r",stdin);
    freopen("expand6.out","w",stdout);
    #endif
    c=read(),n=read(),m=read(),q=read();
    for(int i = 1;i<=n;i++){
        seqX[i]=read();
    }
    for(int i = 1;i<=m;i++){
        seqY[i]=read();
    }
    for(int i = 0,kx=0,ky=0;i<=q;i++){
        if(i)kx=read(),ky=read();
        memcpy(copX,seqX,sizeof seqX);
        memcpy(copY,seqY,sizeof seqY);
        for(int j = 1,u,v;j<=kx;j++){
            u=read(),v=read();
            copX[u]=v;
        }
        for(int j = 1,u,v;j<=ky;j++){
            u=read(),v=read();
            copY[u]=v;
        }
        if(vaild()){
            cout<<1;
        }else cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}