#include <bits/stdc++.h>

using namespace std;
int ans[3000005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        ans[i]=i;
    for(int i=2;i<=n;i++)
    {
        int pre=i-1;
        int last=n+pre;
        for(int j=n/i;j>=0;j--)
        {
            int head=pre+j*i;
            swap(ans[head],ans[last]);
            last=head;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[n+i-1]);
    return 0;
}
