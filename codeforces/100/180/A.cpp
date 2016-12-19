#include <bits/stdc++.h>
using namespace std;

int n;
char str[1005];
int main()
{
    scanf("%d",&n);
    scanf("%s",str);
    int ans1=-1,ans2=-1;
    for(int i=0;i<n;i++)
        if(str[i]=='R')ans1=i;
    for(int i=n-1;i>=0;i--)
        if(str[i]=='L')ans2=i;
    if(ans1==-1)
        printf("%d %d\n",ans2+1,ans2);
    else if(ans2==-1)
        printf("%d %d\n",ans1+1,ans1+2);
    else
    printf("%d %d\n",ans1+2,ans2);
    return 0;
}
