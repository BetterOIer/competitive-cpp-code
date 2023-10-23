#include<iostream>
#include<set>
#define base 256
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,len;
string s,preLeft;
set<int>hashStr;
int mod=101527,ans=0;
void cal(){
    int cnt=0;
    for(int i = 0;i<=s.length()-1;i++){
        cnt=(cnt*base+s[i])%mod;
    }
    hashStr.insert(cnt);
}
int main(){
    /* freopen("game.in","r",stdin);
    freopen("game.out","w",stdout); */
    n=read();
    cin>>s;
    for(int i = 0;i<n;i++){
        if(!preLeft.length()){
            preLeft+=s[i];
            len++;
        }else{
            if(preLeft[len-1]==s[i]){
                preLeft.erase(len-1);
                len--;
            }else{
                preLeft+=s[i];
                len++;
            }
        }
        cal();
    }
    cout<<hashStr.size();
    fclose(stdin);
    fclose(stdout);
    return 0;
}