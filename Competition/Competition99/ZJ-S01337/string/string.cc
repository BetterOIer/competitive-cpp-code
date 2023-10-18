#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,tot=0,strLen;
struct node{
    int num;
    int son[26];
}trie[300005];
string s,str[30005];
vector<int>ans;
int pri[26],priTot=-1;
void insert(int triePos, int strPos,int strId){
    if(strPos==strLen){
        trie[triePos].num=strId;
        return;
    }
    int nex = s[strPos]-'a';
    if(!trie[triePos].son[nex])trie[triePos].son[nex]=++tot;
    insert(trie[triePos].son[nex], strPos+1,strId);
}
void dfs(int pos,int prePri){
    if(trie[pos].num)return ans.push_back(trie[pos].num);
    bool vis[26],flag=false;for(int i = 0;i<26;i++)vis[i]=false;
    for(int i = 0;i<=priTot;i++){
        vis[pri[i]]=true;
        if((!flag)&&trie[pos].son[pri[i]]){dfs(trie[pos].son[pri[i]],i);flag=true;}
    }
    priTot = prePri+1;
    for(int i = 0;i<26;i++){
        if(vis[i])continue;
        if(trie[pos].son[i]){
            pri[priTot]=i;
            dfs(trie[pos].son[i],priTot);
        }
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    n=read();
    for(int i = 1;i<=n;i++){
        cin>>s;strLen = s.length();
        insert(0,0,i);
        str[i]=s;
    }
    dfs(0,-1);
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i:ans){
        cout<<str[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}