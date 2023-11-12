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
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int nex[10005],m,n;
string pat,s;
void getNex(){
    nex[0]=0;int preLen = 0;
    for(int i = 1;i<=m;i++){
        while(preLen && pat[i] != pat[preLen])preLen=nex[preLen];
        if(pat[i]==pat[preLen])nex[i+1]=++preLen;
    }
}
void query(){
    for(int i = 0,j=0/* 用i指向主串，用j指向模式串 */;i<n;i++){
        while(j && s[i]!=pat[j])j = nex[j];//遇到不相等的地方，j就跳nex[];
        if(s[i]==pat[j]) j++;//如果相等，j指针后移
        if(j==m){
            cout<<i-m+2<<endl;
        }/* 返回相同子串开始的地方(这里约定下标开始是1) */
        //若要输出所有的相同字串，记录i-m+2，不要退出，继续遍历即可
    }
}
int main(){
    cin>>s>>pat;
    m=pat.length(),n=s.length();
    getNex();query();
    for(int i = 1;i<=m;i++)cout<<nex[i]<<" ";
    return 0;
}