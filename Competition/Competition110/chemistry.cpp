#include<iostream>
#include<vector>
#include<queue>
#include<assert.h>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int num[4];
int refChar[100],numC,numO,numN,numH,hP,nP;
short cKey[20];
struct EDGE{
    int a;
    int b;
    int keyNum;
};
vector<EDGE>edge;
queue<int>N;
string s;
void addON(int pos){
    int last = pos;
    for(int i = numC+numH+1;i<=numC+numH+numO;i++){
        edge.push_back((EDGE){last,i,1});
        last=i;num[2]--;
    }
    if(numN)edge.push_back((EDGE){last,nP,1}),num[3]--,N.push(nP),nP++;
    else return edge.push_back((EDGE){last,hP,1}),hP++,num[1]--,void();
    while(N.size()){
        int now = N.front();N.pop();
        if(num[3])edge.push_back((EDGE){now,nP,1}),num[3]--,N.push(nP),nP++;
        else edge.push_back((EDGE){now,hP,1}),hP++,num[1]--;
        if(num[3])edge.push_back((EDGE){now,nP,1}),num[3]--,N.push(nP),nP++;
        else edge.push_back((EDGE){now,hP,1}),hP++,num[1]--;
    }
}
void addH(int pos,int nu){
    for(int i = 1;i<=nu;i++){
        edge.push_back((EDGE){pos,hP,1}),num[1]--,hP++;
    }
}
void addC(int x,int y,int val){
    edge.push_back((EDGE){x,y,val});
}
int main(){
    #ifndef LOCAL
    freopen("chemistry.in","r",stdin);
    freopen("chemistry.out","w",stdout);
    #else
    #endif
    refChar['C']=0,refChar['H']=1,refChar['O']=2,refChar['N']=3;
    cin>>s;int len = s.length();
    for(int i = 0;i<len;i+=2){
        if(!isdigit(s[i+1])){num[refChar[int(s[i])]]=1,i--;}
        else num[refChar[int(s[i])]]+=(s[i+1]-'0');
    };
    numC=num[0],numH=num[1],numO=num[2],numN=num[3];
    int unsaturation=2*num[0]+2-(num[1]-num[3]);
    if(s=="CH2O")return cout<<"4 3\nC H H O\n1 2 1\n1 3 1\n1 4 2",0;
    else if(unsaturation<0||(numC==1&&numH<4))return puts("0"),0;
    if(unsaturation==4&&numC==2){
        cKey[1]=cKey[2]=3,addC(1,2,3),unsaturation=0;
    }
    else{
        for(int i = 1;i<num[0];i++){
            if(unsaturation==0) cKey[i]++,addC(i,i+1,1);
            else cKey[i]+=2,unsaturation-=2,addC(i,i+1,2);
        }
        if(unsaturation>0)cKey[num[0]]++,unsaturation-=2;
        if(unsaturation>0)cKey[num[0]]++,unsaturation-=2;
        if(cKey[num[0]])addC(num[0],1,cKey[num[0]]);
        int tmp=cKey[num[0]];
        for(int i = num[0];i>1;i--){
            cKey[i]+=cKey[i-1];
        }cKey[1]+=tmp;
    }
    assert(!unsaturation);
    hP=numC+1,nP=numC+numH+numO+1;
    for(int i = 1;i<=num[0];i++){
        if((num[2]||num[3])&&cKey[i]<4)addON(i),cKey[i]++;
        if(cKey[i]<4)addH(i,4-cKey[i]);
    }
    assert(num[1]==0);
    cout<<numC+numH+numO+numN<<" "<<edge.size()<<endl;
    for(int i = 1;i<=numC;i++)cout<<"C ";
    for(int i = 1;i<=numH;i++)cout<<"H ";
    for(int i = 1;i<=numO;i++)cout<<"O ";
    for(int i = 1;i<=numN;i++)cout<<"N ";
    cout<<endl;
    for(EDGE i:edge){
        cout<<i.a<<" "<<i.b<<" "<<i.keyNum<<endl;
    }
    return 0;
}