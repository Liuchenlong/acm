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
#define eps 1e-8

int n,k;
int num[500005];
int tim[1000005];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
        scanf("%d",&num[i]);
    int l=1,r=1;
    int ansl=1,ansr=1;
    int ans=0;
    int tans=0;
    for(; r<=n; r++)
    {
        if(tim[num[r]]==0)
        {
            tans++;
        }
        tim[num[r]]++;
        while(tans>k)
        {
            tim[num[l]]--;
            if(tim[num[l]]==0)
                tans--;
            l++;
        }
        if(r-l+1>ans)
        {
            ans=r-l+1;
            ansl=l;
            ansr=r;
        }
    }
    printf("%d %d\n",ansl,ansr);
    return 0;
}
