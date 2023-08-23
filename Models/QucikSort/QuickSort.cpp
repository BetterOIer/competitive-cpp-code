#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int a[1000000],n;
void swap(int c,int d){
	if(c==d){
		return;
	}
	a[c] = a[c]^a[d];
	a[d] = a[c]^a[d];
	a[c] = a[c]^a[d];
	//cout<<endl;
	//for(int i = 1;i<=n;i++){
	//	cout<<a[i-1]<<" ";
	//}
}
void fastsort(const int L,const int R){
	if(L>=R){
		return;
	}
	int i = L-1,j = R+1,w = rand()%(R-L+1)+L;
	const int m = a[w];
	int k = L;
	while(k<j){
		if(a[k]< m){
			if(i+1!=k){
				swap(k,i+1);
			}
			i++,k++;
		}else if(a[k]==m){
			k++;
		}else if(a[k]>m){
			swap(k,j-1);
			j--;
		}
	}
	fastsort(L,i);
	fastsort(j,R);
}
int main(){
	int ans = 0;
	cin>>n;
	srand((unsigned)time(NULL));
	for(int i = 1;i<=n;i++){
		//cin>>a[i-1];
		a[i-1]=rand();
	}
	//cout<<endl;
	//for(int i = 1;i<=n;i++){
	//	cout<<'F'<<a[i-1]<<" ";
	//}
	fastsort(0,n-1);
	//cout<<endl;
	for(int i = 1;i<=n;i++){
		cout<<a[i-1]<<" ";
	}
}
