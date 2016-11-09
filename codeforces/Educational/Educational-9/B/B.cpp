#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<iomanip>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
char str[500005];
int val[500005];
long long suma[500005];
long long sumb[500005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&val[i]);
    scanf("%s",str+1);
    for(int i=1;i<=n;i++)
    {
        if(str[i]=='A')
            suma[i]=val[i];
        else
            sumb[i]=val[i];
        suma[i]+=suma[i-1];
        sumb[i]+=sumb[i-1];
    }
    long long ans=0;
    for(int i=0;i<=n;i++)
    {
        if(suma[i]+sumb[n]-sumb[i]>ans)
            ans=suma[i]+sumb[n]-sumb[i];
        if(sumb[i]+suma[n]-suma[i]>ans)
            ans=sumb[i]+suma[n]-suma[i];
    }
    printf("%I64d\n",ans);
    return 0;
}
