#include<iostream>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int tot=0;
int num[1000001];
void del(){
    int po=1,next;
    num[1]=num[tot--];
    while(po*2<=tot){
        next=po*2;
        if(next<tot&&num[next+1]<num[next])next++;
        if(num[po]<=num[next])break;
        swap(num[po],num[next]);
        po=next;
    }
}
void join(int x){
    num[++tot]=x;
    int po=tot;
    while(num[po]<num[po>>1]){
        swap(num[po],num[po>>1]);
        po>>=1;
    }
}
int main(){
    int n=read(),opt,x;
    while(n--){
        opt=read();
        if(opt==1){
            x=read();
            join(x);
        }else if(opt==2) cout<<num[1]<<endl;
        else if(opt==3) del();
    }
    return 0;
}