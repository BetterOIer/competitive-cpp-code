#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int read(){
    int x=0,f=1;char c = getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x = (x<<1)+(x<<3)+(c^48);
    return x*f;
}
int n,m;
struct node{
    string s;
    int tag;
}st[6003];
string sRev;
bool operator < (const node a,const node b){
    if(a.s==b.s)return a.tag>b.tag;
    else return a.s<b.s;
}
bool ans[3005];
int num[27];
void mySort(int whi){
    for(int i = 0;i<m;i++){
        num[st[whi].s[i]-'a']++;
    }
    st[whi].s="";
    for(int i = 0;i<26;i++){
        for(int j = 1;j<=num[i];j++){
            st[whi].s+=(i+'a');
        }
        num[i]=0;
    }
}
int main(){
    #ifndef ZYXNOIP
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    #else
    freopen("dict4.in","r",stdin);
    freopen("dict4.out","w",stdout);
    #endif
    n=read(),m=read();
    for(int i =1;i<=n;i++){
        cin>>st[i].s;st[i].tag=i;
    }
    for(int i = 1;i<=n;i++){
        mySort(i);
    }
    for(int i = 1;i<=n;i++){
        sRev=st[i].s;reverse(sRev.begin(),sRev.end());
        st[i+n].s=sRev;st[i+n].tag=i+n;
    }
    int tot = n<<1;
    sort(st+1,st+tot+1);
    for(int i = 1;i<=n;i++){
        if(st[i].tag>n){
            if(st[i+1].s==st[i].s)ans[st[i].tag-n]=true;
            break;
        }
        ans[st[i].tag]=true;
    }
    for(int i = 1;i<=n;i++){
        cout<<ans[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}