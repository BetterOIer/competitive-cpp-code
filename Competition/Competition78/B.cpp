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
deque<int>dq;
int main(){
    int n=read(),L=2,R=n;dq.push_back(1);
    int cnt=n-1;
    while(cnt){
        int r = dq.back(),l=dq.front();
        if(cnt)if(r>n/2){
            dq.push_back(L++);
            cnt--;
        }else{
            dq.push_back(R--);
            cnt--;
        }
        if(cnt)if(l>n/2){
            dq.push_front(L++);
            cnt--;
        }else{
            dq.push_front(R--);
            cnt--;
        }
    }
    while(dq.size()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    return 0;
}