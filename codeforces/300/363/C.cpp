#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
int n;
int a[105];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int sum=0;
    int mask=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            sum++;
            mask=0;
        }
        if(a[i]==1)
        {
            if(mask==1)
            {
                sum++;
                mask=0;
            }
            else
            {
                mask=1;
            }
        }
        if(a[i]==2)
        {
            if(mask==2)
            {
                sum++;
                mask=0;
            }
            else
            {
                mask=2;
            }
        }
        if(a[i]==3)
        {
            if(mask==1)
                mask=2;
            else if(mask==2)
                mask=1;
            else
                mask=3;
        }
    }
    printf("%d\n",sum);
    return 0;
}
