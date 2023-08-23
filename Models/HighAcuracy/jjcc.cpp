#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
int A[N],B[N],C[N],la,lb,lc; 
/* 高精加 */
void add(int A[],int B[],int C[]){
	for(int i = 0;i<lc;i++){
		C[i]+=A[i]+B[i];
		C[i+1]=C[i]/10;
		C[i]%=10;
	}
	if(C[lc])lc++;
}
/* 高精减 */
bool cmp(int A[],int B[]){
	for(int i = la-1;~i;i--)if(A[i]!=B[i])return A[i]>B[i];
	return true;
}
void sub(int A[],int B[],int C[]){
	for(int i = 0;i<lc;i++){
		if(A[i]<B[i])A[i+1]--,A[i]+=10;
		C[i]=A[i]-B[i];
	}
	while(lc&&C[lc]==0)lc--;
}
/* 高精乘 */
void mul(int A[],int B[],int C[]){
	for(int i = 0;i<la;i++){
		for(int j =0;j<lb;j++){
			C[i+j]+=A[i]*B[j];
			C[i+j+1]+=C[i+j]/10;
			C[i+j]%=10;
		}
	}
	while(lc&&C[lc]==0)lc--;
}
/* 高精除 */
void div(int A[],int b,int C[]){
	long long r=0;
	for(int i = la-1;~i;i--){
		r=(r<<1)+(r<<3)+A[i];
		C[la-i-1] = r/b;
		r%=b;
	}
	reverse(C,C+lc);
	while(lc&&C[lc]==0)lc--;
}
int main(){
	string a,b;
	cin>>a>>b;
	la=a.length(),lb=b.length(),lc=max(la,lb);
	for(int i = la-1;~i;i--)A[la-i-1]=a[i]-'0';
	for(int i = lb-1;~i;i--)B[lb-i-1]=b[i]-'0';
	/* 高精加 */
	add(A,B,C);
	/* 高精减 */
	if(cmp(A,B))swap(A,B),cout<<'-';
	sub(A,B,C);
	/* 高精乘 */
	lc=la+lb;
	mul(A,B,C);
	/* 高精除 */
	int bb;
	cin>>bb;
	lc=la=a.size();
	div(A,bb,C);
	
	for(int i = lc-1;~i;i--)cout<<C[i];
    return 0;
}