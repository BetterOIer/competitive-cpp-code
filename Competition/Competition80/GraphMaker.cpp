#include<testlib.h>
#include<bits/stdc++.h>

using namespace std;

int main(int argc,char* argv[]){
    registerGen(argc, argv, 1);//初始化数据生成器

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int t = atoi(argv[3]);
    int left = m-n+1;
    /* vector<int>fa(n);
    for(int i = 0; i < n; ++i)
    if (i > 0)
        fa[i] = i-1; */
    
    printf("%d %d\n",n,m);

    vector<int> node(n);
    for(int i = 0; i < n; ++i)
        node[i] = i+1;
    shuffle(node.begin(), node.end());

    vector<pair<int,int> > edges;
    set<pair<int,int> > inv;
    for (int i = 0; i+1 < n; i++)
        edges.push_back(make_pair(node[i], node[i+1]));
    
    for (int i = 1; i <= left; i++){
        int node1 = rnd.next(2,n-1);
        int node2 = node1==2? 0:rnd.wnext(node1-2,t);
        if(inv.find(make_pair(node[node2], node[node1]))==inv.end()){
            edges.push_back(make_pair(node[node2], node[node1]));
            inv.insert(make_pair(node[node2], node[node1]));
        }else i--;
    }
    shuffle(edges.begin(), edges.end());

    for (auto i:edges)
        printf("%d %d\n", i.first, i.second);
    
}
 