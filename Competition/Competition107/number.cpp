#include<iostream>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long L,R,k;
string s;
long long tim[20];
int main(){
    #ifndef LOCAL
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    #endif
    L=read(),R=read();cin>>s;k=read();
    if(!k){cout<<R-L+1<<"\n";return 0;}
    for(long long i = L;i<=R;i++){
        string now = to_string(i);
        long long pla = now.find(s),t=0;
        while(pla!=-1){
            now = now.substr(0,pla)+now.substr(pla+2,now.length()-pla-1);
            t++;
            pla = now.find(s);
        }
        tim[t]++;
        if(t==2)cout<<i<<endl;
        /* for(long long J = 0;J<=k;J++){
            cout<<tim[J]<<" \n"[J==k];
        } */
    }
    for(long long i = 0;i<=k;i++){
        cout<<tim[i]<<" ";
    }
    return 0;
}