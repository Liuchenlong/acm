#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))
#define eps 1e-12


int A[200005],B[200005];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    sort(A,A+n);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&B[i]);
    }
    for(int i=0;i<m;i++)
    {
        printf("%d ",upper_bound(A,A+n,B[i])-A);
    }
    printf("\n");

    return 0;
}
