#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
char g[205][205];
int main(){
    #ifndef LOCAL
    freopen("crub.in","r",stdin);
    freopen("crub.out","w",stdout);
    #else
    freopen("ex_cube3.in","r",stdin);
    freopen("ex_cube3.res","w",stdout);
    #endif
    int t=read();
    while(t--){
        for(int i = 1;i<=202;i++)for(int j = 1;j<=202;j++)g[i][j]='.';
        int a=read(),b=read(),c=read();
        for(int i = 1,cnt=1;i<=b;i++,cnt+=2){
            for(int j = (b-i+1)*2+1;j<=(b-i+1)*2+a*2;j+=2)g[cnt][j]='+',g[cnt][j+1]='-';
            for(int j = (b-i+1)*2;j<=(b-i+1)*2-1+a*2;j+=2)g[cnt+1][j]='/';
        }
        for(int i = 1,cnt=b*2+1;i<=c;i++,cnt+=2){
            for(int j = 1;j<=a*2;j+=2)g[cnt][j]='+',g[cnt][j+1]='-';
            for(int j = 1;j<=a*2;j+=2)g[cnt+1][j]='|';
        }
        for(int i = 1,cnt=b*2+1;i<=c;i++,cnt+=2){
            for(int j = 1;j<=b*2;j+=2)g[cnt-(j-1)][j+2*a]='+',g[cnt-(j-1)-1][j+2*a+1]='/';
            for(int j = 1;j<=b*2;j+=2)g[cnt+1-(j-1)][j+2*a]='|';
        }
        for(int i = 1;i<=2*a;i+=2)g[2*(c+b)+1][i]='+',g[2*(c+b)+1][i+1]='-';
        for(int i = 1;i<=2*b;i+=2)g[2*(c+b)+1-(i-1)][i+2*a]='+',g[2*(c+b)-(i-1)][i+2*a+1]='/';
        for(int i = 1;i<=2*c;i+=2)g[i][2*(a+b)+1]='+',g[i+1][2*(a+b)+1]='|';
        g[2*c+1][2*(a+b)+1]='+';
        for(int i = 1;i<=2*(b+c)+1;i++){{for(int j = 1;j<=1+2*(a+b);j++)cout<<g[i][j];}cout<<"\n";}
    }
    return 0;
}




/* 
        for(int i = 1;i<=b;i++){
            for(int j = b-i+1;j;j--)cout<<"..";
            for(int j = 1;j<=a;j++)cout<<"+-";
            for(int j = i-1;j;j--)cout<<"+.";
            cout<<"+\n";

            for(int j = b-i;j;j--)cout<<"..";
            for(int j = 1;j<=a+1;j++)cout<<"./";
            for(int j = i-1;j;j--)cout<<"|/";
            cout<<"|\n";
        }
        for(int i = 1;i<=c-b;i++){
            for(int j = 1;j<=a;j++)cout<<"+-";
            for(int j = b;j;j--)cout<<"+.";
            cout<<"+\n";

            for(int j = 1;j<=a;j++)cout<<"|.";
            for(int j = b;j;j--)cout<<"|/";
            cout<<"|\n";
        }
        for(int j = 1;j<=a;j++)cout<<"+-";
        for(int j = b;j;j--)cout<<"+.";
        cout<<"+\n";
        for(int i = 1;i<=b;i++){
            for(int j = 1;j<=a;j++)cout<<"|.";
            for(int j = b-i+1;j;j--)cout<<"|/";
            for(int j = 1;j<i;j++)cout<<"..";
            cout<<".\n";

            for(int j = 1;j<=a;j++)cout<<"+-";
            for(int j = b-i+1;j;j--)cout<<"+.";
            for(int j = 1;j<i;j++)cout<<"..";
            cout<<".\n";
        } */