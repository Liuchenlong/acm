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
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))

long long num[200005];
int l[200005];
int r[200005];
int Stack[200005];
int snum;
int pos[200005];
long long ans[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%I64d",&num[i]);
    Stack[snum]=num[1];
    pos[snum++]=1;
    for(int i=2; i<=n; i++)
    {
        while(snum&&Stack[snum-1]>num[i])
        {
            r[pos[snum-1]]=i-1;
            snum--;
        }
        Stack[snum]=num[i];
        pos[snum++]=i;
    }
    int rit=pos[snum-1];
    while(snum)
    {
        r[pos[snum-1]]=rit;
        snum--;
    }

    Stack[snum]=num[n];
    pos[snum++]=n;
    for(int i=n-1; i>0; i--)
    {
        while(snum&&Stack[snum-1]>num[i])
        {
            l[pos[snum-1]]=i+1;
            snum--;
        }
        Stack[snum]=num[i];
        pos[snum++]=i;
    }
    int lef=pos[snum-1];
    while(snum)
    {
        l[pos[snum-1]]=lef;
        snum--;
    }
    for(int i=1; i<=n; i++)
    {
        ans[r[i]-l[i]+1]=MAX(ans[r[i]-l[i]+1],num[i]);
    }
    for(int i=n-1;i>=1;i--)
        ans[i]=MAX(ans[i],ans[i+1]);
    for(int i=1;i<=n;i++)
    {
        printf("%I64d ",ans[i]);
    }
    printf("\n");
    return 0;
}
