#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
bool a[50][1100];
bool hang[1000],lie[1000];
int staH,enH,tot=0;
void getAns(int stx,int enx){
    /* ++tot;
    for(int i = staH;i<=enH;i++){
        for(int j = stx;j<=enx;j++){
            cout<<(a[i][j]==1?"#":".");
        }
        cout<<endl;
    }
    cout<<endl; */
    cout<<"M[\"";

    for(int i = staH;i<=enH;i++){
        for(int j = stx;j<=enx;j++){
            cout<<a[i][j];
        }
    }
    cout<<"\"]=\"\";\n";
}
int main(){
    #ifndef LOCAL
    freopen("recognition.in","r",stdin);
    freopen("recognition.out","w",stdout);
    #else
    freopen("recognition.txt","r",stdin);
    freopen("recognition.out","w",stdout);
    #endif
    char n;
    for(int i = 1;i<=30;i++){
        for(int j = 1;j<=720;j++){
            cin>>n;
            a[i][j]=(n=='#');
        }
    }
    for(int i = 1;i<=30;i++){
        for(int j = 1;j<=720;j++){
            cout<<(a[i][j]==1?"#":".");
        }
        cout<<endl;
    }
    for(int i = 1;i<=721;i++){
        for(int j = 1;j<=31;j++){
            lie[i]=a[j][i];
            if(lie[i])break;
        }
    }
    bool hav=false;
    for(int i = 1;i<=31;i++){
        for(int j = 1;j<=721;j++){
            hang[i]=a[i][j];
            if(hang[i]){if(!hav){hav=true;staH=i;}break;}
        }
        if((!hang[i])&&hav){
            hav=false;
            enH=i-1;
        }
    }
    int stx,enx;
    bool sta=false;
    for(int i = 1;i<=721;i++){
        if(lie[i]){
            if(!sta){
                sta=true;
                stx=i;
            }
        }else{
            if(sta){
                sta=false;
                enx=i-1;
                getAns(stx,enx);
            }
        }
    }
    return 0;
}