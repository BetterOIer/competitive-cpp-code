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
    vector<int>offset;
};
vector<CustomType>customType;
int totCType;
map<string,int>refTypeSize,refCType,refEmt;
vector<node>dfdEmt;
int addrCount=0;
string req,ansOfQ4;
void creNewType(){
    CustomType newType;newType.inType.clear();
    cin>>newType.name;newType.inNum=read();
    int offset=0;
    for(int j = 1;j<=newType.inNum;j++){
        node basicType;
        cin>>basicType.typeName>>basicType.name;
        newType.neat=max(newType.neat,customType[refCType[basicType.typeName]].neat);
        newType.siz+=refTypeSize[basicType.typeName];
        newType.inType.push_back(basicType);
        newType.offset.push_back(offset);
        offset=ceil(1.0*(offset+customType[refCType[basicType.typeName]].siz)/customType[refCType[basicType.typeName]].neat)*customType[refCType[basicType.typeName]].neat;
    }
    newType.siz=ceil(1.0*(offset))/newType.neat*newType.neat;
    refTypeSize[newType.name]=newType.siz;
    customType.push_back(newType);
    refCType[newType.name]=totCType++;
    cout<<newType.siz<<" "<<newType.neat<<endl;
}
void creNewEmt(){
    cout<<addrCount<<endl;
    node newNode;
    cin>>newNode.typeName>>newNode.name;
    refEmt[newNode.name]=dfdEmt.size();
    dfdEmt.push_back(newNode);
    customType[0].inNum++;
    customType[0].inType.push_back(newNode);
    customType[0].offset.push_back(addrCount);
    customType[0].neat=max(customType[0].neat,customType[refCType[newNode.typeName]].neat);
    addrCount=ceil(1.0*(addrCount+customType[refCType[newNode.typeName]].siz-1)/customType[refCType[newNode.typeName]].neat)*customType[refCType[newNode.typeName]].neat;
}
void findFrom(int addrSta, int reqSta,int preType){
    int oriAddrSta = addrSta;
    string nowCope = req.substr(reqSta,req.length()-reqSta);
    int dotPla = nowCope.find(".");
    if(dotPla==-1){
        for(int i = 0;i<customType[preType].inType.size();i++){
            if(customType[preType].inType[i].name==nowCope){
                cout<<addrSta<<endl;
                return;
            }
            addrSta=oriAddrSta+customType[preType].offset[i+1];//Danger
        }
    }else{
        string nowType = nowCope.substr(0,dotPla);
        for(int i = 0;i<customType[preType].inType.size();i++){
            if(customType[preType].inType[i].name==nowType){
                findFrom(addrSta,reqSta+dotPla+1,refCType[customType[preType].inType[i].typeName]);
                return;
            }
            addrSta=oriAddrSta+customType[preType].offset[i];
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
    for(int i = 0;i<customType[nowType].inType.size();i++){
        if(addrSta+customType[nowType].offset[i]>goalSta){
            ansOfQ4+=customType[nowType].inType[i].name+".";
            return findWho(goalSta,addrSta+customType[nowType].offset[i-1],refCType[customType[nowType].inType[i].typeName]);
        }else addrSta+=customType[refCType[customType[nowType].inType[i].typeName]].siz;
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