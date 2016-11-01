#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-12

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    vector<int>ans;
    while(b>a)
    {
        if(b%2==0)
        {
            ans.push_back(b);
            b/=2;
        }
        else
        {
            ans.push_back(b);
            b--;
            if(b%10==0)
            {
                b/=10;
            }
            else
            {
                printf("NO\n");
                return 0;
            }
        }
        if(b<a)
        {
            printf("NO\n");
            return 0;
        }
    }
    ans.push_back(a);
    printf("YES\n");
    printf("%d\n",ans.size());
    for(int i=ans.size()-1;i>=0;i--)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}
