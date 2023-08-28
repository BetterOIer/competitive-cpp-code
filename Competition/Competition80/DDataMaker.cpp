#include<testlib.h>
#include<bits/stdc++.h>

using namespace std;
int start[300005],sm_n,ind_n;
int now[300005];
int num[300005];
int cont[300005];
vector<int>bell[300005];
int rand_node(int bel){
    return bell[bel][rnd.next(bell[bel].size())];
}
int main(int argc,char* argv[]){
    registerGen(argc, argv, 1);//初始化数据生成器

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int circleCount = m-n+1;
    int t = atoi(argv[3]);
    /* int n = 20;
    int m = 30;
    int circleCount = m-n+1;
    int t = 0; */
    
    printf("%d %d\n",n,m);

    vector<int> node(n);
    for(int i = 0; i < n; ++i)
        node[i] = i+1;
    shuffle(node.begin(), node.end());
    bool not_ok=true;
    while(not_ok){
        int tmp=m-circleCount+1;
        for(int i = 1;i<circleCount;i++){
            num[i]=rnd.next(1,tmp);
            tmp-=num[i];
            if(tmp==0&&i<circleCount){
                tmp=m-circleCount+1,i=0;
            }
        }
        num[circleCount]=tmp;
        not_ok=false;
        for(int i = 1;i<=circleCount;i++){
            if(num[i]<=2){not_ok=true;break;}
        }
    }
    vector<int> belong(n);
    for(int i = 0; i < n; ++i){
        belong[i] = rnd.next(1,circleCount);
        if(cont[belong[i]]==num[belong[i]]){
            i--;
        }else{
            cont[belong[i]]++;
            bell[belong[i]].push_back(i);
        }
    }
    
    vector<pair<int,int> > edges;
    memset(start,-1,sizeof start);
    for (int i = 0; i < n; i++){
        if(start[belong[i]]==-1)start[belong[i]]=now[belong[i]]=i;
        else {
            m--;
            edges.push_back(make_pair(node[now[belong[i]]], node[i]));
            now[belong[i]]=i;
        }
    }
    for(int i = 1;i<=circleCount;i++){
        if(start[i]==now[i]) {
            ind_n++,sm_n++;
            continue;
        }
        else{
            edges.push_back(make_pair(node[now[i]], node[start[i]])),m--,sm_n++;
        }
    }
    /* for (auto i:edges)
        printf("%d %d\n", i.first, i.second); */
    if(sm_n-1!=m){
        return puts("Err"),0;
    }
    vector<int> p(sm_n);

    //给 1..n-1 号点设置父亲
    for(int i = 0; i < sm_n; ++i)
        if (i > 0)
            p[i] = rnd.wnext(i, t);
    
    vector<int> perm(sm_n);
    for(int i = 0; i < sm_n; ++i)
        perm[i] = i;
    shuffle(perm.begin() + 1, perm.end());
    for (int i = 1; i < sm_n; i++)
        if (rnd.next(2))
            edges.push_back(make_pair(node[rand_node(perm[i]+1)], node[rand_node(perm[p[i]]+1)]));
        else
            edges.push_back(make_pair(node[rand_node(perm[p[i]]+1)], node[rand_node(perm[i]+1)]));
    
    shuffle(edges.begin(), edges.end());

    for (auto i:edges)
        printf("%d %d %d %d\n", i.first, i.second,rnd.next(1,10000),rnd.next(1,10000));

}
 