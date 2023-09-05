#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<3)+(s<<1)+ch-'0';
        ch=getchar();
    }
    return s*w;
}
int n,m,r;
int bx[15],by[15],br[15];
int x[1003],y[1003];
double ans;
double ansx,ansy;
double check(double xx,double yy){
    double mr=r;
    for(int i=1;i<=n;i++){
        double rr=sqrt((bx[i]-xx)*(bx[i]-xx)+(by[i]-yy)*(by[i]-yy))-br[i];
        if(rr<=mr)mr=rr;
    }
    int res=0;
    for(int i=1;i<=m;i++){
        double rr=sqrt((x[i]-xx)*(x[i]-xx)+(y[i]-yy)*(y[i]-yy));
        if(rr<=mr)res++;
    }
    return res;
}

void tui(){
    double t=3000,k=0.997,down=1e-15;
    double ax=ansx,ay=ansy;
    while(t>=down){
        double xx=ansx+((rand()<<1)-RAND_MAX)*t;
        double yy=ansy+((rand()<<1)-RAND_MAX)*t;
        double tot=check(xx,yy);
        if(tot>ans){
            ans=tot;
            ansx=xx;
            ansy=yy;
            ax=xx;
            ay=yy;
        }
        else if(-exp((tot-ans)/t)*RAND_MAX<rand()){
            ax=xx;
            ay=yy;
        }
        t*=k;
    }
}
int main(){
    srand(time(0));
    n=read(),m=read(),r=read();
    for(int i=1;i<=n;i++)bx[i]=read(),by[i]=read(),br[i]=read();
    for(int i=1;i<=m;i++)x[i]=read(),y[i]=read(),ansx+=x[i],ansy+=y[i];
    ansx/=m,ansy/=m;
    ans=check(ansx,ansy);
    for(int i=1;i<=6;i++)tui();
    printf("%.0f",ans);
}