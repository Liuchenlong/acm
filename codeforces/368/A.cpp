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

int main()
{
    bool flag=0;
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
        char str[12];
        scanf("%s",str);
        if(str[0]=='C'||str[0]=='Y'||str[0]=='M')
            flag=1;
    }
    if(flag)puts("#Color");
    else puts("#Black&White");
    return 0;
}
