#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,m,mr,res=0;
double X=0,Y=0;
struct ARCH{
    int x;
    int y;
    int r;
}arch[12];
struct node{
    int x;
    int y;
}enemy[1003];
double len(double x_1,double y_1,double x_2,double y_2){
    return __builtin_sqrt((x_2-x_1)*(x_2-x_1)+(y_2-y_1)*(y_2-y_1));
}
double getMaxRa(double x,double y){
    double r = mr;
    for(int i = 1;i<=n;i++){
        r= min(len(x,y,arch[i].x,arch[i].y)-arch[i].r,r);
    }
    return r;
}
int getVal(double x,double y){
    int ans=0;
    double r = getMaxRa(x,y);
    for(int i = 1;i<=m;i++){
        if(len(x,y,enemy[i].x,enemy[i].y)<=r){
            ans++;
        }
    }
    return ans;
}
void SA(){
    double x = X,y = X;
    int val = getVal(x,y);
    for(double temp = 3000;temp>=1e-15;temp*=0.997){
        double 
        newX = x+1.0*((rand()<<1)-RAND_MAX)*temp,
        newY = y+1.0*((rand()<<1)-RAND_MAX)*temp;
        int newVal = getVal(newX,newY);
        if(newVal>val)
            x = newX,y = newY,val = newVal;
    }
    X=x,Y=y;
    res = max(res,val);
}
int main(){
    int t = clock();
    srand(time(0));
    n=read(),m=read(),mr=read();
    for(long long i = 1;i<=n;i++)arch[i].x=read(),arch[i].y=read(),arch[i].r=read();
    for(long long i = 1;i<=m;i++)enemy[i].x=read(),enemy[i].y=read(),X+=enemy[i].x,Y+=enemy[i].y;
    X/=m,Y/=m,res = getVal(X,Y);
    SA();SA();SA();SA();SA();
    cout<<res;
    return 0;
}