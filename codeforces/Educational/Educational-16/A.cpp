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
bool check(int x,int y)
{
    if(x>=0&&x<8&&y>=0&&y<8)return true;
    return false;
}
int main()
{
    char str[5];
    scanf("%s",str);
    int x,y;
    x=str[0]-'a';
    y=str[1]-'1';
    int ans=0;
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(check(x+i,y+j))ans++;
        }
    }
    printf("%d\n",ans-1);
    return 0;
}
