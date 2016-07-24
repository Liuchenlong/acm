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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-7
const int maxn=100005;
bool visx[maxn];
bool visy[maxn];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    long long resx=n,resy=n;
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(!visx[x])
        {
            visx[x]=true;
            resx--;
        }
        if(!visy[y])
        {
            visy[y]=true;
            resy--;
        }
        printf("%I64d ",resx*resy);
    }
    return 0;
}
