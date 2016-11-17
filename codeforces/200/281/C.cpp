#include<stdio.h>
#include<math.h>
#include<cmath>
#include<vector>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) (a<b?a:b)
#define ll long long
#define INF 9223372036854775807
long long numf[200005];
long long nums[200005];
long long sumf;
long long sums;
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&numf[i]);
    }
    sort(numf,numf+n);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%I64d",&nums[i]);
    }
    sort(nums,nums+m);
    long long max=-INF;
    long long ansf=0,anss=0;
    for(int i=0;i<n;i++)
    {
        sumf=i*2+(n-i)*3;
        int pos=lower_bound(nums,nums+m,numf[i])-nums;
        sums=pos*2+(m-pos)*3;
        if(sumf-sums>max||(sumf-sums==max&&sumf>ansf))
        {
            max=sumf-sums;
            ansf=sumf;
            anss=sums;
        }
    }
    sumf=2*n;
    sums=2*m;
    if(sumf-sums>max||(sumf-sums==max&&sumf>ansf))
    {
        ansf=sumf;
        anss=sums;
    }
    printf("%I64d:%I64d\n",ansf,anss);
    return 0;
}
