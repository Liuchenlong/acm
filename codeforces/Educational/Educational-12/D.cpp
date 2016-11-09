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
#define SIZE 2000005
bool notprime[SIZE];
void getprime()
{
    for(int i=2;i<SIZE;i++)
    {
        if(notprime[i])
            continue;
        for(int j=2*i;j<SIZE;j+=i)
            notprime[j]=1;
    }
}
int n;
int num[1005];
vector<int>ans;
int main()
{
    getprime();
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    sort(num,num+n);
    int one=0;
    for(int i=0;i<n;i++)
    {
        if(num[i]>1)
        {
            for(int j=i+1;j<n;j++)
            {
                if(notprime[num[i]+num[j]]==0)
                {
                    if(ans.size()==0)
                    {
                        ans.push_back(num[i]);
                        ans.push_back(num[j]);
                    }
                }
            }
        }
        else
        {
            one++;
        }
    }
    if(one)
    {
        for(int i=0;i<n;i++)
        {
            if(num[i]>1&&notprime[num[i]+1]==0)
            {
                ans.clear();
                for(int j=0;j<one;j++)
                    ans.push_back(1);
                ans.push_back(num[i]);
                break;
            }
        }
        if(one>ans.size())
        {
            ans.clear();
            for(int i=0;i<one;i++)
                ans.push_back(1);
        }
    }
    if(ans.size()==0)
    {
        ans.push_back(num[0]);
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
