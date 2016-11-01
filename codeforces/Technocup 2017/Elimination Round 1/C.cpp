#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-12
int ans[5005];
int main()
{
    int n;
    scanf("%d",&n);
    int a12,a23,a13;
    printf("? 1 2\n");fflush(stdout);scanf("%d",&a12);
    printf("? 2 3\n");fflush(stdout);scanf("%d",&a23);
    printf("? 1 3\n");fflush(stdout);scanf("%d",&a13);
    ans[1]=(a12-a23+a13)/2;
    ans[2]=a12-ans[1];
    ans[3]=a23-ans[2];
    for(int i=4;i<=n;i++)
    {
        printf("? %d %d\n",i-1,i);
        fflush(stdout);
        int x;scanf("%d",&x);
        ans[i]=x-ans[i-1];
    }
    printf("!");
    for(int i=1;i<=n;i++)printf(" %d",ans[i]);
    printf("\n");
    fflush(stdout);
    return 0;
}
