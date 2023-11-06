#include <iostream>
#include <cstring>
using namespace std;
long long n, m, p, q, a1, a2, ans;
struct mat{
	long long m[4][4];
}squ1, squ2;
inline void init() {
	squ1.m[1][1] = a2, squ1.m[1][2] = a1;
	squ2.m[1][1] = p, squ2.m[2][1] = q, squ2.m[1][2] = 1;
}
inline mat mul(mat a, mat b) {
	mat res;
	memset(res.m, 0, sizeof(res.m));
	for(int i=1; i<=2; i++) {
		for(int j=1; j<=2; j++) {
			for(int k=1; k<=2; k++) {
				res.m[i][j] += (a.m[i][k] % m) * (b.m[k][j] % m);
				res.m[i][j] %= m;
			}
		}
	}
	return res;
}
inline void Qmat_pow(int p) {
	while (p) {
		if(p & 1) squ1 = mul(squ1, squ2);
		squ2 = mul(squ2, squ2);
		p >>= 1;
	}
}

int main() {
	scanf("%lld",&n);a1=1,a2=2,p=1,q=1,m=100000000;
	if(n == 1) {cout<<a1;return 0;}
	if(n == 2) {cout<<a2;return 0;}
	squ1.m[1][1] = a2, squ1.m[1][2] = a1;
	squ2.m[1][1] = p, squ2.m[2][1] = q, squ2.m[1][2] = 1;
	Qmat_pow(n-2);
	ans = squ1.m[1][1];
	ans %= m;
	printf("%lld", ans);
}