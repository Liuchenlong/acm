#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
int n;
int l[100005],r[100005];
int suml,sumr;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        suml+=l[i];
        sumr+=r[i];
    }
    int pos=0;
    int ans=abs(suml-sumr);
    for(int i=1;i<=n;i++)
    {
        int tmp=abs((suml-l[i]+r[i])-(sumr-r[i]+l[i]));
        if(tmp>ans)
        {
            ans=tmp;
            pos=i;
        }
    }
    printf("%d\n",pos);
    return 0;
}
