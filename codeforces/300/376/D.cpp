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
int n,c;
int a[1000005];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int info)
{
    for(int i=x;i<=1000000;i+=lowbit(i))
        a[i]+=info;
}
int sum(int x)
{
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i))
        ans+=a[i];
    return ans;
}
int l[2],num[2][500005];
int main()
{
    scanf("%d%d",&n,&c);
    scanf("%d",&l[0]);for(int i=0;i<l[0];i++)scanf("%d",&num[0][i]);
    int now=1,pre=0;
    int cnt=0;
    for(int i=1;i<n;i++)
    {
        scanf("%d",&l[now]);
        for(int j=0;j<l[now];j++)scanf("%d",&num[now][j]);
        for(int j=0;;j++)
        {
            if(j==l[pre])break;
            if(j==l[now])
            {
                cnt++;
                break;
            }
            if(num[pre][j]!=num[now][j])
            {
                cnt++;
                if(num[pre][j]>num[now][j])
                {
                    add(c-num[pre][j]+1,1);
                    add(c-num[now][j]+1,-1);
                }
                else
                {
                    add(1,1);add(c-num[now][j]+1,-1);
                    add(c-num[pre][j]+1,1);
                }
                break;
            }
        }
        swap(now,pre);
    }
    int ans=-1;
    for(int i=1;i<=1000000;i++)
    {
        if(sum(i)==cnt)
        {
            ans=i;
            break;
        }
    }
    printf("%d\n",(ans==-1?-1:ans%c));
    return 0;
}
