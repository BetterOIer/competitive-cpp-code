#include<testlib.h>
#include<bits/stdc++.h>

using namespace std;

int main(int argc,char* argv[]){
    registerGen(argc, argv, 1);//初始化数据生成器

    int n = atoi(argv[1]);
    int t = atoi(argv[2]);

    vector<int> p(n);

    //给 1..n-1 号点设置父亲
    for(int i = 0; i < n; ++i)
        if (i > 0)
            p[i] = rnd.wnext(i, t);

    printf("%d\n", n);

    //打乱节点排序
    vector<int> perm(n);
    for(int i = 0; i < n; ++i)
        perm[i] = i;
    shuffle(perm.begin() + 1, perm.end());

    // 随机加边
    vector<pair<int,int> > edges;
    for (int i = 1; i < n; i++)
        if (rnd.next(2))
            edges.push_back(make_pair(perm[i], perm[p[i]]));
        else
            edges.push_back(make_pair(perm[p[i]], perm[i]));

    //打乱边的顺序
    shuffle(edges.begin(), edges.end());

    for (int i = 0; i + 1 < n; i++)
        printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);
}