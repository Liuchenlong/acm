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
int num[105];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    int minpos=0,maxpos=0;
    for(int i=1;i<n;i++)
    {
        if(num[i]<num[minpos])
            minpos=i;
        if(num[i]>num[maxpos])
            maxpos=i;
    }
    int ans=abs(minpos-maxpos);
    if(minpos==maxpos)
        ;
    else
    {
        if(minpos==0||minpos==n-1||maxpos==0||maxpos==n-1)
            ans=n-1;
        else
        {
            ans=max(ans,minpos);
            ans=max(ans,n-1-minpos);
            ans=max(ans,maxpos);
            ans=max(ans,n-1-maxpos);
        }
    }
    printf("%d\n",ans);
    return 0;
}
