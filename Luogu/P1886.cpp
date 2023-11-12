/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<queue>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,k;
int a[1000005];
deque<int>Q1,Q2;
int main(){
    n=read(),k=read();
    for(int i = 1;i<=n;i++)a[i]=read();
    for(int i = 1;i<=n;i++){
        while(Q1.size()&&Q1.front()<=i-k)Q1.pop_front();
        while(Q1.size()&&a[Q1.back()]>=a[i])Q1.pop_back();
        Q1.push_back(i);if(i>=k)cout<<a[Q1.front()]<<" \n"[i==n];
    }
    for(int i = 1;i<=n;i++){
        while(Q2.size()&&Q2.front()<=i-k)Q2.pop_front();
        while(Q2.size()&&a[Q2.back()]<=a[i])Q2.pop_back();
        Q2.push_back(i);if(i>=k)cout<<a[Q2.front()]<<" \n"[i==n];
    }
    return 0;
}