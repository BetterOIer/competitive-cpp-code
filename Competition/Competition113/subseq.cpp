#include<iostream>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int a[305],pre[1100000],tot,n,tmp[305],cnt=0;
set<int>s;
bool cmp(int a,int b){
    return __builtin_popcount(a)>__builtin_popcount(b);
}
bool vaild(int pos){
    if(!pos)return false;
    if(__builtin_popcount(pos)==1)return true;
    int last= __lg(pos&-pos)+1;
    pos-=(pos&-pos);
    while(pos){
        int now = __lg(pos&-pos)+1;
        if(a[now]<=a[last])return false;
        last=now;
        pos-=(pos&-pos);
    }
    return true;
}
int getTmp(int pos){
    int res=0;
    while(pos){
        res+=(1<<tmp[__lg(pos&-pos)+1]);
        pos-=(pos&-pos);
    }
    return res;
}
void insert(int pos){
    cnt=0;
    while(pos){
        tmp[++cnt]=__lg(pos&-pos);
        pos-=(pos&-pos);
    }
    for(int i = 1;i<(1<<cnt);i++){
        s.insert(getTmp(i));
    }
}
void getAns(){
    tot=0;s.clear();
    for(int i = 0;i<(1<<n);i++){
        if(vaild(i)){
            pre[++tot]=i;
        }
    }
    sort(pre+1,pre+tot+1,cmp);
    int ans=0;
    for(int i =1;i<=tot;i++){
        if(s.find(pre[i])==s.end())insert(pre[i]),ans++;
    }
    cout<<ans<<endl;;
}
int main(){
    #ifndef LOCAL
    freopen("subseq.in","r",stdin);
    freopen("subseq.out","w",stdout);
    #else
    freopen("ex_subseq5.in","r",stdin);
    freopen("ex_subseq5.res","w",stdout);
    #endif
    int t=read();
    while(t--){
        n=read();
        for(int i = 1;i<=n;i++)a[i]=read();
        //爱你孤身走暗巷，爱你不跪的模样，爱你对峙过绝望，不肯哭一场
        getAns();
    }
    return 0;
}