#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-') f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,sx,sy;
struct node{
    int y;
    int x;
    int w;
}a[1015];
double ansx,ansy;
double ans=1e18,t;
const double delta=0.997;
inline double cal(double x,double y) {
    double rt=0;
    for (int i=1;i<=n;i++) {
        double deltax=x-a[i].x,deltay=y-a[i].y;
        rt+=sqrt(deltax*deltax+deltay*deltay)*a[i].w;
    }
    return rt;
}
inline void simulate_anneal() {
    double x=ansx,y=ansy;
    t=4000;
    while (t>1e-14) {
        double X=x+((rand()<<1)-RAND_MAX)*t;
        double Y=y+((rand()<<1)-RAND_MAX)*t;
        double now=cal(X,Y);
        double Delta=now-ans;
        if (Delta<0) {
            x=X,y=Y;
            ansx=x,ansy=y,ans=now;
        }
        else if (exp(-Delta/t)*RAND_MAX>rand()) x=X,y=Y;
        t*=delta;
    }
}
int main(){
    srand((unsigned int)time(NULL));
    n=read();
    for (int i=1;i<=n;i++) {
        a[i].x=read(),a[i].y=read(),a[i].w=read();
        sx+=a[i].x,sy+=a[i].y;
    }
    ansx=(double)sx/n,ansy=(double)sy/n;
    simulate_anneal();
    simulate_anneal();
    simulate_anneal();
    printf("%.3f %.3f\n",ansx,ansy);
}