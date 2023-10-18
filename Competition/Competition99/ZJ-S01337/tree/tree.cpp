#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,m,q;
vector<int>trMod[10005],trHuge[10005];
int fa[10005][20],dep[10005],siz[10005],tot;
int ids[10005];
struct node{
    int sonHead;
    int dadTail;
    int idFrom;
};
node tr[10005];
int faHugeTr[10005][20],sizHugeTr[10005],depHugeTr[10005],dis[10005];
int dfs(int pos,int fat){
    fa[pos][0]=fat;
    dep[pos]=dep[fat]+1;
    int res= 1;
    for(int i :trMod[pos]){
        if(i==fat)continue;
        res+=dfs(i,pos);
    }
    return siz[pos]=res;
}
int dfsHugTree(int pos,int fat){
    faHugeTr[pos][0]=fat;
    depHugeTr[pos]=depHugeTr[fat]+1;
    dis[pos] = dis[fat]+dep[tr[pos].dadTail-tr[fat].idFrom+tr[fat].sonHead]-dep[tr[fat].sonHead];
    int res= 1;
    for(int i :trHuge[pos]){
        if(i==fat)continue;
        res+=dfs(i,pos);
    }
    return sizHugeTr[pos]=res;
}
void LCA(int a,int b,int pla,int plb,int &lca, int &plLca){
    int aMod,bMod,faIdFrom,tmp;
    if(pla==plb){
        aMod = a;bMod = b;faIdFrom = tr[pla].idFrom;
    }else{
        if(depHugeTr[pla]<depHugeTr[plb])swap(pla,plb),swap(a,b);
        tmp = 20;
        while(depHugeTr[pla]>depHugeTr[plb]){
            if(depHugeTr[faHugeTr[pla][tmp]]>=depHugeTr[plb])pla=faHugeTr[pla][tmp];
            tmp--;
        }
        tmp=20;
        while(faHugeTr[pla][tmp]!=faHugeTr[plb][tmp]){
            pla=faHugeTr[pla][tmp],plb=faHugeTr[plb][tmp];
            tmp--;
        }
        aMod = tr[pla].dadTail,bMod = tr[plb].dadTail,faIdFrom =tr[faHugeTr[pla][0]].idFrom;
    }
    aMod=aMod-faIdFrom+1;
    bMod=bMod-faIdFrom+1;
    if(dep[aMod]<dep[bMod])swap(aMod,bMod);
    tmp = 20;
    while(dep[aMod]>dep[bMod]){
        if(dep[fa[aMod][tmp]]>=dep[bMod])aMod=faHugeTr[aMod][tmp];
        tmp--;
    }
    tmp=20;
    while(fa[aMod][tmp]!=fa[bMod][tmp]){
        aMod=fa[aMod][tmp],bMod=fa[bMod][tmp];
        tmp--;
    }
    lca = fa[aMod][0];
    plLca = faHugeTr[pla][0];
}
int getDis(int a,int pla){
    return dis[pla]+dep[a-tr[pla].idFrom+tr[pla].sonHead]-dep[fa[tr[pla].sonHead][0]];
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read(),m=read(),q=read();
    for(int i = 1,u,v;i<n;i++){
        u=read(),v=read();
        trMod[u].push_back(v);
        trMod[v].push_back(u);
    }
    dfs(1,0);tot=n;
    for(int i = 1;i<20;i++){
        for(int j = 1;j<=n;j++){
            fa[j][i]=fa[fa[j][i-1]][i-1];
        }
    }
    tr[1].dadTail=0,tr[1].idFrom=1,tr[1].sonHead=1;
    for(int i = 2;i<=m+1;i++){
        tr[i].sonHead=read(),tr[i].dadTail=read();int faPos = lower_bound(ids+1,ids+i,tr[i].dadTail)-ids-1;
        tr[i].idFrom=ids[i]=tot+1;tot+=siz[tr[i].sonHead];
        trHuge[i].push_back(faPos);trHuge[faPos].push_back(i);
    }
    dfsHugTree(1,0);
    for(int i = 1;i<20;i++){
        for(int j = 1;j<=m+1;j++){
            faHugeTr[j][i]=faHugeTr[faHugeTr[j][i-1]][i-1];
        }
    }
    for(int i = 1,a,b;i<=q;i++){
        a=read(),b=read();
        int pla = lower_bound(ids+1,ids+m+2,a)-ids-1;
        int plb = lower_bound(ids+1,ids+m+2,b)-ids-1;
        int lca,plLca;
        LCA(a,b,pla,plb,lca,plLca);
        int aDis = getDis(a,pla);
        int bDis = getDis(b,plb);
        int lcaDis = getDis(lca,plLca);
        cout<<aDis+bDis-2*lcaDis<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}