#include<iostream>
#include<cstdio>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}
int n;
string s;
int lin[2000005];
int ans=0;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    n=read();cin>>s;int len =s.length();
    int head = 0;
    for(int i = 0;i<len;i++){
        lin[i]=i+1;
    }
    lin[len]=-1;
    int p=lin[head],q=head,o=head,anscnt=0;
    while(head!=-1){
        p=lin[head],q=head,o=head;
        while(p!=-1){
            if(s[p]==s[q]){
                ans++;
                if(q==head){
                    head=q=o=p=p[lin];
                    p=lin[p];
                }else{
                    lin[o]=p[lin];
                    p=q=lin[o];
                    p=lin[p];
                }
            }
            else{
                o=q;
                q=p;
                p=lin[p];
            }
        }
        if(anscnt==ans)break;
        anscnt=ans;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}