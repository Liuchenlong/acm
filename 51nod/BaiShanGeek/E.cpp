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
#define eps 1e-8
int n;
long long k;
long long ss;
int num[1000005];
int sum[1000005];
bool check(int x)
{
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1];
        if(num[i]<=x)
            sum[i]++;
    }
    long long ans=0;
    vector<int>v1,v2;
    for(int i=1; i<=n; i++)
    {
        if(i%2==1)
        {
            vector<int>::iterator iter=lower_bound(v1.begin(),v1.end(),2*sum[i]-i);
            v1.insert(iter,2*sum[i]-i);
            iter=upper_bound(v2.begin(),v2.end(),2*sum[i]-i);
            ans+=(iter-v2.begin());
            if(2*sum[i]>=i)
                ans++;
        }
        else
        {
            vector<int>::iterator iter=lower_bound(v2.begin(),v2.end(),2*sum[i]-i);
            v2.insert(iter,2*sum[i]-i);
            iter=upper_bound(v1.begin(),v1.end(),2*sum[i]-i);
            ans+=(iter-v1.begin());
        }
    }
    return ans>=(ss-k+1);
}
map<int,int>mp1,mp2;
vector<int>vec;
int main()
{
    scanf("%d%I64d",&n,&k);
    int l=0,r=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&num[i]);
        vec.push_back(num[i]);
    }
    sort(vec.begin(),vec.end());
    int siz=unique(vec.begin(),vec.end())-vec.begin();
    for(int i=0;i<siz;i++)
    {
        mp1[vec[i]]=i;
        mp2[i]=vec[i];
    }
    for(int i=1;i<=n;i++)
        num[i]=mp1[num[i]];
    for(int i=1;i<=n;i+=2)
        ss+=(n-i+1);
    l=num[1],r=num[1];
    for(int i=2; i<=n; i++)
    {
        l=min(l,num[i]);
        r=max(r,num[i]);
    }
    while(l<r)
    {
        int mid=(l+r)/2;
        if(check(mid))
            r=mid;
        else
            l=mid+1;
    }
    printf("%d\n",mp2[r]);
    return 0;
}
