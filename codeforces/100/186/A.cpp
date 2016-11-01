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
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) (a<0?-a:a)
#define SIZE 500000
#define INF 0x7fffffff
#define mod 9901


int main()
{
    int n;
    scanf("%d",&n);
    if(n>0)
        printf("%d\n",n);
    else
    {
        int ans=n;
        ans=max(ans,n/10);
        ans=max(ans,n/100*10-abs(n)%10);
        printf("%d\n",ans);
    }
    return 0;
}
