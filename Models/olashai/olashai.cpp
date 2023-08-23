#include<iostream>
using namespace std;
bool a[100000001]={1,1};
int b[100000001];//存质数 
int k;
int main()
{
    //freopen("P.in","r",stdin);
    freopen("olashai.out","w",stdout);
	for(int i=2;i<=70;i++)//这个意思是在100001里面找到质数并且标记 ，质数最小是2，所以i=2 
	{
		if (a[i]==0)	b[++k]=i;	//如果没有被标记为1，就是质数。我接下来会讲解为什么是质数。 
		for(int j=1;j<=k;j++)//j小于当前所有的质数的个数
		{
			if(i*b[j]>70)break;// 如果超出给出的范围，那么就退出循环 
			a[i*b[j]]=1;//用质数数依次×i，结果标记为合数（也就是标记为1）。 
			if(i%b[j]==0)break;//最关键的只标记一次 
		}	
	}
    for(int i = 1;i<=k;i++){
        cout<<b[i]<<endl;
    }
    fclose(stdout);
	return 0;
 } 