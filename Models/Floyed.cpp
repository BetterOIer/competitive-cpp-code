#include<iostream>
#include<cstring>
#define MAXN 105
#define refer127 2139062143
using namespace std;
int dist[MAXN][MAXN],p[MAXN][MAXN],n,m,q;
/* void out_string(int i,int j){
    if(p[i][j]==-1) return ;
    out_string(i,p[i][j]);
    printf("%d->",p[i][j]);
}
void print(){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(dist[i][j]==refer127){
                printf("    &");
            }else printf("%5d",dist[i][j]);
        }
        puts("");
    }
    puts("");
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            printf("%5d",p[i][j]);
        }
        puts("");
    }
    puts("");
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            printf("%d -> %d",i,j);
            if(dist[i][j]==refer127){
                printf("   No way.  ");
            }else printf("%10d  ",dist[i][j]);
            out_string(i,j);
            printf("%d\n",j);
        }
    }
} */
int main(){
    freopen("Floyed2.in","r",stdin);
    freopen("Floyed2.out","w",stdout);
    memset(p,255,sizeof(p));
    memset(dist,127,sizeof(dist));
    int u,v,w;
    scanf("%d%d%d",&n,&m,&q);
    for(int i = 1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        dist[u][v]=w;
        p[u][v]=u;
    }
    for(int i = 1;i<=n;i++) dist[i][i]=0;
    /* print(); */
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(dist[j][i]!=0&&dist[j][i]!=refer127){
                for(int w = 1;w<=n;w++){
                    if(dist[i][w]!=refer127){
                        if(dist[j][w]>dist[j][i]+dist[i][w]){
                            dist[j][w]=dist[j][i]+dist[i][w];
                            p[j][w]=p[i][w];
                        }
                    }
                }
            }
        }
    } 
    /* for(int i = 1;i<=q;i++){
        scanf("%d%d",&u,&v);
        if(dist[u][v]==refer127){
            printf("No way.\n");
        }else printf("%d\n",dist[u][v]);
    } */
    /* print(); */
    fclose(stdin);
    fclose(stdout);
}