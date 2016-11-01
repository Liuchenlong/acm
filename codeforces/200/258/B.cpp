#include<cstdio>
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
#define eps 1e-8
#define LL long long
#define pii pair<int,int>
int n;
int a[100005];
pair<int,int>pr[100005];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        pr[i]=make_pair(a[i],i);
    }
    sort(pr,pr+n);
    bool flag=false;
    pair<int,int>ans;
    for(int i=0;i<n;i++)
    {
        if(pr[i].second!=i)
        {
            ans=make_pair(i+1,pr[i].second+1);
            flag=true;
            int len=pr[i].second-i+1;
            for(int j=i;j<i+len/2;j++)
                swap(a[j],a[pr[i].second-(j-i)]);
            break;
        }
    }
    if(flag)
    {
        bool check=true;
        for(int i=1;i<n;i++)
        {
            if(a[i]<a[i-1])
            {
                check=false;
                break;
            }
        }
        if(!check)
            printf("no\n");
        else
        {
            printf("yes\n");
            printf("%d %d\n",ans.first,ans.second);
        }
    }
    else
    {
        printf("yes\n");
        printf("1 1\n");
    }
    return 0;
}
