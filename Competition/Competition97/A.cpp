#include<iostream>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,spcPoint,ans;
int a[505][505];
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
            if(a[ldX][ldY])for(int ruX = ldX;ruX<=n;ruX++){
                for(int ruY = ldY+1;ruY<=n;ruY++){
                    if(
                        a[ruX][ruY]&&
                        (!((ldX+ruX+ldY-ruY)&1))&&(!((ruX-ldX+ldY+ruY)&1))&&(ldX+ruX+ldY-ruY)/2>=1&&(ruX-ldX+ldY+ruY)/2<=n&&a[(ldX+ruX+ldY-ruY)/2][(ruX-ldX+ldY+ruY)/2]&&
                        (!((ldX+ruX-ldY+ruY)&1))&&(!((ldX-ruX+ldY+ruY)&1))&&(ldX+ruX-ldY+ruY)/2<=n&&(ldX-ruX+ldY+ruY)/2>=1&&a[(ldX+ruX-ldY+ruY)/2][(ldX-ruX+ldY+ruY)/2]
                    )ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}