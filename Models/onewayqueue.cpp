#include<iostream>
#include<deque>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
deque<int>Q1,Q2;
int a[2000005];
int main(){
    int n=read(),k=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
        while(Q1.size()&&Q1.front()<i-k+1)Q1.pop_front();
        while(Q1.size()&&a[Q1.back()]>a[i])Q1.pop_back();
        Q1.push_back(i);
        if(i>=k)printf("%d ",a[Q1.front()]);
    }
    puts("");
    for(int i = 1;i<=n;i++){
        while(Q2.size()&&Q2.front()<i-k+1)Q2.pop_front();
        while(Q2.size()&&a[Q2.back()]<a[i])Q2.pop_back();
        Q2.push_back(i);
        if(i>=k)printf("%d ",a[Q2.front()]);
    }
    return 0;
}