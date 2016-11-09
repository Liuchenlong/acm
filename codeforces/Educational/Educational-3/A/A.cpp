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

int num[100005];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    sort(num,num+n);
    int sum=0;
    for(int i=n-1;i>=0;i--)
    {
        sum++;
        m-=num[i];
        if(m<=0)
            break;
    }
    printf("%d\n",sum);
    return 0;
}
