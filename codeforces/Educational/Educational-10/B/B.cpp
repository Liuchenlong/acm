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
int n;
int num[1005];
int ans[1005];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    sort(num,num+n);
    int l=0,r=n-1;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
            ans[i]=num[l++];
        else
            ans[i]=num[r--];
    }
    bool flag=0;
    for(int i=1;i<n;i++)
    {
        if(i%2==1)
        {
            if(ans[i]<ans[i-1])
            {
                flag=1;
                break;
            }
        }
        else
        {
            if(ans[i]>ans[i-1])
            {
                flag=1;
                break;
            }
        }
    }
    if(flag)
    {
        printf("Impossible\n");
        return 0;
    }
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
    return 0;
}
