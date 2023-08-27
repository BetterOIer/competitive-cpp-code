/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<bits/stdc++.h>
using namespace std;
string s;
long long n,ans=0,cnt=0;
bool vis[1000005];
long long find(long long ad,long long pos,char c){
    for(;pos<n;pos++){
        if(vis[pos]) continue;
        if(s[pos]==c) break;
    }
    ans+=pos-ad-cnt++;
    return pos;
}
int main(){
    cin>>n>>s;
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