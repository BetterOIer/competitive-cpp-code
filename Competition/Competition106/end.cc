#include<bits/stdc++.h>
#define hor(i,l,r) for(register int i=l;i<=r;i++)
#define lor(i,l,r) for(register int i=l;i>=r;i--)
using namespace std;
int n,a[114],b[114],p1[114],p2[114],q,num[5],x,st1[114],st2[114],ll;
char s[114];
int get(char s[]){
	if(s[0]=='a') return 1;
	if(s[0]=='b') return 2;
	if(s[0]=='c') return 3;
	if(s[0]=='d') return 4;
}
signed main(){
	scanf("%d%d",&n,&q);
	hor(i,1,n){
		scanf("%s",s);
		if(s[0]=='r'){
			scanf("%d",&x);
			a[i]=2;
			b[i]=x;
			continue;
		}if(s[0]=='e'){
			a[i]=3;
			continue;
		}
		if(s[0]=='x') b[i]=1;
		if(s[0]=='o') b[i]=2;
		if(s[0]=='a') b[i]=3;
		scanf("%s",s);
		p1[i]=get(s);
		if(s[2]=='i'||s[3]=='i'){
			a[i]=1;
			scanf("%d",&p2[i]);
		}else{
			scanf("%s",s);
			p2[i]=get(s);
		}
	}while(q--){
		int lim,now=0;
		scanf("%d",&lim);
		hor(i,1,4) scanf("%d",&num[i]);
		ll=0;
		hor(i,1,n){
			if(now==lim) continue;
			if(a[i]==3){
				st1[ll]--;
				if(st1[ll]==0){
					ll--;
					continue;
				}
				i=st2[ll];
			}if(a[i]==2){
				st1[++ll]=b[i];
				st2[ll]=i+1;
			}
			if(!a[i]){
				if(b[i]==1) num[p1[i]]=(num[p1[i]]^num[p2[i]]);
				if(b[i]==2) num[p1[i]]=(num[p1[i]]|num[p2[i]]);
				if(b[i]==3) num[p1[i]]=(num[p1[i]]&num[p2[i]]);
				now++;
			}if(a[i]==1){
				if(b[i]==1) num[p1[i]]=(num[p1[i]]^p2[i]);
				if(b[i]==2) num[p1[i]]=(num[p1[i]]|p2[i]);
				if(b[i]==3) num[p1[i]]=(num[p1[i]]&p2[i]);
				now++;
			}
		}
		printf("%d %d %d %d\n",num[1],num[2],num[3],num[4]);
	}
	return 0;
}

