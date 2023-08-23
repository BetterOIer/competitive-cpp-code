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
#include<map>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,idx/* 处理数的离散化 */;
int a[100005];
priority_queue<int> q[100005];/* 为当前次数的数们 */
int tmp[200005]/* 这个离散化后的数的次数 */;
map<int ,int >M,Mm;
int main(){
    n=read(),m=read();
    for(int i = 1;i<=n;i++) a[i]=read();
    for(int i = 1;i<=n;i++){
        if(!M[a[i]])M[a[i]]=++idx;
        if(!tmp[M[a[i]]]){
            tmp[M[a[i]]]++;
            q[tmp[M[a[i]]]].push(M[a[i]]);
        }else{
            q[tmp[M[a[i]]]]
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}