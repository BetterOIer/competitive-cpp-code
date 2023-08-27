#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = (j); i <= (k); i ++)
#define frep(i, j, k) for(int i = (j); i >= (k); i --)
#define mrep(i, h, j) for(int i = (h[j]); ~i; i = ne[i])
#define mset(a, v) memset(a, v, sizeof(a))
#define mcpy(a, v) memcpy(a, v, sizeof(a))

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010, M = N << 2;
int n, m, K, mx, S, T;
int h[N], e[M], ne[M], idx;
int dep[N], cnt[N];
bool st[N], col[N];
vector<int> v, res1, res2;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

//找最小环
void dfs(int u){
    v.push_back(u);
    dep[u] = v.size();
    mrep(i, h, u){
        int j = e[i];
        if(!dep[j]) dfs(j);
        else if(dep[j] == dep[u] - 1) cnt[u] ++;
        if(dep[j] < dep[u] - 1 || cnt[u] == 2){
            int t = dep[u] - dep[j] + 1;
            if(t <= K){
                printf("2\n%d\n", t);
                rep(k, dep[j] - 1, dep[u] - 1) printf("%d ", v[k]);
                exit(0);
            }
            else if(t <= mx){
                mx = t;
                S = u, T = j;
            }
        }
    }
    v.pop_back();
}

//输出独立集
void dfs1(int u){
    v.push_back(u);
    dep[u] = v.size();
    if(u == T){
        puts("1");
        for(int k = 0; k < K; k += 2) printf("%d ", v[k]);
        exit(0);
    }
    mrep(i, h, u){
        int j = e[i];
        if(u == S && j == T) continue;
        if(!dep[j]) dfs1(j);
    }
    v.pop_back();
}

//树的情况
void dfs2(int u){
    st[u] = true;
    if(col[u]) res1.push_back(u);
    else res2.push_back(u);
    mrep(i, h, u){
        int j = e[i];
        if(!st[j]){
            col[j] = !col[u];
            dfs2(j);
        }
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &K);
    mset(h, -1);
    while(m --){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    mx = n;
    dfs(1);
    if(S){
        mset(dep, 0);
        dfs1(S);
    }
    puts("1");
    dfs2(1);
    int t = (K + 1) / 2;
    if(res1.size() >= t){
        rep(i, 0, t - 1) printf("%d ", res1[i]);
    }
    else{
        rep(i, 0, t - 1) printf("%d ", res2[i]);
    }
    return 0;
}
