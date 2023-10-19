#include<iostream>
#include<cstring>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
string s[30002];
int a[300002][27],cnt;
bool c[300002];
void insert(string ss){
    int p=0,len=ss.length();
    for(int i=0;i<len;i++){
        int ch=ss[i]-'a';
        if(!a[p][ch]){
            a[p][ch]=++cnt;
        }
        p=a[p][ch];
    }
    c[p]=1;
}
bool vis[27][27];
bool check(string ss){
    memset(vis,0,sizeof(vis));
    int p=0,len=ss.length();
    for(int i=0;i<len;i++){
        int ch=ss[i]-'a';
        
        for(int j=0;j<26;j++){
            if(j==ch||(!a[p][j]))continue;
            if(vis[j][ch]==1)return 0;
            vis[ch][j]=1;
        }
        p=a[p][ch];
        if(c[p]==1&&i!=len-1)return 0;
    }
    return 1;
}
int ans;
int b[30005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        insert(s[i]);
    }
    for(int i=1;i<=n;i++){
        if(check(s[i]))b[++ans]=i;
    }
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++){
        cout<<s[b[i]]<<"\n";
    }
    fclose(stdin);fclose(stdout);
    return 0;
}