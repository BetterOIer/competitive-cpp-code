#include<iostream>
#include<set>
using namespace std;
set <string> S;
int all=0;
int main(){
    int n;
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        if(S.find(s)==S.end()) S.insert(s);
    }
    cout<<S.size();
    return 0;
}