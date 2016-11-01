#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
int n,k;
int a[505];
int b[505];
vector<pair<int,int> >ans;
bool check(int l,int r,int pre)
{
    if(l==r)
        return true;
    int mx=0;
    for(int i=l; i<=r; i++)mx=max(mx,a[i]);
    for(int i=l; i<=r; i++)
    {
        int pos=i-l+1;
        if(a[i]==mx)
        {
            if(i-1>=l&&a[i-1]<a[i])
            {
                ans.push_back(make_pair(pre+pos,0));
                pos--;
                for(int j=i-2; j>=l; j--)
                {
                    ans.push_back(make_pair(pre+pos,0));
                    pos--;
                }
                for(int j=i+1; j<=r; j++)
                {
                    ans.push_back(make_pair(pre+pos,1));
                }
                return true;
            }
            if(i+1<=r&&a[i+1]<a[i])
            {
                for(int j=i+1; j<=r; j++)
                    ans.push_back(make_pair(pre+pos,1));
                for(int j=i-1; j>=l; j--)
                {
                    ans.push_back(make_pair(pre+pos,0));
                    pos--;
                }
                return true;
            }
        }
    }
    return false;
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    scanf("%d",&k);
    for(int i=1; i<=k; i++)
        scanf("%d",&b[i]);

    int now=0;
    int l=1;
    int j=1;
    for(int i=1; i<=n; i++)
    {
        now+=a[i];
        if(now==b[j])
        {
            if(!check(l,i,j-1))
            {
                printf("NO\n");
                return 0;
            }
            now=0;
            l=i+1;
            j++;
        }
        else if(now>b[j])
        {
            printf("NO\n");
            return 0;
        }
    }
    if(j<k+1)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for(int i=0; i<ans.size(); i++)
    {
        printf("%d %c\n",ans[i].first,ans[i].second==0?'L':'R');
    }
    return 0;
}
