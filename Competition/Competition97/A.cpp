#include<iostream>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,spcPoint,ans;
bool a[505][505];
/* string s; */
int main(){
    freopen("firstsnow.in","r",stdin);
    freopen("firstsnow.out","w",stdout);
    n=read(),spcPoint=read();
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            a[i][j]=getchar()-'0';
        }
        getchar();
    }
    for(int ldX = 1;ldX<=n;ldX++){
        for(int ldY = 1;ldY<=n;ldY++){
            if(a[ldX][ldY]){
                for(int xOff=0;xOff+1<=ldX&&ldY+xOff+1<=n;xOff++){
                    for(int yOff=1;ldY+xOff+yOff<=n&&ldX+yOff<=n&&ldX+yOff-xOff>=1;yOff++){
                        if(a[ldX-xOff][ldY+yOff]&&a[ldX+yOff-xOff][ldY+xOff+yOff]&&a[ldX+yOff][ldY+xOff])ans++;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}