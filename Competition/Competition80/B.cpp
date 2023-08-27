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
using namespace std;
int n;
string s;
int dir[4][2] = {{-1,0},{+1,0},{0,-1},{0,+1}};
int g[50][50];
struct node{
    int x;
    int y;
};
bool operator <(node a,node b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x; 
}
set<node>S,sdel;
int get_dir(char opt){
    if(opt=='L')return 0;
    if(opt=='R')return 1;
    if(opt=='D')return 2;
    return 3;
}
void solve(int whi){
    if(sdel.size()){
        for(node i:sdel){
            g[i.x][i.y]=0;
        }
        sdel.clear();
    }
    int x=0,y=0;
    for(int i = 0;i<n;i++){
        g[25+x][25+y]=-1;
        sdel.insert((node){x+25,25+y});
        int opt = get_dir(s[i]);
        if((whi>>i)&1){
            if(g[25+x+dir[opt][0]][25+y+dir[opt][1]]<=0){
                x = x+dir[opt][0],y = y+dir[opt][1];
            }
        }else{
            if(g[25+x+dir[opt][0]][25+y+dir[opt][1]]==-1)return;
            if(!g[25+x+dir[opt][0]][25+y+dir[opt][1]])g[25+x+dir[opt][0]][25+y+dir[opt][1]]=true,sdel.insert((node){25+x+dir[opt][0],25+y+dir[opt][1]});
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