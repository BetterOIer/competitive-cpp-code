#include<iostream>
#include<vector>
#include<map>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m;
bool a[2005][2005];
int pre[2005][2005];
vector<pair<int,int> >v[2005];
/* map<pair<int, int>, int>s; */

void out(){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cout<<a[i][j]<<" \n"[j==m];
        }
    }cout<<endl;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cout<<pre[i][j]<<" \n"[j==m];
        }
    }cout<<endl;
}
int main(){
    #ifndef LOCAL
    freopen("wu.in","r",stdin);
    freopen("wu.out","w",stdout);
    #else
    freopen("wu/wu4.in","r",stdin);
    freopen("wu/wu4.out","w",stdout);
    #endif
    n=read(),m=read();
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            a[i][j]=read();pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+a[i][j];
            if(a[i][j])v[1].push_back(make_pair(i,j))/* ,s[make_pair(i,j)]=1; */;
        }
    }
    //out();
    int minn = min(n,m);
    for(int i = 2;i<=minn;i++){
        for(auto j:v[i-1]){
            if(pre[j.first][j.second]+pre[j.first-i][j.second-i]-pre[j.first][j.second-i]-pre[j.first-i][j.second]==i*i)v[i].push_back(j)/* ,s[j]++ */;
        }
    }
    int ans=0;
    for(int _t = 1;_t<=minn&&v[_t].size();_t++){
        for(auto i:v[_t]){
            int my=n,mx=m,num=0;
            for(int y = i.first+1;y<=my;y++){
                for(int x = i.second+1;x<=mx;x++){
                    if(pre[y][x]+pre[i.first-_t][i.second-_t]-pre[y][i.second-_t]-pre[x][i.first-_t]==_t*_t)num++;
                    /* else mx=x-1; */
                }
            }
            ans+=num;
        }
    }
    cout<<ans;
    return 0;
}