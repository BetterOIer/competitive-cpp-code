#include<iostream>
#include<stdio.h>

using namespace std;

int i,m,n,j,k,l,o,p,a[1001][1001],ma[1001],maxx,maxy,z[6]={2,1,0,0,0,0},s[6]={6,6,6,6,5,4};

char c[1001][1001],c1[10][10]={
"  +---+",
" /   /|",
"+---+ |",
"|   | +",
"|   |/",
"+---+",
};

void fg(int x,int y)
{
    int i,j;
    for(i=5;i>=0;i--)//立方体需要倒过来存入数组
        for(j=z[i];j<=s[i];j++)//分别是这一行的宽度
        {
            c[5-i+x][j+y]=c1[i][j];
            if(5-i+x>maxx) maxx=5-i+x;
            if(j+y>maxy) maxy=j+y;//分别记录最大长宽
        }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    for(o=1;o<=n;o++)//层数
        for(k=0;k<m;k++)//列循环
            for(l=0;l<a[o][k];l++)//高度
                fg((n-o)*2+1+3*l,(n-o)*2+1+4*k);//表示立方体左下角位置

    for(i=maxx;i>=1;i--)
    {    
        for(j=1;j<=maxy;j++)
            if(c[i][j]=='\000') printf(".");
            else printf("%c",c[i][j]);
        printf("\n");
    }
}