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
bool a[1000005]={1,1};
int b[1000005],k;
void ols(){
	for(long long i=2;i<=1000000;i++)//这个意思是在100001里面找到质数并且标记 ，质数最小是2，所以i=2 
	{
		if (a[i]==0)	b[++k]=i;	//如果没有被标记为1，就是质数。我接下来会讲解为什么是质数。 
		for(long long j=1;j<=k;j++)//j小于当前所有的质数的个数
		{
			if(1ll*i*b[j]>1000000)break;// 如果超出给出的范围，那么就退出循环 
			a[i*b[j]]=1;//用质数数依次×i，结果标记为合数（也就是标记为1）。 
			if(i%b[j]==0)break;//最关键的只标记一次 
		}	
	}
}
int main(){
    ols();
    int t=read();
    while(t--){
        int l=read(),r=read();
        bool flag=true;
        for(int i = 1;i<=k&&b[i]<=r/2&&flag;i++){
            int newL = l/b[i],newR = r/b[i];
            if(newL<=newR&&newR>=2&&newR*b[i]<=r&&newR*b[i]>=l){
                printf("%d %d\n",1*b[i],(newR-1)*b[i]);
                flag=false;
            }
        }
        if(flag){
            printf("-1\n");
        }
    }
    return 0;
}