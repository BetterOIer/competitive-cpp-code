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
bool vaild[26];
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
    if(trie[pos].num)return ans.push_back(trie[pos].num),void();
    bool vis[26];for(int i = 0;i<26;i++)vis[i]=false;
    for(int i = 0;i<=priTot;i++){
        vis[pri[i]]=true;
        if(trie[pos].son[pri[i]])dfs(trie[pos].son[pri[i]],i);
    }
    for(int i = prePri+1;i<=priTot;i++){
        vaild[pri[i]]=true;
    }
    priTot = prePri+1;
    for(int i = 0;i<26;i++){
        if(vis[i])continue;
        if(trie[pos].son[i]&&vaild[i]){
            pri[priTot]=i;vaild[i]=false;
            dfs(trie[pos].son[i],priTot);
        }
    }
}
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        cin>>s;strLen = s.length();
        insert(0,0,i);
        str[i]=s;
    }
    for(int i = 0;i<26;i++)pri[i]=-1;
    dfs(0,-1);
    sort(ans.begin(),ans.end());
    for(int i:ans){
        cout<<str[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}