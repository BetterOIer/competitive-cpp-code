#include<iostream>
#include<cstring>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
string s;
/* int dp[1005][1005]; */
/* int preFix[105],ans=0; */
int ans[2];
int main(){
    #ifndef LOCAL
    freopen("went.in","r",stdin);
    freopen("went.out","w",stdout);
    #else
    freopen("B/ex_guo5.in","r",stdin);
    freopen("B/ex_guo5.res","w",stdout);
    #endif
    n=read();
    // int pos = 0,maxlen = 0;
    cin>>s;
    // Shit, Fake!!!
    // memset(dp,0x3f3f3f3f,sizeof dp);
    // for(int i = 1;i<=n;i++) dp[i][i]=1;
    // for(int k = 2;k<=n;k++){
    //     for(int l = 1,r;l<=n-k+1;l++){
    //         r = l+k-1;
    //         for(int j = l;j<r;j++){
    //             dp[l][r]=min(dp[l][r],dp[l][j]+dp[j+1][r]-(s[j-1]!=s[j]));
    //         }
    //     }
    // }
    // cout<<dp[1][n];

    // Shit,Fake Again !@#$@$%$^
    // while(s.length()){
    //     pos = 0,maxlen = 0;
    //     for(int i = 1;i<=n;i++){
    //         if(i-2>=0&&s[i-2]!=s[i-1])preFix[i]=preFix[i-1]+1;
    //         else preFix[i]=1;
    //         if(maxlen<preFix[i])pos = i,maxlen = preFix[i];
    //     }
    //     s = s.substr(0,pos-maxlen)+s.substr(pos,n-pos);
    //     n = s.length();
    //     ans++;
    // }
    // cout<<ans;

    for(int i = 1;i<n;i++){
        if(s[i]==s[i-1])ans[s[i]-'0']++;
    }
    cout<<max(ans[0],ans[1])+1<<endl;
    return 0;
}