#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n;
string str[55];
int id[55];
bool apper[26];
int pri[9]={0,1,2,3,4,5,6,7,8};
set<int>ans;
bool cmp(int ida,int idb){
    int lena = str[ida].length();
    int lenb = str[idb].length();
    string sta = str[ida],stb=str[idb];
    while(lena<lenb)sta+='`',lena++;
    while(lenb<lena)stb+='`',lenb++;
    for(int i = 0;i<lena;i++){
        if(pri[sta[i]-'`']<pri[stb[i]-'`'])return true;
        else if(pri[sta[i]-'`']>pri[stb[i]-'`'])return false;
    }
    
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    n=read();
    for(int i = 1;i<=n;i++){
        cin>>str[i];id[i]=i;
    }
    do{
        /* for(int i = 0;i<=8;i++)cout<<pri[i]<<" \n"[i==8]; */
        sort(id+1,id+n+1,cmp);
        ans.insert(id[1]);
    }while(next_permutation(pri+1,pri+9));
    cout<<ans.size()<<endl;
    for(int i:ans){
        cout<<str[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}