#include<iostream>
#include<map>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
map<int,int>M;
int main(){
    int n=read();
    for(int i = 1,x;i<=n;i++){
        x=read();
        if(!M[x])M[x]=0;M[x]++;
    }
    while(M.size()>2){
        std::map<int, int>::iterator i = M.begin();
        std::map<int, int>::iterator j = M.end();j--;
        int minn = min(i->second,j->second);
        i->second-=minn;
        j->second-=minn;
        if(!i->second){
            M.erase(i);i = M.begin();
            if(M.size()==2){
                cout<<"Mirko\n"<<M.begin()->first<<" "<<j->first;
                return 0;
            }
        }else i++;
        if(!j->second){
            M.erase(j);j = M.end();j--;
            if(M.size()==2){
                cout<<"Slavko\n"<<M.begin()->first<<" "<<j->first;
                return 0;
            }
            
        }else j--;
        i->second+=minn;
        j->second+=minn;
    }
    std::map<int, int>::iterator j = M.end();j--;
    cout<<"Slavko\n"<<M.begin()->first<<" "<<j->first;
    return 0;
}