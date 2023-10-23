#include<iostream>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,ans;
int pre[2000005],num[2000005];
int trie[2000005][26];
string s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    n=read();
    cin>>s;
    s=" "+s;
    for(int i = 1;i<=n;i++){
        if(trie[i-1][s[i]-'a']){
            pre[i]=trie[i-1][s[i]-'a']-1;
            for(int j = 0;j<26;j++)trie[i][j]=trie[pre[i]][j];
            num[i]=num[pre[i]]+1;
            ans+=num[i];
        }
        trie[i][s[i]-'a']=i;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}