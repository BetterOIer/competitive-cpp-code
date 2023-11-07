#include<iostream>
#include<cstring>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int nxt[30];char s[30];
int to[30][10];
long long L,R;
int len,k;

long long f[30][30][30][2][2];
int num[30];
inline long long dfs(int now,int spos, int cnt,int upv,int stv){
    if(cnt<0)return 0;
    if(now<0) return cnt==0;
    if(~f[now][spos][cnt][upv][stv])return f[now][spos][cnt][upv][stv];
    long long ans=0;
    for(int v = 0;v<10;v++){
        if(upv&&v>num[now])break;
        int nst = stv|(v!=0);
        int npos = nst?to[spos][v]:0;
        int ncnt = cnt- (npos==len);
        ans+=dfs(now-1,npos,ncnt,upv&&v==num[now],nst);
    }
    return f[now][spos][cnt][upv][stv]=ans;
}
inline void init(long long x){
    for(int i = 0;i<20;i++){
        num[i]=x%10;x/=10;
    }
    memset(f,-1,sizeof f);
}
long long ans[30];
int main(){
    #ifndef LOCAL
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    #else
    #endif
    L=read(),R=read();cin>>(s+1);k=read();len=strlen(s+1);
    for(int i = 2,j=0;i<=len;i++){
        while(j&&s[j+1]!=s[i])j=nxt[j];
        if(s[j+1]==s[i])j++;
        nxt[i]=j;
    }
    for(int i = 0;i<=len;i++) for(int addv = 0;addv<10;addv++){
        int now = i;
        while(now&&(now==len||addv!=s[now+1]-'0'))now = nxt[now];
        if(s[now+1]-'0'==addv)now++;
        to[i][addv]=now;
    }
    init(R);
    for(int i = 0;i<=k;i++)ans[i]=dfs(20,0,i,1,0);
    init(L-1);
    for(int i = 0;i<=k;i++)ans[i]-=dfs(20,0,i,1,0);
    for(int i = 0;i<=k;i++)cout<<ans[i]<<" \n"[i==k];
    return 0;
}