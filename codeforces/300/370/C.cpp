#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
#define eps 1e-8
int ans;
int x,y;
int num[3];
int cal(int a,int b,int c)
{
    if(a==x)return 0;
    num[0]=b;
    num[1]=c;
    num[2]=min(x,b+c-1);
    sort(num,num+3);
    return 1+cal(num[0],num[1],num[2]);
}
int main()
{
    scanf("%d%d",&x,&y);
    printf("%d\n",cal(y,y,y));
    return 0;
}
