#include<iostream>
using namespace std;
int ne[1000006],n,m;
string s,p;
void build_next(){
    for (int i = 1, j = 0; i < m; i ++ ){
        while (j && p[i] != p[j]) j = ne[j];
        if (p[i] == p[j]) j++,ne[i+1] =j;
    }
}
void search(){
    for (int i=0, j = 0; i < n; i ++ ){
        while (j && s[i] != p[j]) j = ne[j];
        if (s[i] == p[j]) j ++ ;
        if (j == m) cout<<i-m+2<<endl;
    }
}
int main(){
    cin>>s>>p;
    n=s.size(),m=p.size();
    build_next();search();
    for (int i=1;i<=m;i++) cout<<ne[i]<<" ";
    return 0;
}