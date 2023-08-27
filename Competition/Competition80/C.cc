#include<bits/stdc++.h>
#define IL inline
#define reg register
#define int long long
IL int read()
{
    reg int x=0; reg char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}

int n,p[62],ans,sum;

IL void insert(reg int x)
{
    sum^=x;
    for(reg int i=0;i<60;++i)if(x>>i&1)
    {
        if(!p[i])return p[i]=x,void();
        x^=p[i];
    }
}

IL void cmax(reg int &x,reg int y){x<y?x=y:0;}

main()
{
    n=read();
    while(n--)insert(read());
    for(reg int i=60,j;i--;)for(j=i;j--;)if(p[j]>>i&1)p[j]^=p[i];
    for(reg int i=0,c=0,nw=0;;++i)
    {
        c+=1ll<<i;
        if(~nw>>i&1)cmax(ans,sum^c);
        if((~nw>>i&1)&&!p[i])break;
        nw^=p[i];
    }
    printf("%lld\n",ans);
}