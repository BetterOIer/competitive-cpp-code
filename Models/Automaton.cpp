/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: betteroier.site:1000
* FileStation: betteroier.site:1001
* OnlineJudge: betteroier.site:8888
=================================================*/
#include<iostream>
#include<queue>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
const int maxn=1000005;
int cnt[maxn],ch[maxn][26],ne[maxn],idx=0;
string master_s,pattern_s;
void build_ac(){
     queue<int>q;
     for(int i = 0;i<26;i++){
        if(ch[0][i])q.push(ch[0][i]);
     }
     while(q.size()){
        int u=q.front();q.pop();
        for(int i =0;i<26;i++){
            int v=ch[u][i];
            if(v)ne[v]=ch[ne[u]][i],q.push(v);
            else ch[u][i]=ch[ne[u]][i];
        }
     }
}
int query(){
    int ans=0;
    for(int k=0,i=0;master_s[k];k++){
        i=ch[i][master_s[k]-'a'];
        for(int j = i;j&&~cnt[j];j=ne[j]){
            ans+=cnt[j],cnt[j]=-1;
        }
    }
    return ans;
}
void build_trie(){
    int p=0;
    for(int i = 0;pattern_s[i];i++){
        int j=pattern_s[i]-'a';
        if(!ch[p][j])ch[p][j]=++idx;
        p=ch[p][j];
    }
    cnt[p]++;
}
int main(){
    int n=read();
    for(int i = 1;i<=n;i++){
        cin>>pattern_s;
        build_trie();
    }
    build_ac();
    cin>>master_s;
    cout<<query();
    return 0;
}