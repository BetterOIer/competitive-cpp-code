#include<iostream>
#include<map>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,m;
string s;
long long preCmd[4][100005];
/* ![](/file/2/lyric.png) */
map<char,int>refCmd;
int main(){
	freopen("move.in","r",stdin);
	freopen("move.out","w",stdout);
    refCmd['W']=0,refCmd['A']=1,refCmd['S']=2,refCmd['D']=3;
    n=read(),m=read();cin>>s;
    for(long long i = 1;i<=n;i++)preCmd[refCmd[s[i-1]]][i]=1;
    for(long long i = 1;i<=n;i++)preCmd[0][i]+=preCmd[0][i-1];
    for(long long i = 1;i<=n;i++)preCmd[1][i]+=preCmd[1][i-1];
    for(long long i = 1;i<=n;i++)preCmd[2][i]+=preCmd[2][i-1];
    for(long long i = 1;i<=n;i++)preCmd[3][i]+=preCmd[3][i-1];
    long long x=0,y=0;
    for(long long i = 1,l,r;i<=m;i++){
        l=read(),r=read();
        long long num[4];double dis[4];
        bool vaild[5]={0,0,0,0,0};
        num[0]=preCmd[0][r]-preCmd[0][l-1];
        num[1]=preCmd[1][r]-preCmd[1][l-1];
        num[2]=preCmd[2][r]-preCmd[2][l-1];
        num[3]=preCmd[3][r]-preCmd[3][l-1];
        dis[1]=__builtin_sqrt((x+num[3])*(x+num[3])+(y+num[0])*(y+num[0]));
		dis[2]=__builtin_sqrt((x-num[1])*(x-num[1])+(y+num[0])*(y+num[0]));
		dis[3]=__builtin_sqrt((x-num[1])*(x-num[1])+(y-num[2])*(y-num[2]));
		dis[4]=__builtin_sqrt((x+num[3])*(x+num[3])+(y-num[2])*(y-num[2]));
		if(dis[1]>=dis[2]&&dis[1]>=dis[3]&&dis[1]>=dis[4]) vaild[1]=1;
		if(dis[2]>=dis[1]&&dis[2]>=dis[3]&&dis[2]>=dis[4]) vaild[2]=1;
		if(dis[3]>=dis[1]&&dis[3]>=dis[2]&&dis[3]>=dis[4]) vaild[3]=1;
		if(dis[4]>=dis[2]&&dis[4]>=dis[1]&&dis[4]>=dis[3]) vaild[4]=1;
		if(vaild[1]) x+=num[3],y+=num[0];
		else if(vaild[4]) x+=num[3],y-=num[2];
		else if(vaild[2]) x-=num[1],y+=num[0];
		else x-=num[1],y-=num[2];
    }
    cout<<x<<" "<<y;
    return 0;
}