#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
inline int read(){
    int x=0,f=1;char c = getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x = (x<<1)+(x<<3)+(c^48);
    return x*f;
}
int c,t;
struct node{
    int rel;/* 与上一个位置的关系 */
    int pos;/* 上一个位置 */
    int fir=-1;/* 已确定的值 */
}sta[100005];
int n,m,ans=0;
int cfLis[100005];
int instk[100005];
bool oked[100005];
queue<int>Q;
/* int dfs(int pos,int root,int rel){
    oked[pos]=true;
    if(sta[pos].fir!=-1){
        return sta[pos].fir;
    }
    if(sta[pos].pos==root){
        if(rel!=sta[pos].rel){
            return sta[pos].fir=2;
        }
        else return sta[pos].fir=0;
    }
    sta[pos].fir=dfs(sta[pos].pos,root,rel*sta[pos].rel);
    return sta[pos].fir;
} */
/* else if(sta[cfLis[i]].rel==1){
                        sta[cfLis[i]].fir=0;
                        cled++;
                        cfLis[i]=cfLis[tot];--tot,--i;
                    } */
void delCir(){
    for(int i = 1;i<=n;i++){
        if(oked[i])continue;
        Q.push(cfLis[i]),instk[cfLis[i]]=sta[cfLis[i]].rel;
        int now = cfLis[i];
        while(!instk[sta[now].pos]){
            instk[sta[now].pos]=sta[sta[now].pos].rel;
            Q.push(sta[now].pos);now = sta[now].pos;
        }
        while(Q.front()!=sta[now].pos)oked[Q.front()]=true,Q.pop();
        if(instk[sta[now].pos]==sta[sta[now].pos].rel){
            int now = Q.front();oked[Q.front()]=true;
            sta[now].fir=0;Q.pop();
            while(Q.size()){
                oked[Q.front()]=true;
                sta[Q.front()].fir=sta[now].fir^(instk[Q.front()]==-1);
                Q.pop();
            };
        }else{
            while(Q.size())sta[Q.front()].fir=2,oked[Q.front()]=true,Q.pop();
        }
    }
}
/* void delCir(){
    for(int i = 1;i<=n;i++){
        if(oked[i])continue;
        dfs(i,i,1);
    }
} */
int main(){
    #ifndef ZYXNOIP
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    #else
    freopen("tribool5.in","r",stdin);
    freopen("tribool5.out","w",stdout);
    #endif
    c=read(),t=read();
    while(t--){
        n=read(),m=read();
        for(int i = 1;i<=n;i++){
            sta[i].pos=i;
            sta[i].rel=1;
            sta[i].fir=-1;
            cfLis[i]=i;
        }
        for(int i = 1;i<=m;i++){
            char opt;int x, y;
            cin>>opt;x=read();
            if(opt=='-'){
                y=read();
                sta[x].pos=sta[y].pos;
                sta[x].rel=-sta[y].rel;
                sta[x].fir=-1;
            }else if(opt=='+'){
                y=read();
                sta[x].pos=sta[y].pos;
                sta[x].rel=sta[y].rel;
                sta[x].fir=-1;
            }else{
                if(opt=='T')sta[x].fir=1;
                else if(opt=='F')sta[x].fir=0;
                else sta[x].fir=2;
                sta[x].pos=sta[x].rel=0;
            }
        }
        int cled = 0,tot=n,last=0;ans=0;
        /* delCir(); */
        while(cled<n&&cled-last>0){
            for(int i = 1;i<=tot;i++){
                if(sta[cfLis[i]].pos==cfLis[i]){
                    if(sta[cfLis[i]].rel==-1){
                        sta[cfLis[i]].fir=2,ans++;
                        cled++;
                        cfLis[i]=cfLis[tot];--tot,--i;
                    }
                }else if(sta[cfLis[i]].fir!=-1){
                    if(sta[cfLis[i]].fir==2)ans++;
                    cled++;
                    cfLis[i]=cfLis[tot];--tot,--i;
                }else if(sta[sta[cfLis[i]].pos].fir!=-1){
                    if(sta[sta[cfLis[i]].pos].fir==2)sta[cfLis[i]].fir=2,ans++;
                    else if(sta[cfLis[i]].rel==-1){
                        sta[cfLis[i]].fir=sta[sta[cfLis[i]].pos].fir^1;
                    }else sta[cfLis[i]].fir=sta[sta[cfLis[i]].pos].fir;
                    cled++;
                    cfLis[i]=cfLis[tot];--tot,--i;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}