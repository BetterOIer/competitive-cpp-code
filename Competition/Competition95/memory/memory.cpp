#include<iostream>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,m=5;
string s;
void rotate(){
    m = m%s.length();
    string s1 = s.substr(0,m),s2=s.substr(m,s.length()-m);
    s=s2+s1;
}
int main(){
    freopen("memory.in","r",stdin);
    freopen("memory.out","w",stdout);
    n=read();
    /* for(int i = 1;i<=n;i++){
        char opt;
        cin>>opt>>s;
        rotate();
        if(opt=='+'){
            I'm exhausted
        }else{

        }
    } */
    for(int i = 1;i<=n;i++){
        puts("0\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}