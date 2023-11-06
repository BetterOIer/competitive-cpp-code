#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,q;
string opt;
int a[5];
int getPos(char s[]){
	if(s[0]=='a') return 1;
	if(s[0]=='b') return 2;
	if(s[0]=='c') return 3;
	if(s[0]=='d') return 4;
}
int main(){
    #ifndef LOCAL
    freopen("end.in","r",stdin);
    freopen("end.out","w",stdout);
    #else
    freopen("D/ex_D1.in","r",stdin);
    freopen("D/ex_D1.out","w",stdout);
    #endif
    n=read(),q=read();
    while(cin>>opt){
        if(opt[0]=='r'){

        }else if(opt=="xor"){

        }else if(opt=="xori"){

        }else if(opt=="and"){

        }else if(opt=="andi"){
            
        }else if(opt=="or"){

        }else if(opt=="ori"){

        }
    }
    //来 不 及 啦
    return 0;
}