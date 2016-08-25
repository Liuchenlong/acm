#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int a[1000005];
int n,b,d;
int main()
{
    scanf("%d%d%d",&n,&b,&d);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int ans=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>b)continue;
        if(res+a[i]>d)
        {
            ans++;
            res=0;
        }
        else
            res+=a[i];
    }
    printf("%d\n",ans);
    return 0;
}
