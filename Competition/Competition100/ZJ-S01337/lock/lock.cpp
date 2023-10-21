#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}
struct node{
    int l1,l2,l3,l4,l5;
};
bool operator < (const node a, const node b){
    if(a.l1==b.l1){
        if(a.l2==b.l2){
            if(a.l3==b.l3){
                if(a.l4==b.l4){
                    return a.l5<b.l5;
                }
                return a.l4<b.l4;
            }
            return a.l3<b.l3;
        }
        return a.l2<b.l2;
    }
    return a.l1<b.l1;
}
map<node,int>ans;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n=read();
    for(int i = 1,l1,l2,l3,l4,l5;i<=n;i++){
        l1=read(),l2=read(),l3=read(),l4=read(),l5=read();
        for(int a = 0;a<=9;a++){
            if(a==l1)continue;
            if(ans.find(node{a,l2,l3,l4,l5})==ans.end())ans[node{a,l2,l3,l4,l5}]=0;
            ans[node{a,l2,l3,l4,l5}]++;
        }
        for(int a = 0;a<=9;a++){
            if(a==l2)continue;
            if(ans.find(node{l1,a,l3,l4,l5})==ans.end())ans[node{l1,a,l3,l4,l5}]=0;
            ans[node{l1,a,l3,l4,l5}]++;
        }
        for(int a = 0;a<=9;a++){
            if(a==l3)continue;
            if(ans.find(node{l1,l2,a,l4,l5})==ans.end())ans[node{l1,l2,a,l4,l5}]=0;
            ans[node{l1,l2,a,l4,l5}]++;
        }
        for(int a = 0;a<=9;a++){
            if(a==l4)continue;
            if(ans.find(node{l1,l2,l3,a,l5})==ans.end())ans[node{l1,l2,l3,a,l5}]=0;
            ans[node{l1,l2,l3,a,l5}]++;
        }
        for(int a = 0;a<=9;a++){
            if(a==l5)continue;
            if(ans.find(node{l1,l2,l3,l4,a})==ans.end())ans[node{l1,l2,l3,l4,a}]=0;
            ans[node{l1,l2,l3,l4,a}]++;
        }
        for(int a,b,cnt = 1;cnt<=9;cnt++){
            a = (l1+cnt)%10;b = (l2+cnt)%10;
            if(ans.find(node{a,b,l3,l4,l5})==ans.end())ans[node{a,b,l3,l4,l5}]=0;
            ans[node{a,b,l3,l4,l5}]++;
        }
        for(int a,b,cnt = 1;cnt<=9;cnt++){
            a = (l2+cnt)%10;b = (l3+cnt)%10;
            if(ans.find(node{l1,a,b,l4,l5})==ans.end())ans[node{l1,a,b,l4,l5}]=0;
            ans[node{l1,a,b,l4,l5}]++;
        }
        for(int a,b,cnt = 1;cnt<=9;cnt++){
            a = (l3+cnt)%10;b = (l4+cnt)%10;
            if(ans.find(node{l1,l2,a,b,l5})==ans.end())ans[node{l1,l2,a,b,l5}]=0;
            ans[node{l1,l2,a,b,l5}]++;
        }
        for(int a,b,cnt = 1;cnt<=9;cnt++){
            a = (l4+cnt)%10;b = (l5+cnt)%10;
            if(ans.find(node{l1,l2,l3,a,b})==ans.end())ans[node{l1,l2,l3,a,b}]=0;
            ans[node{l1,l2,l3,a,b}]++;
        }
    }
    int Ans=0;
    for(auto i:ans){
        if(i.second==n){
            Ans++;
        }
    }
    cout<<Ans;
    fclose(stdin);
    fclose(stdout);
}