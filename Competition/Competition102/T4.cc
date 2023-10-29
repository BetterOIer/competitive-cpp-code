// I can't understand the solution nor the video
// So I choose to submit the STD!!!

#include <cstdio>
#include <vector>
#include <ctime>
#include <cstring>
#include <algorithm>
#define ull unsigned long long
using std::vector;
typedef vector<int> poly;
const int N=1000005, MOD=998244353;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return mval(x+MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

int iv[N], iiv[N], fac[N], tp;
namespace iobuff{
	const int LEN=1000000;
	char in[LEN+5], out[LEN+5];
	char *pin=in, *pout=out, *ed=in, *eout=out+LEN;
	inline char gc(void)
	{
		return pin==ed&&(ed=(pin=in)+fread(in, 1, LEN, stdin), ed==in)?EOF:*pin++;
	}
	inline void pc(char c)
	{
		pout==eout&&(fwrite(out, 1, LEN, stdout), pout=out);
		(*pout++)=c;
	}
	inline void flush()
	{ fwrite(out, 1, pout-out, stdout), pout=out; }
	template<typename T> inline void scan(T &x)
	{
		static int f;
		static char c;
		c=gc(), f=1, x=0;
		while(c<'0'||c>'9') f=(c=='-'?-1:1), c=gc();
		while(c>='0'&&c<='9') x=10*x+c-'0', c=gc();
		x*=f;
	}
	template<typename T> inline void putint(T x, char div)
	{
		static char s[15];
		static int top;
		top=0;
		x<0?pc('-'), x=-x:0;
		while(x) s[top++]=x%10, x/=10;
		!top?pc('0'), 0:0;
		while(top--) pc(s[top]+'0');
		pc(div);
	}
}
using namespace iobuff;
inline void init(void) { tp=2; iv[0]=iv[1]=iiv[0]=iiv[1]=1, fac[0]=fac[1]=1; }
inline void ext(int x)
{
	for(; tp<=x; ++tp)
	{
		iv[tp]=MOD-1ll*(MOD/tp)*iv[MOD%tp]%MOD;
		iiv[tp]=1ll*iiv[tp-1]*iv[tp]%MOD;
		fac[tp]=1ll*fac[tp-1]*tp%MOD;
	}
}
namespace Poly{
	namespace Poly_Basic{
		inline void print(const poly &a) { for(int x:a) printf("%d ", x); puts(""); }
		inline void printbuff(const poly &a) { for(int x:a) putint(x, ' '); pc('\n'); }
		inline poly to_poly(int *a, int n) { poly ret; ret.resize(n); memcpy((int*)&ret[0], a, sizeof(int)*n); return ret; }
		inline poly slice(const poly &a, int s, int t)
		{ poly ret(t-s); memcpy((int*)&ret[0], (int*)&a[s], sizeof(int)*(t-s)); return ret; }
		inline poly add(const poly &a, const poly &b)
		{
			poly ret(std::max(a.size(), b.size()));
			for(int i=0; i<ret.size(); ++i) ret[i]=mval((i<a.size()?a[i]:0)+(i<b.size()?b[i]:0));
			return ret;
		}
		inline void add_to(poly &a, const poly &b)
		{
			if(a.size()<b.size()) a.resize(b.size());
			for(int i=0; i<b.size(); ++i) inc(a[i], b[i]);
		}
		inline poly neg(poly a)
		{
			for(int i=0; i<a.size(); ++i) a[i]=MOD-a[i];
			return a;
		}
		inline poly mul(poly a, int x)
		{
			for(int i=0; i<a.size(); ++i) a[i]=1ll*a[i]*x%MOD;
			return a;
		}
		inline void mul_val(poly &a, int x)
		{
			for(int i=0; i<a.size(); ++i) a[i]=1ll*a[i]*x%MOD;
		}
		inline poly deri(poly a)
		{
			for(int i=0; i<a.size()-1; ++i) a[i]=1ll*a[i+1]*(i+1)%MOD;
			a.pop_back();
			return a;
		}
		inline poly intg(poly a)
		{
			a.push_back(0);
			if(tp<a.size()) ext(a.size());
			for(int i=a.size()-1; i; --i) a[i]=1ll*iv[i]*a[i-1]%MOD;
			a[0]=0;
			return a;
		}
		inline int calc(const poly &a, int p)
		{
			int ret=0;
			for(int i=0, x=1; i<a.size(); ++i, x=1ll*x*p%MOD) inc(ret, 1ll*a[i]*x%MOD);
			return ret;
		}
	}
	using namespace Poly_Basic;
	namespace NTT{
		const int g=3;
		int A[N], B[N], C[N], rev[N], wn[N], up=1;
		inline int glim(int n)
		{
			int l=0;
			while(n) n>>=1, ++l;
			return l;
		}
		inline void init(int l)
		{
			for(int i=1; i<(1<<l); ++i) rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
			for(int i=up; i<(1<<l); i<<=1)
			{
				wn[i]=1;
				int mw=qpow(g, (MOD-1)/(i<<1));
				for(int j=1; j<i; ++j) wn[i+j]=1ll*wn[i+j-1]*mw%MOD;
			}
			if((1<<l)>up) up=(1<<l);
		}
		void ntt(int *a, int n, int mod)
		{
			static ull f[N];
			std::copy(a, a+n, f);
			for(int i=0; i<n; ++i) if(i<rev[i]) std::swap(f[i], f[rev[i]]);
			for(int len=2; len<=n; len<<=1)
			{
				int c=len>>1;
				for(int i=0; i<n; i+=len) for(int j=i; j<i+c; ++j)
				{
					ull t=f[j+c]*wn[c+j-i]%MOD;
					f[j+c]=f[j]-t+MOD, f[j]+=t;
				}
			}
			for(int i=0; i<n; ++i) f[i]%=MOD;
			if(mod)
			{
				std::reverse(f+1, f+n);
				int iv=qpow(n, MOD-2);
				for(int i=0; i<n; ++i) f[i]=1ll*f[i]*iv%MOD;
			}
			std::copy(f, f+n, a);
		}
		inline void ntt1(int *f, int n, int mod, int t)
		{
			for(int i=0; i<n; ++i) if(i<rev[i]) std::swap(f[i], f[rev[i]]);
			for(int len=2; len<=n; len<<=1)
			{
				int c=len>>1;
				for(int i=0; i<n; i+=len) for(int j=i; j<i+c; ++j)
				{
					int x=f[j], y=1ll*f[j+c]*wn[((c+j-i)<<1)+t]%MOD;
					f[j]=mval(x+y), f[j+c]=mval(MOD+x-y);
				}
			}
			if(mod)
			{
				std::reverse(f+1-t, f+n);
				int iv=qpow(n<<1, MOD-2);
				for(int i=0; i<n; ++i) f[i]=1ll*f[i]*iv%MOD;
			}
		}
		template <class _T, class _T1, class _T2> inline void mul(const _T &a, const _T1 &b, _T2 &c, int n, int m)
		{
			if(std::max(n, m)<=128)
			{
				for(int i=0; i<=n; ++i) for(int j=0; j<=m; ++j) c[i+j]=(c[i+j]+1ll*a[i]*b[j])%MOD;
				return;
			}
			int l=glim(n+m);
			init(l);
			memcpy(A, (int*)&a[0], sizeof(int)*(n+1));
			memcpy(B, (int*)&b[0], sizeof(int)*(m+1));
			std::fill(A+n+1, A+(1<<l)+1, 0);
			std::fill(B+m+1, B+(1<<l)+1, 0);
			ntt(A, (1<<l), 0), ntt(B, (1<<l), 0);
			for(int i=0; i<(1<<l); ++i) C[i]=1ll*A[i]*B[i]%MOD;
			ntt(C, (1<<l), 1);
			memcpy((int*)&c[0], C, sizeof(int)*(n+m+1));
		}
		inline poly mul(const poly &a, const poly &b)
		{
			if(!a.size()||!b.size()) return poly(0);
			poly ret(a.size()+b.size()-1);
			mul(a, b, ret, a.size()-1, b.size()-1);
			return ret;
		}
	}
	using NTT::init;
	using NTT::ntt;
	using NTT::glim;
	using NTT::mul;
}
using namespace Poly;
int t, n, q;
inline void conv(int &x, int &y)
{
	int a=x-y, b=x+y;
	x=a, y=b;
}
poly solve(int l)
{
	if(l==1) return {1, 1};
	poly ret=solve(l>>1);
	ret=mul(ret, ret);
	for(int i=n; i<ret.size(); ++i) inc(ret[i-n], ret[i]);
	if(ret.size()>n) ret.resize(n);
	if(l&1)
	{
		ret.push_back(0);
		for(int i=ret.size()-1; i; --i) inc(ret[i], ret[i-1]);
		if(ret.size()>n) inc(ret[0], ret[n]), ret.pop_back();
	}
	return ret;
}
poly f;
inline int reg(int x) { return (x%n+n)%n; }
inline int calc(int x, int y, int x1, int y1)
{
	conv(x, y), conv(x1, y1);
	x=x1-x, y=y1-y;
	if(((x+t)&1)||((y+t)&1)) return 0;
	int ret=1ll*f[reg((t+x)/2)]*f[reg((t+y)/2)]%MOD;
	return ret;
}
inline int C(int n, int m) { return 1ll*fac[n]*iiv[m]%MOD*iiv[n-m]%MOD; }
int main()
{
	freopen("typical.in","r",stdin);
    freopen("typical.out","w",stdout);
	scanf("%d%d%d", &n, &t, &q);
	n+=2;
	int rn=n;
	n*=2;
	init();
	f=solve(t);
	f.resize(n);
	for(int i=1, x, y, x1, y1; i<=q; ++i)
	{
		scan(x), scan(y), scan(x1), scan(y1);
		++x, ++y, ++x1, ++y1;
		int ans=calc(x, y, x1, y1);
		inc(ans, calc(x, y, -x1, -y1));
		inc(ans, calc(x, y, n-x1, -y1));
		inc(ans, calc(x, y, x1, y1-n));
		dec(ans, calc(x, y, n-x1, y1));
		dec(ans, calc(x, y, x1, n-y1));
		dec(ans, calc(x, y, -x1, y1));
		dec(ans, calc(x, y, x1, -y1));
		putint(ans, '\n');
	}
	fprintf(stderr, "time: %d\n", clock());
	flush();
	return 0;
}