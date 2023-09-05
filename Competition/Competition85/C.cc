/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int len,nex[500005],nex2[500005],ans=0;
void kmp(string s){
    nex[0]=0;
    for(int i = 1,j = 0;i<=len;i++){
        while(j&&s[i]!=s[j])j = nex[j-1];
        if(s[i]==s[j])j++;
        nex[i]=j;
    }
}
string s,t;
int main(){
    cin>>s;t=s;
    len = s.length();
    reverse(t.begin(),t.end());
    kmp(t);swap(nex2,nex);kmp(s);
    bool flag=true;
    for(int i = 0;i<len;i++)if(s[i]!=s[0])flag=false;
    if(flag)cout<<len<<"\n1";
    else if(nex[len - 1] == 0 || len % (len - nex[len - 1]) != 0)cout<<"1\n1";
    else{
        for(int i = 1;i<=len;i++){
			int j = len - i;
			if((nex[i - 1] == 0 || i % (i - nex[i - 1]) != 0) && (nex2[j - 1] == 0 || j % (j - nex2[j - 1]) != 0)) ans++;
		}
		cout<<"2\n"<<ans;
    }
    return 0;
}