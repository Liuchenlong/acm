#include<stdio.h>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int t[1000005];
int main()
{
    int n,c;
    scanf("%d%d",&n,&c);
    for(int i=0;i<n;i++)scanf("%d",&t[i]);
    int ans=1;
    int now=t[0];
    for(int i=1;i<n;i++)
    {
        if(t[i]-now<=c)
        {
            now=t[i];
            ans++;
        }
        else
        {
            now=t[i];
            ans=1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
