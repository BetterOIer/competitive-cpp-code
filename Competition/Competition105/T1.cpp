#include<iostream>
using namespace std;
int a,b;
int main(){
    freopen("ensata.in","r",stdin);
    freopen("ensata.out","w",stdout);
	scanf("%d%d",&a,&b);
	if(b>a-2||b==a-3) return printf("%d",a==0&&b==0),0;
	if(b==a-2){
		printf("%d\n1 2\n",a+b);
		for(int i=1;i<=b;i++) printf("%d %d\n%d %d\n",i*2-1,i*2+1,i*2-1,i*2+2);
	}
	if(b<=a-4){
		b++;
		printf("%d\n1 2\n",a+b);
		for(int i=1;i<=b;i++) printf("%d %d\n%d %d\n",i*2-1,i*2+1,i*2-1,i*2+2);
		for(int i=1;i<=a-b-2;i++) printf("%d %d\n",i+b*2+2,b*2-1);
	}
	return 0;
}