/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
string s,ans,tmpans;
int slen;
void read_float(int l,int r){
    while(s[r]=='0')r--;
    if(l>r)return tmpans="0",void();
    return tmpans=s.substr(l,r-l+1),void();
}
void read_qbsg(int l,int r){
    string tans="";
    while(s[l]=='0')l++;
    if(l>r)return tmpans="0",void();
    int len = r-l+1;
    if(len==4){
        tans=s[l]
    }
}
void read_int(int l,int r){
    string tans="";
    while(s[l]=='0')l++;
    if(l>r)return tmpans="0",void();
    int len = r-l+1;
    if(len>=9){

    }
    if(len>=5){

    }

}
void read_num(int l,int r){
    string tans="";
    bool opst=true;
    if(!isdigit(s[l])){
        if(s[l]=='-'){
            l++;
            opst=false;
        }else if(s[l]=='+')l++;
    }
    if(!opst) tans='F';
    int cntdh = s.find('.');
    if(cntdh!=-1){
        read_int(l,cntdh-1);
        tans+=tmpans;
        read_float(cntdh+1,r);
        if(tmpans!="0"){
            tans+='D';
            tans+=tmpans;
        }
    }
    tmpans=tans;
}
int main(){
    cin>>s;
    int cntfs=s.find('/');
    if(cntfs!=-1){
        read_num(cntfs+1,slen);
        ans+=tmpans;
        ans+="fz";
        read_num(0,cntfs-1);
        ans+=tmpans;
    }else{
        read_num(0,slen);
        ans+=tmpans;
    }
    cout<<ans;
    return 0;
}