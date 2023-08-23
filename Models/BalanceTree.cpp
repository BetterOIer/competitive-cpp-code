#include<iostream>
using namespace std;
const int N = 1000005;  
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
struct node{
    int s[2];
    int fa;
    int val;
    int cnt;
    int size;
    void init(int fanew,int valnew){
        fa=fanew,val=valnew;
        cnt=size=1;
    }
}tree[N];
int root,n,idx;
void pushup(int pos){
    tree[pos].size=tree[tree[pos].s[0]].size+tree[tree[pos].s[1]].size+tree[pos].cnt;
}
void rotate(int pos){
    int fa=tree[pos].fa,grandfa=tree[fa].fa;
    int fich = tree[fa].s[1]==pos;
    tree[fa].s[fich]=tree[pos].s[fich^1];
    tree[tree[pos].s[fich^1]].fa=fa;
    tree[pos].s[fich^1]=fa;
    tree[fa].fa=pos;
    tree[grandfa].s[tree[grandfa].s[1]==fa]=pos;
    tree[pos].fa=grandfa;
    pushup(fa),pushup(pos);
}
void splay(int pos,int goal){
    while(tree[pos].fa!=goal){
        int fa=tree[pos].fa,grandfa=tree[fa].fa;
        if(grandfa!=goal) ((tree[fa].s[0]==pos)^(tree[grandfa].s[0]==fa))? rotate(pos):rotate(fa);
        rotate(pos);
    }
    if(goal==0) root=pos;
}
void find(int val){
    int pos=root;
    while(tree[pos].s[val>tree[pos].val]&&val!=tree[pos].val)pos=tree[pos].s[val>tree[pos].val];
    splay(pos,0);
}
int get_pre(int val){
    find(val);
    int pos=root;
    if(tree[pos].val<val)return pos;
    pos=tree[pos].s[0];
    while(tree[pos].s[1])pos=tree[pos].s[1];
    return pos;
}
int get_aft(int val){
    find(val);
    int pos=root;
    if(tree[pos].val>val)return pos;
    pos=tree[pos].s[1];
    while(tree[pos].s[0])pos=tree[pos].s[0];
    return pos;
}
void del(int val){
    int pre=get_pre(val);
    int aft=get_aft(val);
    splay(pre,0);splay(aft,pre);
    int del=tree[aft].s[0];
    if(tree[del].cnt>1)tree[del].cnt--,splay(del,0);
    else tree[aft].s[0]=0; 
}
int get_rank(int val){
    find(val);
    return tree[tree[root].s[0]].size;
}
int get_kth(int k){
    int pos=root;
    while(true){
        int fich=tree[pos].s[0];
        if(tree[fich].size+tree[pos].cnt<k){
            k-=(tree[fich].size+tree[pos].cnt);
            pos=tree[pos].s[1];
        }else{
            if(tree[fich].size>=k)pos=tree[pos].s[0];
            else break;
        }
    }
    splay(pos,0);
    return tree[pos].val;
}
void insert(int val){
    int pos=root,fa=0;
    while(pos&&tree[pos].val!=val) fa=pos,pos=tree[pos].s[val>tree[pos].val];
    if(pos)tree[pos].cnt++;
    else{
        pos=++idx;
        tree[fa].s[val>tree[fa].val]=pos;
        tree[pos].init(fa,val);
    }
    splay(pos,0);
}
int main(){
    insert(-1e9);insert(1e9);
    n=read();
    while(n--){
        int opt=read(),num=read();
        if(opt==1)insert(num);
        if(opt==2)del(num);
        if(opt==3)cout<<get_rank(num)<<endl;
        if(opt==4)cout<<get_kth(num+1)<<endl;
        if(opt==5)cout<<tree[get_pre(num)].val<<endl;
        if(opt==6)cout<<tree[get_aft(num)].val<<endl;
    }
    return 0;
}