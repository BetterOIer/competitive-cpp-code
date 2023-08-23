#include<iostream>
#include<vector>
using namespace std;
struct node{
    vector<pair<int,int>> to;
    int mxs;
    int size;
    bool visit;
}tree[40004];
int root,mx,n,m;
void getroot(int now,int fa){
    tree[now].size=1,tree[now].mxs=0;
    for(auto i:tree[now].to){
        if(tree[i.first].visit||i.first==fa) continue;
        getroot(i.first,now);
        tree[now].size+=tree[i.first].size;
        tree[now].mxs=max(tree[now].mxs,tree[i.first].size);
    }
    tree[now].mxs=max(tree[now].mxs,n-tree[now].size);
    if(tree[now].mxs<mx){
        root=now;
        mx=tree[now].mxs;
    }
}
int main(){

}