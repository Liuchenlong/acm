#include <bits/stdc++.h>
using namespace std ;

int n,m,k;
long long d,x,y;
long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
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
bool merge(long long a1,long long m1,long long a2,long long m2,long long &a3,long long &m3)
{
    long long d=gcd(m1,m2);
    long long c=a2-a1;
    if(c%d!=0)
        return false;
    c=(c%m2+m2)%m2;
    m1/=d;
    m2/=d;
    c/=d;
    exgcd(m1,m2,x,y);
    x=(x%m2+m2)%m2;
    c*=x;
    c%=m2;
    c*=m1*d;
    c+=a1;
    m3=m1*m2*d;
    a3=(c%m3+m3)%m3;
    return true;
}
long long china(int n,long long a[],long long m[])
{
    long long a1=a[0];
    long long m1=m[0];
    for(int i=1; i<n; i++)
    {
        long long a2=a[i];
        long long m2=m[i];
        long long m3,a3;
        if(!merge(a1, m1, a2, m2, a3, m3))//无解
            return -1;
        a1=a3;
        m1=m3;
    }
    return (a1%m1+m1)%m1;
}
long long A[2],M[2];
long long update(long long a,long long b)
{
    if(b==-1)return a;
    if(a==-1)return b;
    return min(a,b);
}
long long ans;
void output()
{
    printf("%I64d %I64d %I64d\n",A[0],A[1],ans);
}
long long cal(long long x,long long y)
{
    M[0]=2LL*n;
    M[1]=2LL*m;
    ans=-1;
    A[0]=x,A[1]=y;
    ans=update(ans,china(2,A,M));
    A[0]=x,A[1]=m+m-y;
    ans=update(ans,china(2,A,M));
    A[0]=n+n-x,A[1]=y;
    ans=update(ans,china(2,A,M));
    A[0]=n+n-x,A[1]=m+m-y;
    ans=update(ans,china(2,A,M));
    return ans;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<k; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%I64d\n",cal(x,y));
    }
    return 0;
}
