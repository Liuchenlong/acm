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
bool vis[55][55];
vector<int>odd,even;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n*n;i++)
    {
        if(i&1)odd.push_back(i);
        else even.push_back(i);
    }
    int mid=(n+1)/2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(abs(i-mid)+abs(j-mid)<=n/2)
                vis[i][j]=1;
        }
    }
    int ho=0,he=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(vis[i][j])printf("%d ",odd[ho++]);
            else printf("%d ",even[he++]);
        }
        printf("\n");
    }
    return 0;
}
