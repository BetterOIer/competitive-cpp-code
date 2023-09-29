#include<iostream>
#include<algorithm>
#define release
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
int xSta[200005];
int chkMin(){
    sort(xSta+1,xSta+n+1);
    int lastPos = xSta[1],ans=1;
    for(int i = 2;i<=n;i++){
        if(xSta[i]>=lastPos-1){
            if(xSta[i]==lastPos-1) lastPos=xSta[i]+2;
            else if(xSta[i]==lastPos) lastPos=xSta[i]+1;
            else lastPos=xSta[i];
            ans++;
        }
    }
    return ans;
}
int chkMax(){
    int lastPos = xSta[1]+2,ans=1;
    for(int i = 2;i<=n;i++){
        if(!(xSta[i]==lastPos||xSta[i]+1==lastPos||xSta[i]+2==lastPos)){
            lastPos = xSta[i]+2;
            ans++;
        }
    }
    return ans;
}
int main(){
    #ifdef release
    freopen("party.in","r",stdin);
    freopen("party.out","w",stdout);
    #endif
    n=read();
    for(int i = 1;i<=n;i++){
        xSta[i]=read()-1;
    }
    int ansMin = chkMin();
    int ansMax  = chkMax();
    cout<<ansMax<<" "<<ansMin<<endl;
    return 0;
}