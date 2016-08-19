#include<stdio.h>
#include<cmath>
#include<cstring>
long long d,x,y;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        long long ret=exgcd(b,a%b,x,y);
        long long temp=x;
        x=y;
        y=temp-a/b*y;
        return ret;
    }
}
int n;
long long a[10];
long long p,p2;
long long cal(long long x)
{
    long long ans=0;
    for(int i=0; i<=n; i++)
    {
        long long tmp=a[i];
        for(int j=0; j<n-i; j++)
            tmp=tmp*x;
        ans=(ans+tmp);
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        scanf("%d",&n);
        for(int i=0; i<=n; i++)
            scanf("%I64d",&a[i]);
        scanf("%I64d",&p);
        p2=p*p;
        int flag=0;
        printf("Case #%d: ",cas);
        for(int i=0; i<p; i++)
        {
            long long fx=cal(i);
            if(fx%p==0)
            {
                long long dx=0;
                for(int j=0;j<n;j++)
                {
                    long long tmp=a[j]*(n-j);
                    for(int k=0;k<n-j-1;k++)
                    {
                        tmp=tmp*i;
                    }
                    dx+=tmp;
                }
                d=exgcd(dx,p,x,y);
                long long c=(p-(fx/p)%p)%p;
                if(c%d==0)
                {
                    x=(x%p+p)%p;
                    x=x*(c/d)%p;
                    flag=1;
                    printf("%I64d\n",((p*x+i)%p2+p2)%p2);
                    break;
                }
            }
        }
        if(!flag)
            printf("No solution!\n");
    }
    return 0;
}
