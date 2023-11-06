#include<iostream>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
char s[55];
int dep[55];
vector<int>wei[4];
vector<int>ro[55];
int fa[55];
int eql[55];
int main(){
    #ifndef LOCAL
    freopen("very.in","r",stdin);
    freopen("very.out","w",stdout);
    #else
    freopen("B/ex_B1.in","r",stdin);
    freopen("B/ex_B1.out","w",stdout);
    #endif
    n=read();
    for(int i = 1;i<=n;i++){
        scanf("%s",s+1);
        for(int j = 1;j<=n;j++){
            if(i==j)continue;
            if(s[j]=='+'||s[j]=='-'){
                int nowI = i,nowJ = j;
                if(s[j]=='-')swap(nowI,nowJ);
                ro[nowJ].push_back(nowI);
                fa[nowI]=nowJ;
            }else if(s[j]=='='){
                eql[j]=i;
                eql[i]=j;
            }
        }
    }
    int chd = 0;
    do{
        for(int i = 1;i<=n;i++){
            if(fa[fa[i]]){
                dep[i]=3;
                dep[fa[i]]=2;
                dep[fa[fa[i]]]=1;
                wei[3].push_back(i);
                wei[1].push_back(fa[i]);
                wei[1].push_back(fa[fa[i]]);
                chd+=3;
            }
            if(dep[eql[i]])dep[i]=dep[eql[i]],chd++;
            if(fa[i]){
                if(ro[i].size()){

                }
            }
        }
    }while(chd);
    return 0;
}