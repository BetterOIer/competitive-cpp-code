// 测试一下正解正确性
#include <iostream>
#include <cstdio>
using namespace std;
struct modein
{
    modein operator>>(int &x)
    {
        x = 0;
        char c = getchar();
        while (c < '0' || c > '9')
            c = getchar();
        while (c >= '0' && c <= '9')
            x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
        return (modein){};
    }
} qin;
const long long mod = 998244353;
struct edge
{
    int next, to, v[2];
    bool usd[2];
    int &operator[](int x) { return x < 2 ? v[x] : to; }
    bool &operator()(bool x) { return usd[x]; }
} e[1000010];
int head[1000010], v[1000010], is[1000010], cnt = 1, n, m, t;
bool now;
long long inv[1000010], onv[1000010], dp[1000010][2], res;
long long o[2], u[2], goin[1000010], cs[1000010][2];
void add(int a, int b)
{
    goin[a]++, goin[b]++;
    e[++cnt][2] = b;
    e[cnt].next = head[a];
    is[head[a] = cnt] = t;
    e[++cnt][2] = a;
    e[cnt].next = head[b];
    is[head[b] = cnt] = t;
}
long long qk(long long a, long long b)
{
    long long ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod, b >>= 1;
    }
    return ret;
}
long long c(int a, int b)
{
    return onv[b] * inv[a] % mod * inv[b - a] % mod;
}
long long got(int i, int k)
{
    return c(k, t) * v[i] % mod * qk(u[0], k) % mod * qk(u[1], t - k) % mod;
}
void dfs(int p, int f, int c)
{
    if (goin[p] > 2)
        return;
    for (int i = head[p]; i; i = e[i].next)
        if (e[i][2] != f)
            is[i] = c, dfs(e[i][2], p, c + 1);
}
int main()
{
    freopen("masses.in", "r", stdin);
    freopen("masses.out", "w", stdout);
    qin >> n >> m >> t, scanf("%lld/%lld", &o[0], &o[1]);
    u[0] = o[0] * qk(o[1], mod - 2) % mod, u[1] = (o[1] - o[0]) * qk(o[1], mod - 2) % mod;
    for (int i = 1; i <= n; i++)
        qin >> v[i];
    onv[0] = 1;
    for (int i = 1, a, b; i <= m; i++)
        qin >> a >> b, add(a, b);
    for (int i = 1; i <= t; i++)
        onv[i] = onv[i - 1] * i % mod;
    inv[t] = qk(onv[t], mod - 2);
    for (int i = t - 1; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
    for (int i = 1; i <= n; i++)
        if (goin[i] == 1)
            dfs(i, i, 0);
    for (int k = t - 1; ~k; k--, now = !now)
    {
        for (int i = 1; i <= n; i++)
            cs[i][now] = dp[i][now] = 0;
        for (int i = 1; i <= cnt; i++)
            e[i](now) = false;
        for (int i = 1; i <= n; i++)
            for (int r = head[i]; r; r = e[r].next)
            {
                if (is[r] >= k)
                {
                    if (e[r ^ 1](!now))
                    {
                        e[r][now] = (dp[e[r][2]][!now] * cs[e[r][2]][!now] % mod - e[r ^ 1][!now] + mod) % mod;
                        e[r][now] = (e[r][now] * qk(cs[e[r][2]][!now] - 1, mod - 2) % mod + got(e[r][2], k + 1)) % mod;
                    }
                    else
                        e[r][now] = (dp[e[r][2]][!now] + got(e[r][2], k + 1)) % mod;
                    dp[i][now] = (dp[i][now] + e[r][now]) % mod, cs[i][now]++, e[r](now) = true;
                }
                else if (goin[i] == 1)
                    dp[i][now] = (dp[i][now] + dp[i][!now] + got(i, k + 1)) % mod, cs[i][now] = 1;
            }
        for (int i = 1; i <= n; i++)
            dp[i][now] = dp[i][now] * qk(cs[i][now], mod - 2) % mod;
    }
    for (int i = 1; i <= n; i++)
        res = (res + dp[i][!now] + got(i, 0)) % mod;
    return !(cout << res * qk(n, mod - 2) % mod);
}
