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
int a[1000005];
int b[1000005];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    b[n]=n+1;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]==a[i+1])
            b[i]=b[i+1];
        else
            b[i]=i+1;
    }
    for(int i=0;i<m;i++)
    {
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        if(a[l]!=x)
            printf("%d\n",l);
        else if(a[b[l]]!=x&&b[l]<=r)
            printf("%d\n",b[l]);
        else
            printf("-1\n");
    }
    return 0;
}
