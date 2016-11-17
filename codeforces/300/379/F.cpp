#include<bits/stdc++.h>

using namespace std;
int n;
long long b[200005];
long long c[200005];
long long a[200005];
int cnt[32];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%I64d",&b[i]);
    for(int i=0;i<n;i++)scanf("%I64d",&c[i]);
    long long sum=0;
    for(int i=0;i<n;i++)sum+=(b[i]+c[i]);
    if(sum%(n*2)==0)
    {
        sum/=(n*2);
        for(int i=0;i<n;i++)
        {
            long long d=b[i]+c[i]-sum;
            if(d%n==0)
            {
                a[i]=d/n;
            }
            else
            {
                puts("-1");
                return 0;
            }
        }
        for(int i=0;i<32;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[j]&(1LL<<i))
                    cnt[i]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            long long val=0;
            for(int j=0;j<32;j++)
            {
                if(a[i]&(1LL<<j))
                    val+=(1LL<<j)*cnt[j];
            }
            if(val!=b[i])
            {
                puts("-1");
                return 0;
            }
        }
        for(int i=0;i<n;i++)
        {
            long long val=0;
            for(int j=0;j<32;j++)
            {
                if(a[i]&(1LL<<j))
                    val+=(1LL<<j)*n;
                else
                    val+=(1LL<<j)*cnt[j];
            }
            if(c[i]!=val)
            {
                puts("-1");
                return 0;
            }
        }
        for(int i=0;i<n;i++)
            printf("%I64d ",a[i]);
        printf("\n");

    }
    else
    {
        puts("-1");
    }
    return 0;
}
