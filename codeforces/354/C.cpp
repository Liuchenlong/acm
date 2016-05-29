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
int suma[100005];
int sumb[100005];
char str[100005];
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",str+1);
    for(int i=1;i<=n;i++)
    {
        suma[i]=suma[i-1];
        sumb[i]=sumb[i-1];
        if(str[i]=='a')
            suma[i]++;
        else
            sumb[i]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(suma[i]<=k)
            ans=max(ans,i);
        else
        {
            int pos=lower_bound(suma,suma+1+n,suma[i]-k)-suma;
            ans=max(ans,i-pos);
        }
        if(sumb[i]<=k)
            ans=max(ans,i);
        else
        {
            int pos=lower_bound(sumb,sumb+1+n,sumb[i]-k)-sumb;
            ans=max(ans,i-pos);
        }
    }
    printf("%d\n",ans);
    return 0;
}
