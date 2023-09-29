/*=================================================
*Le vent se lève,il faut tenter de vivre!
*Author: Better_OIer Zyx
*起风了，唯有努力生存！
*Blog: https://betteroier.site:1000
*Fileansstation: https://betteroier.site:1005
*OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
int n,k,cnt;
char s[1000005];
string anss;
void solve(){
    cnt=k;anss="";
    for(int i=1;i<n;i++){
        if(s[i]=='?'||s[i+1]=='?')continue;
        if(s[i]!=s[i+1])cnt--;
    }
    //找出现在已经有了的k并减去
    int minn=0,maxn=0;
    for(int i=1;i<n;i++){
        if(s[i]!='?'&&s[i+1]=='?'){
            int len=0;//都是?的区间长度
            while(i+len+1<=n&&s[i+len+1]=='?')len++;
            if(s[i]!=s[i+len+1]){
                minn++;maxn+=(len/2)*2+1;
            }else maxn+=(len+1)/2*2;
            i+=len;
        }
    }
    if(cnt<minn||cnt>maxn||((cnt&1)!=(minn&1))){
        anss="Impossible";
    }else{
        for(int i=1;i<=n;i++){
            if(s[i]!='?')anss+=s[i];
            else{
                int len=1;
                while(s[i+len]=='?')len++;
                if(s[i-1]!=s[i+len]) minn--,maxn-=(len/2)*2+1;
                else maxn-=(len+1)/2*2;

                int minPI=max(0,cnt-maxn),maxPI=cnt-minn;
                if(s[i-1]!=s[i+len]){
                    minPI--;maxPI--;
                    minPI=(minPI+1)/2;maxPI/=2;
                    if(s[i-1]=='0'){
                        int t=len-(minPI*2);cnt--;
                        while(t--)anss+="0";
                        while(minPI--) anss+="10",cnt-=2;
                    }else{
                        int t=len-(minPI*2);
                        while(t--){anss+="0";}cnt--;//单个补全
                        while(minPI--) anss+="01",cnt-=2;
                    }
                }else if(s[i-1]==s[i+len]){
                    minPI=(minPI+1)/2;maxPI/=2;
                    if(s[i-1]=='0'){
                        int t=len-max(0,(minPI*2)-1);
                        while(t--) anss+="0";
                        if(minPI) anss+="1",minPI--,cnt-=2;
                        while(minPI--) anss+="01",cnt-=2;
                    }else{
                        if(maxPI==0){//不能填了，直接插1
                            int t=len;
                            while(t--)anss+="1";
                        }else{
                            if(minPI)minPI--;
                            int t=len-(minPI*2);
                            while(t--){anss+="0";}cnt-=2;
                            while(minPI--)anss+="10",cnt-=2;
                        }
                    }
                }
                i+=len-1;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k>>(s+1);
    string ans="Impossible";
    bool wh_1 = (s[1] == '?'), wh_2 = (s[n] == '?');
    for(int j=0;j<=1;j++){
        if(wh_1||s[1]=='0'+j){
            s[1]='0'+j;
            for(int w=0;w<=1;w++)
                if(wh_2||s[n]=='0'+w){
                    s[n]='0'+w;
                    solve();
                    ans=min(ans,anss);
                }
        }
    }
    if(ans=="Impossible")cout<<"-1\n";
    else cout<<ans<<endl;
    return 0;
}