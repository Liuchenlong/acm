#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8

int main()
{
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        while(x)
        {
            int res=x%256;
            x/=256;
            if(res==97)
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
