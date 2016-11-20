#include <bits/stdc++.h>

using namespace std;
int ans[100005];
int main()
{
    int n;
    scanf("%d",&n);
    if(n%4==0||n%4==1)
    {
        for(int i=1;i<=(n+1)/2;i+=2)
        {
            if(i==(n+1)/2)
            {
                ans[i]=i;
            }
            else
            {
                ans[i]=i+1;
                ans[i+1]=n-i+1;
                ans[n-i+1]=n-i;
                ans[n-i]=i;
            }
        }
        for(int i=1;i<=n;i++)
            printf("%d ",ans[i]);
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}
