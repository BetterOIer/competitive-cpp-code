#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#define ull unsigned long long 
using namespace std;
FILE *Finn,*Fout,*Fstd,*Fres;
const int N=5005;
int n,c,ans,a[N],b[N];
char ch[N*10];
void Return(double p,char *s){
	fprintf(Fres,"%.3lf\n%s",p,s);
	exit(0);
}
int	main(int args, char** argv){
	Finn=fopen(argv[1],"r");
	Fstd=fopen(argv[2],"r");
	Fout=fopen(argv[3],"r");
	Fres=fopen(argv[4],"w");
	
	fscanf(Finn,"%d%d",&n,&c);
	for(int i=1;i<=n;i++)fscanf(Finn,"%d",&a[i]);
	for(int i=1;i<=n;i++)fscanf(Finn,"%d",&b[i]);
	fscanf(Fout,"%s",ch);
	int t1=1,t2=1;
	for(int i=0;i<=2*(n-1);i++){
		if(t1>n||t2>n)Return(0,"WA");
		ans+=a[t1]*b[t2]%c;
		if(ch[i]=='D')t1++; else if(ch[i]=='R')t2++; else if(i<2*(n-1))Return(0,"WA");
	}
	int t;
	fscanf(Fstd,"%d",&t);
	if(ans>t)Return(2,"NOIP 1200"); else
	if(ans==t)Return(1,"NOIP AK");
	else if(ans*5>=t*4)Return(0.2,"NOIP 500+");
	else Return(0,"NOIP 1=");
}
