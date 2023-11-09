#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,k;
struct CARD{
    long long val;
    int scr;
}card[105];
long long dp[2][105][2605][105]/* ,maxv[2][105][2605][105] */;
vector<int>v1,v2;
bool operator< (const CARD a,const CARD b){
    return a.scr>b.scr;
}
int main(){
    #ifndef LOCAL
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    #else
    freopen("ex_card4.in","r",stdin);
    //freopen("ex_card4.res","w",stdout);
    #endif
    n=read(),k=read();int Q=0;
    for(int i = 1;i<=n;i++){
        card[i].val=read(),card[i].scr=read();Q+=card[i].scr;
        //if(card[i].val<0){i--,n--;}
    }
    for(int i = 0;i<=1;i++){
        for(int j = 0;j<=104;j++){
            for(int q= 0;q<=Q;q++){
                for(int m = 0;m<=104;m++){
                    dp[i][j][q][m]=-1145141919810;
                }
            }
        }
    }
    dp[0][0][Q][0]=0;
    int flg=1;
    long long ans=-1145141919810;
    for(int i = 1;i<=n;i++,flg^=1){
        for(int j = i;j<=n;j++){
            for(int q = 0;q<(Q<<1);q++){
                for(int p = 0;p<=min(k,i);p++){
                    long long res=-1145141919810;
                    for(int m = i-1;m<j;m++){
                        if(p==i&&j==i){
                            if(q-2*card[j].scr>=0)res=max(res,dp[flg^1][m][q-2*card[j].scr][p-1]+card[j].val);
                            if(q+2*card[j].scr<(Q<<1))res=max(res,dp[flg^1][m][q+2*card[j].scr][p-1]+card[j].val);
                        }
                        else{
                            if(q-card[j].scr>=0)res=max(res,dp[flg^1][m][q-card[j].scr][p]+card[j].val);
                            if(q+card[j].scr<(Q<<1))res=max(res,dp[flg^1][m][q+card[j].scr][p]+card[j].val);
                        }
                    }
                    dp[flg][j][q][p]/* =maxv[flg][j][q][p] */=res;
                    //if(flg&&j==1&&q==Q+6&&p==1)cout<<"n:"<<dp[flg][j][q][p]<<endl;
                    //if(!flg&&j==2&&q==Q+6&&k==0)cout<<"m:"<<dp[flg][j][q][p]<<endl;
                    if(q==Q)ans=max(ans,res);
                    ///cout<<ans<<endl;
                }
            }
        }
    }
    cout<<ans;
    /* sort(card+1,card+n+1);
    int p1=0,p2=0,val=0;
    for(int i =1;i<=n;i++){
        if(p1<p2){
            v1.push_back(i);
            p1+=card[i].scr;
        }else{
            v2.push_back(i);
            p2+=card[i].scr;
        }
        val+=card[i].val;
    }
    cout<<p1<<" " <<p2<<" "<<val; */
    return 0;
}