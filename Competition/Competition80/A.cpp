/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
string s;
long long n,ans=0,cnt=0;
bool vis[1000005];
long long find(long long ad,long long pos,char c){
    for(;pos<n;pos++){
        if(vis[pos]){
            continue;
        }
        if(s[pos]==c){
            break;
        }
    }
    ans+=pos-ad-cnt;
    cnt++;
    return pos;
}
int main(){
    n=read();
    cin>>s;
    /* for(long long i = find(0,'('),j = find(0,')');i<n&&j<n;i=find(++i,'('),j=find(++j,')')){
        ans+=abs(i-j);

    } */
    long long l = 0,r = 0,j=-1;
    for(long long i = 0;i<n;i++){
        if(vis[i]){
            cnt--;
            continue;
        }
        if(s[i]=='(')l++;
        else r++;
        if(l<r){
            j = find(i,j+1,'(');
            vis[j]=true;
            l++;
        }
        vis[i]=true;
    }
    cout<<ans;
    return 0;
}