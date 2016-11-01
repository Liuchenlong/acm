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
int maxn=7*7*7*7*7*7*7;
vector<int>v1,v2;
int getlen(int x)
{
    if(x==0)return 1;
    int ans=0;
    while(x)
    {
        ans++;
        x/=7;
    }
    return ans;
}
bool check(int x,int y,int len1,int len2)
{
    int num[7]={0};
    for(int i=0;i<len1;i++)
    {
        num[x%7]++;
        x/=7;
    }
    for(int j=0;j<len2;j++)
    {
        if(num[y%7])
            return false;
        y/=7;
    }
    return true;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(n>maxn||m>maxn)
        printf("0\n");
    else
    {
        int len1,len2;
        len1=getlen(n-1);
        len2=getlen(m-1);
        if(len1+len2>7)
        {
            printf("0\n");
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            set<int>s;
            int t=i;
            for(int j=0;j<len1;j++)
            {
                s.insert(t%7);
                t/=7;
            }
            if(s.size()==len1)
                v1.push_back(i);
        }
        for(int i=0;i<m;i++)
        {
            set<int>s;
            int t=i;
            for(int j=0;j<len2;j++)
            {
                s.insert(t%7);
                t/=7;
            }
            if(s.size()==len2)
                v2.push_back(i);
        }
        long long ans=0;
        for(int i=0;i<v1.size();i++)
            for(int j=0;j<v2.size();j++)
            if(check(v1[i],v2[j],len1,len2))
            {
                ans++;
            }
        printf("%I64d\n",ans);
    }
    return 0;
}
