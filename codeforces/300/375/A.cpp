#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int ans=100000;
    for(int i=0;i<=100;i++)
    {
        int tmp=abs(i-a)+abs(i-b)+abs(i-c);
        ans=min(ans,tmp);
    }
    printf("%d\n",ans);
    return 0;
}
