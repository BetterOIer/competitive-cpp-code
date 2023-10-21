#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}
int n;
struct node{
    string typeName;
    string name;
};
struct CustomType{
    string name;
    int neat=0;
    int inNum=0;
    int siz=0;
    vector<node>inType;
};
vector<CustomType>customType;
int totCType;
map<string,int>refTypeSize,refCType,refEmt;
vector<node>dfdEmt;
int addrCount=0;
int emtFrom[105];
string req,ansOfQ4;
void creNewType(){
    CustomType newType;newType.inType.clear();
    cin>>newType.name;newType.inNum=read();
    for(int j = 1;j<=newType.inNum;j++){
        node basicType;
        cin>>basicType.typeName>>basicType.name;
        newType.neat=max(newType.neat,refTypeSize[basicType.typeName]);
        newType.siz+=refTypeSize[basicType.typeName];
        newType.inType.push_back(basicType);
    }
    newType.siz=ceil(1.0*newType.siz/newType.neat)*newType.neat;
    refTypeSize[newType.name]=newType.siz;
    customType.push_back(newType);
    refCType[newType.name]=totCType++;
    cout<<newType.siz<<" "<<newType.neat<<endl;
}
void creNewEmt(){
    cout<<addrCount<<endl;
    node newNode;
    cin>>newNode.typeName>>newNode.name;
    emtFrom[dfdEmt.size()]=addrCount;
    refEmt[newNode.name]=dfdEmt.size();
    dfdEmt.push_back(newNode);
    addrCount+=customType[refCType[newNode.typeName]].siz;/* Attention!! */
    customType[0].inNum++;
    customType[0].inType.push_back(newNode);
    customType[0].neat=max(customType[0].neat,refTypeSize[newNode.typeName]);
}
void findFrom(int addrSta, int reqSta,int preType){
    //cout<<addrSta<<" "<<reqSta<<" "<<preType<<endl;
    string nowCope = req.substr(reqSta,req.length()-reqSta);
    int dotPla = nowCope.find(".");
    if(dotPla==-1){
        for(node i:customType[preType].inType){
            if(i.name==nowCope){
                cout<<addrSta<<endl;
                return;
            }
            addrSta+=customType[refCType[i.typeName]].siz;
        }
    }else{
        string nowType = nowCope.substr(0,dotPla);
        for(node i:customType[preType].inType){
            if(i.name==nowType){
                findFrom(addrSta,reqSta+dotPla+1,refCType[i.typeName]);
                return;
            }
            addrSta+=customType[refCType[i.typeName]].siz;
        }
    }
}
bool findWho(int goalSta, int addrSta, int nowType){
    if(customType[nowType].inNum==0){
        if(addrSta+customType[nowType].siz<=goalSta){
            cout<<"ERR\n";
            return false;
        }else{
            ansOfQ4=ansOfQ4.substr(0,ansOfQ4.length()-1);
            return true;
        }
    }
    for(node i:customType[nowType].inType){
        if(addrSta+customType[refCType[i.typeName]].siz>goalSta){
            ansOfQ4+=i.name+".";
            return findWho(goalSta,addrSta,refCType[i.typeName]);
        }else addrSta+=customType[refCType[i.typeName]].siz;
    }
    cout<<"ERR\n";
    return false;
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    refTypeSize["byte"]=1;
    refTypeSize["short"]=2;
    refTypeSize["int"]=4;
    refTypeSize["long"]=8;

    refCType["program"]=totCType++;
    CustomType program;
    program.inNum=0;
    program.inType.clear();
    program.name="program";
    program.neat=0;
    program.siz=0;
    customType.push_back(program);

    refCType["byte"]=totCType++;
    CustomType bYTE;
    bYTE.inNum=0;
    bYTE.inType.clear();
    bYTE.name="byte";
    bYTE.neat=1;
    bYTE.siz=1;
    customType.push_back(bYTE);

    refCType["int"]=totCType++;
    CustomType iNT;
    iNT.inNum=0;
    iNT.inType.clear();
    iNT.name="int";
    iNT.neat=4;
    iNT.siz=4;
    customType.push_back(iNT);

    refCType["short"]=totCType++;
    CustomType sHORT;
    sHORT.inNum=0;
    sHORT.inType.clear();
    sHORT.name="short";
    sHORT.neat=2;
    sHORT.siz=2;
    customType.push_back(sHORT);

    refCType["long"]=totCType++;
    CustomType lONG;
    lONG.inNum=0;
    lONG.inType.clear();
    lONG.name="long";
    lONG.neat=8;
    lONG.siz=8;
    customType.push_back(lONG);

    n=read();
    for(int i=1,op;i<=n;i++){
        op=read();
        if(op==1) creNewType();
        else if(op==2) creNewEmt();
        else if(op==3){cin>>req;findFrom(0,0,0);}
        else if(op==4){int addr = read();if(findWho(addr,0,0)){cout<<ansOfQ4<<endl;}ansOfQ4="";}
        //cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}