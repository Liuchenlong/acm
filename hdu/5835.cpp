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

int a[11];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        int ans;
        if(n==1)
        {
            if(a[0]==1)ans=0;
            else ans=1;
        }
        else
        {
            int sum=0;
            sort(a,a+n);
            for(int i=0;i<n-1;i++)sum+=a[i];
            if(a[n-1]>=sum*3+2)ans=sum*2+1;
            else ans=(sum+a[n-1])/2;
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
