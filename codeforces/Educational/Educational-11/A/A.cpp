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
int n;
int num[1005];
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    vector<int>ans;
    int tnum=0;
    ans.push_back(num[0]);
    for(int i=1;i<n;i++)
    {
        if(gcd(num[i],ans[ans.size()-1])!=1)
        {
            tnum++;
            ans.push_back(1);
        }
        ans.push_back(num[i]);
    }
    printf("%d\n",tnum);
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
