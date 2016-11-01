#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;
const int n=1000000;
int a[n];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int info)
{
    for(int i=x; i<=n; i+=lowbit(i))
    {
        a[i]+=info;
    }
}
int qry(int x)
{
    int ans=0;
    for(int i=x; i>0; i-=lowbit(i))
        ans+=a[i];
    return ans;
}
int cnt[1000005];
int num[1000005];
int atk[1000005];
int main()
{
    int q,m;
    scanf("%d%d",&q,&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d",&atk[i]);
        atk[i]-=i;
    }
    int pos=0;
    for(int i=0; i<q; i++)
    {
        int type;
        scanf("%d",&type);
        if(type==-1)
        {
            int sum=qry(n);
            for(int j=0; j<m; j++)
            {
                if(atk[j]>sum)break;
                int l=1,r=pos;
                while(l<r)
                {
                    int mid=(l+r)/2;
                    if(qry(mid)<atk[j])
                        l=mid+1;
                    else
                        r=mid;
                }
                cnt[l]--;
                sum--;
                add(l,-1);
            }
        }
        else
        {
            pos++;
            num[pos]=type;
            cnt[pos]=1;
            add(pos,1);
        }
    }
    if(qry(n)==0)
        printf("Poor stack!\n");
    else
    {
        for(int i=1; i<=pos; i++)
        {
            if(cnt[i])printf("%d",num[i]);
        }
        printf("\n");
    }
    return 0;
}
