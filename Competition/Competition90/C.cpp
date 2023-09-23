#include<iostream>
#define release
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
string s,ori;
char table[26];
int refTo[26];
int belong[26],havNum=0;
bool used[26];
int find(int x){
    if(belong[x]==x)return x;
    return belong[x] = find(belong[x]);
}
void join(int x,int y){
    belong[find(x)]=find(y);
}
void solve(){
    for(int i = 0;i<26;i++)refTo[i]=-1;
    for(int i = 0;i<26;i++)used[i]=false;
    for(int i = 0;i<26;i++)belong[i]=i;
    havNum=0;
    int len = read(),pos = 0;
    ori="";
    cin>>s;
    for(int i = 0;i<len;i++){
        if(refTo[s[i]-'a']!=-1){
            ori+=table[refTo[s[i]-'a']];
        }else{
            pos=0;while(used[pos]||s[i]==table[pos])pos++;
            while(find(s[i]-'a')==find(pos)&&havNum<25){
                pos++;
            }
            refTo[s[i]-'a']=pos;
            join(s[i]-'a',pos);
            used[pos]=true;havNum++;
            ori+=table[refTo[s[i]-'a']];
        }
    }
    cout<<ori<<endl;
}
int main(){
    #ifdef release
    freopen("encode.in","r",stdin);
    freopen("encode.out","w",stdout);
    #endif
    for(int i = 0;i<26;i++) table[i] = 'a'+i;
    int t=read();
    while(t--){
        solve();
    }
    return 0;
}