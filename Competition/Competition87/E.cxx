#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#define ls (2*root)
#define rs (2*root+1)
#define mid (l+((r-l)>>1))

using std::cin; using std::cout;
using std::max; using std::swap;
using std::vector; typedef long long ll;
const ll N=2e5+5,P=1e9+7;

struct Block{ ll l,r; }; // 封锁的区间

ll n,m,a[N];  
vector<Block> que[N]; // que[i]保存在 i 时刻，需要解封的区间

struct segment{ 
    ll one,two,len,add,times,block; 
    /*
    one 代表未封锁的和
    two 代表封锁区域的和
    len 代表未封锁元素个数
    add 为加法懒标记     times为乘法懒标记
    block 为目前被封锁次数
    */
};
struct Segment_Tree{
    segment tr[4*N];
    void pushdown(ll root){ // 下传懒标记
        if(tr[ls].block==0){ // 若整个区间被封锁，不能下传懒标记
            tr[ls].one=(tr[ls].one*tr[root].times%P+tr[root].add*tr[ls].len%P)%P;
            tr[ls].add=(tr[ls].add*tr[root].times%P+tr[root].add)%P;
            tr[ls].times=(tr[ls].times*tr[root].times)%P;
        }
        if(tr[rs].block==0){
            tr[rs].one=(tr[rs].one*tr[root].times%P+tr[root].add*tr[rs].len%P)%P;
            tr[rs].add=(tr[rs].add*tr[root].times%P+tr[root].add)%P;
            tr[rs].times=(tr[rs].times*tr[root].times)%P;
        }
        tr[root].add=0,tr[root].times=1;
        return;
    }
    void pushup(ll root){ // 子节点更新父亲
        if(tr[root].block==0){ // 若整个区间被封锁，那么子节点的one没有被修改，不能更新父亲
            tr[root].one=(tr[ls].one+tr[rs].one)%P;
            tr[root].two=(tr[ls].two+tr[rs].two)%P;
            tr[root].len=tr[ls].len+tr[rs].len;
        }// 不过在add等函数中，tr[root].block>0已经return了
        return;
    }
    void build(ll root,ll l,ll r){  // 初始化
        if(l>r) return; 
        tr[root].times=1; // 不要忘了把乘法懒标记初始化
        if(l==r){
            tr[root].one=a[l]%P;
            tr[root].len=1; // 一定不要忘初始未封锁元素个数
            return;
        }
        build(ls,l,mid); build(rs,mid+1,r);
        pushup(root);
        return;
    }
    void add(ll root,ll l,ll r,ll x,ll y,ll z){ // 区间加
        if(l>r||tr[root].block) return;
        if(x<=l&&r<=y){
            tr[root].one=(tr[root].one+tr[root].len*z%P)%P;
            tr[root].add=(tr[root].add+z)%P;
            return;
        } pushdown(root);
        if(x<=mid) add(ls,l,mid,x,y,z);
        if(y>mid) add(rs,mid+1,r,x,y,z);
        return pushup(root);
    }
    void times(ll root,ll l,ll r,ll x,ll y,ll z){ // 区间乘
        if(l>r||tr[root].block) return;
        if(x<=l&&r<=y){
            tr[root].one=(tr[root].one*z)%P;
            tr[root].add=(tr[root].add*z)%P;
            tr[root].times=(tr[root].times*z)%P;
            return;
        } pushdown(root);
        if(x<=mid) times(ls,l,mid,x,y,z);
        if(y>mid) times(rs,mid+1,r,x,y,z);
        return pushup(root);
    }
    void block(ll root,ll l,ll r,ll x,ll y){ // 封锁区间
        if(l>r) return;
        if(x<=l&&r<=y){
            if(l!=r) pushdown(root);
            if(tr[root].block==0){ // 第一次封锁
                tr[root].two=(tr[root].two+tr[root].one)%P;  tr[root].one=0;
                // 封锁整个区间，所以把所有和记到two里，one清零
                tr[root].len=0; // 解锁元素个数为零了          
            }
            ++tr[root].block; // 封锁次数+1，后面解锁时不要改回零，而是-1
            return;
        } pushdown(root);
        if(x<=mid) block(ls,l,mid,x,y);
        if(y>mid) block(rs,mid+1,r,x,y);
        return pushup(root);
    }
    void deblock(ll root,ll l,ll r,ll x,ll y){ //解封区间
        if(l>r) return;
        if(x<=l&&r<=y){
            --tr[root].block;  // 呼应上文++，解除一重封锁
            if(tr[root].block==0){ // 若已经全部解封
                if(l==r) swap(tr[root].one,tr[root].two),tr[root].len=1; // 由于整体解封，原来未解封的变成解封的，没有未解封的元素，因为这里是叶节点所以len=1
                else pushup(root); // 若不是叶节点接受子节点信息即可
            }
            return;
        } pushdown(root);
        if(x<=mid) deblock(ls,l,mid,x,y);
        if(y>mid) deblock(rs,mid+1,r,x,y);
        return pushup(root);
    }
    ll inque(ll root,ll l,ll r,ll x,ll y){ //询问，函数名有点奇怪，但是我习惯了
        if(l>r) return 0;
        if(x<=l&&r<=y) return (tr[root].one+tr[root].two)%P; // 询问整个区间的和，自然包括解封的和未解封的
        pushdown(root); ll ret=0;
        if(x<=mid) ret=inque(ls,l,mid,x,y)%P;
        if(y>mid) ret=(ret+inque(rs,mid+1,r,x,y))%P;
        return ret;
    }
} tree;

int main(){
    std::ios::sync_with_stdio(0); 
    cin>>n>>m; for(ll i=1;i<=n;cin>>a[i],++i);  // 码风较奇怪……
    tree.build(1,1,n);
    for(ll i=1,type,l,r,x;i<=m;++i){
        cin>>type>>l>>r;
        if(type==4){
            cout<<tree.inque(1,1,n,l,r)<<"\n";
            for(Block &j:que[i]) tree.deblock(1,1,n,j.l,j.r); // continue 前，一定要把操作做完啊啊啊，卡了我好久
            continue;
        }  cin>>x;
        if(type==1) tree.add(1,1,n,l,r,x);
        else if(type==2) tree.times(1,1,n,l,r,x);
        else{
            tree.block(1,1,n,l,r);
            que[i+x].push_back({l,r}); // 记录每一次解封操作
        }
        for(Block &j:que[i]) tree.deblock(1,1,n,j.l,j.r); // 于所有操作之后解封，因为 i+x 时刻也是被封锁的
    }
    return 0;
}

