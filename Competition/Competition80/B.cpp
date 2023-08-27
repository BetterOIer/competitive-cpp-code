/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
#include<set>
#include<cstring>
using namespace std;
int n;
string s;
int dir[4][2] = {{-1,0},{+1,0},{0,-1},{0,+1}};
int g[105][105];
struct node{
    int x;
    int y;
};
bool operator <(node a,node b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x; 
}
set<node>S;
int get_dir(char opt){
    if(opt=='L')return 0;
    if(opt=='R')return 1;
    if(opt=='D')return 2;
    return 3;
}
void solve(int whi){
    memset(g,0,sizeof g);
    int x=0,y=0;
    for(int i = 0;i<n;i++){
        g[30+x][30+y]=-1;
        int opt = get_dir(s[i]);
        if((whi>>i)&1){
            if(g[30+x+dir[opt][0]][30+y+dir[opt][1]]<=0){
                x = x+dir[opt][0],y = y+dir[opt][1];
            }
        }else{
            if(g[30+x+dir[opt][0]][30+y+dir[opt][1]]==-1)return;
            if(!g[30+x+dir[opt][0]][30+y+dir[opt][1]])g[30+x+dir[opt][0]][30+y+dir[opt][1]]=true;
        }
    }
    S.insert((node){x,y});
}
int main(){
    cin>>n>>s;
    for(int i = 0;i<(1<<n);i++){
        solve(i);
    }
    cout<<S.size()<<endl;
    for(node i:S){
        cout<<i.x<<" "<<i.y<<endl;
    }
    return 0;
}