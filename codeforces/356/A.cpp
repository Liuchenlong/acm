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

int sum=0;
int num[105];
int cad[5];
int main()
{
    for(int i=0;i<5;i++)
    {
        scanf("%d",&cad[i]);
        sum+=cad[i];
        num[cad[i]]++;
    }
    int ans=sum;
    for(int i=0;i<5;i++)
    {
        if(num[cad[i]]>1)
        {
            ans=min(ans,sum-min(3,num[cad[i]])*cad[i]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
