/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,d,k,q;
struct DOOR{
    int y;
    int x;
    char dir;
}door[100005];
bool operator < (DOOR a, DOOR b){
    return a.y<b.y;
}
int find(int y){
    int l = 1,r = k;
    while(l<=r){
        int mid = (l+r)>>1;
        if(door[mid].y<=y)l=mid+1;
        else r = mid-1;
    }
    return l;
}
int cal(int whi, int tim){
    int t = tim%((n-d)<<1),x = door[whi].x,di=(door[whi].dir=='+');
    while(t){
        if(di){
            if(t<=(n-d+1)-x){
                x+=t;
                t=0;
            }else{
                t-=(n-d+1)-x;
                x=(n-d+1);
                di=1-di;
            }
        }
        else{
            if(t<=x-1){
                x-=t;
                t=0;
            }else{
                t-=x-1;
                x=1;
                di=1-di;
            }
        }
    }
    return x;
    /* if(door[whi].dir=='+'){
        if(t<=(n-d+1)-x){
            return x+t;
        }else{
            t-=(n-d+1)-x;
            x=(n-d+1);
            return x-t;
        }
    }
    if(t<=x-1){
        return x-t;
    }else{
        t-=x-1;
        x=1;
        return x+t;
    } */
}
bool solve(int x,int y){
    int p=find(y);
    for(int i = p,nowx1=x,nowx2=x,nowy=y,tim=0;i<=k;i++){
        int t = door[i].y-nowy;
        int 
        nex1 = (nowx1-t>0? nowx1-t:1),
        nex2 = (nowx2+t<=n? nowx2+t:n);
        tim+=t;
        int dp1 = cal(i,tim);
        int dp2 = dp1+d-1;
        if(dp2<nex1||dp1>nex2){
            return false;
        }
        nowx1 = max(nex1,dp1);
        nowx2 = min(nex2,dp2);
        nowy = door[i].y;
    }
    return true;
}
int main(){
    /* freopen("wall4.in","r",stdin);
    freopen("wall4.out","w",stdout); */
    n=read(),m=read(),d=read(),k=read();
    for(int i = 1;i<=k;i++){
        door[i].x=read(),door[i].y=read();cin>>door[i].dir;
    }
    sort(door+1,door+k+1);/* 
    for(int i = 2313;i<=k;i++){
        cout<<door[i].x<<" "<<door[i].y<<" "<<door[i].dir<<endl;
    } */
    q=read();
    if(d==n){
        for(int i = 1;i<=q;i++)cout<<"1\n";
        return 0;
    }
    for(int i = 1,x,y;i<=q;i++){
        x=read(),y=read();
        int ans = solve(x,y);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}