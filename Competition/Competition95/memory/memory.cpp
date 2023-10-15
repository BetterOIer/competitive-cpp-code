#include<iostream>
#include<vector>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,tot=0,totMemStr=0;
char opt;
struct node{
    int ch;
    int num;
    int son[26];
};
node trie[100005];
string s,memStr[100005];
int idMemStr[100005];
bool havFnd[100005];
vector<int>ans;
void rotate(int m){
    m = m%s.length();
    string s1 = s.substr(0,m),s2=s.substr(m,s.length()-m);
    s=s2+s1;
}
void add(int pos,int posStr){
    if(posStr==(int)(s.length())-1){
        trie[pos].num=1;
        return;
    }
    if(!trie[pos].son[s[posStr]-'0']){
        trie[pos].son[s[posStr]-'0']=++tot;
        trie[tot].ch=s[posStr]-'0';
    }
    add(trie[pos].son[s[posStr]-'0'],posStr+1);
}
bool chkStr(int pos){
    int len = memStr[pos].length(),j=0;
    for(int i = 0;i<len;i++){
        if(!trie[j].son[memStr[pos][i]-'0']){
            if(trie[j].num)j = 0,i--;
            else return false;
        }else{
            j = trie[j].son[memStr[pos][i]-'0'];
        }
    }
    if(trie[j].num)return true;
    else return false;
}
int main(){
   /*  freopen("memory.in","r",stdin);
    freopen("memory.out","w",stdout); */
    n=read();
    for(int i = 1,lstAns = 0;i<=n;i++){
        cin>>opt>>s;
        rotate(lstAns);
        if(opt=='?'){
            memStr[++totMemStr]=s;
            idMemStr[totMemStr]=i;
            lstAns = chkStr(totMemStr);
            if(lstAns){
                havFnd[totMemStr]=true;
                printf("1 %d\n",i);
            }else printf("0\n");
        }else{
            add(0,0);
            for(int j = 0;j<=totMemStr;j++){
                if(havFnd[j])continue;
                else{
                    ans.clear();
                    if(chkStr(j))ans.push_back(idMemStr[j]);
                }
            }
            lstAns=ans.size();
            printf("%d",lstAns);
            for(int j:ans){
                printf(" %d",j);
            }printf("\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}