#include<iostream>
#include<map>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,totCTT;
map<string,int>typeId;
struct CTTYPE{
    string name;
    long long size;
    long long neat;
    map <string, pair <int, long long> > sub;
	void push_back(int, string);
}a[1005];
long long updiv(long long a,long long b){
    return (a+b-1)/b;
}
void CTTYPE :: push_back(int tp, string var) {
	long long st = updiv(size, a[tp].neat) * a[tp].neat;
	//cout << st << ' ' << a[tp].mx << endl;
	sub[var] = make_pair(tp, st);
	size = st + a[tp].size;
	neat = max(neat, a[tp].neat);
}


int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    n=read();
    totCTT=4;
	a[1].name = "byte";a[1].size=a[1].neat=1;typeId["byte"] = 1;
	a[2].name = "short";a[2].size=a[2].neat=2;typeId["short"] = 2;
	a[3].name = "int";a[3].size=a[3].neat=4;typeId["int"] = 3;
	a[4].name = "long";a[4].size=a[4].neat=8;typeId["long"] = 4;
    for(int i = 1;i<=n;i++){
        int op = read();
        if(op==1){
            string s,dfdType,typeName;cin>>s;
            int k=read();
            ++totCTT;a[totCTT].name=s;typeId[s]=n;
            while(k--){
                cin>>dfdType>>typeName;
                a[totCTT].push_back(typeId[dfdType],typeName);
            }
            a[totCTT].size=updiv(a[totCTT].size, a[totCTT].neat)*a[totCTT].neat;
            cout<<a[totCTT].size<<" "<<a[totCTT].neat<<"\n";
        }else if(op==2){
            string s, t; cin >> s >> t;
			a[0].push_back(typeId[s], t);
			cout<<a[0].sub[t].second<<'\n';
        }else if(op==3){
            string s,t;cin>>s;
            long long ans=0;int p = 0,len=s.length();
            for(int i = 0;i<=len;i++){
                if(i==len||s[i]=='.'){
                    ans+=a[p].sub[t].second;
                    p = a[p].sub[t].first;
                    t="";
                }else t+=s[i];
            }
            cout<<ans<<'\n';
        }else if(op==4){
            long long x=read();
            int p = 0,flag=1;
            string s;
            while(a[p].sub.size()){
                int nxt = 0;
				for(auto mb : a[p].sub)
					if(mb.second.second <= x && x < mb.second.second + a[mb.second.first].size) {
						s += mb.first; s += '.';
						x -= mb.second.second;
						nxt = mb.second.first; break;
					}
				if(!nxt) { flag = 0; break; }
				p = nxt;
			}
            if((!a[0].sub.size())||(!flag))cout<<"ERR\n";
            else s.erase(--s.end()),cout<<s<<"\n";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}