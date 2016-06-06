#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
char mon1[10],mon2[10];
int M(char ch[])
{
    if(ch[0]=='J'&&ch[1]=='a')return 1;
    if(ch[0]=='F')return 2;
    if(ch[0]=='M'&&ch[2]=='r')return 3;
    if(ch[0]=='A'&&ch[1]=='p')return 4;
    if(ch[0]=='M')return 5;
    if(ch[0]=='J'&&ch[2]=='n')return 6;
    if(ch[0]=='J')return 7;
    if(ch[0]=='A')return 8;
    if(ch[0]=='S')return 9;
    if(ch[0]=='O')return 10;
    if(ch[0]=='N')return 11;
    if(ch[0]=='D')return 12;
}
int cal(int y,int m,int d)
{
    if(m<2||(m==2&&d<=28))
        y--;
    return y/4-y/100+y/400;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int day1,year1;
        int day2,year2;
        scanf("%s%d,%d",mon1,&day1,&year1);
        scanf("%s%d,%d",mon2,&day2,&year2);
        int ans=0;
        ans+=cal(year2,M(mon2),day2);
        ans-=cal(year1,M(mon1),day1);
        if(day1==29&&M(mon1)==2&&(year1%400==0||(year1%100!=0&&year1%4==0)))
            ans++;
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
