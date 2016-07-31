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
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) (a<0?-a:a)
#define SIZE 1000005
#define INF 0x7fffffff

int main()
{
    int n;
    scanf("%d",&n);
    int ans=0;
    while(n)
    {
        if(n%2==1)
            ans++;
        n/=2;
    }
    printf("%d\n",ans);
    return 0;
}
