#include<iostream>
#include<map>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,len;
string s,preLeft;
map<string,long long>strs;
long long calAns(long long how){
    return how*(how-1)/2;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    n=read();
    cin>>s;
    strs[preLeft]=1;
    for(long long i = 0;i<n;i++){
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
        if(!strs[preLeft]){
            strs[preLeft]=0;
        }strs[preLeft]++;
    }
    long long ans=0;
    for(auto i:strs){
        ans+=calAns(i.second);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}