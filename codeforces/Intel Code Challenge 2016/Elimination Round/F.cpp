#include <bits/stdc++.h>

using namespace std;
int n,m;
int k[100005];
int num[100005][42];
vector<pair<int,int> >vec[100005];
long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
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
///x=a[i](mod m[i])
long long china(int n,long long a[],long long m[])
{
    long long a1=a[0];
    long long m1=m[0];
    for(int i=1; i<n; i++)
    {
        long long a2=a[i];
        long long m2=m[i];
        long long m3,a3;
        if(!merge(a1, m1, a2, m2, a3, m3))//нч╫Б
            return -1;
        a1=a3;
        m1=m3;
    }
    return (a1%m1+m1)%m1;
}
int ans;
pair<long long,long long>pr[100005];
int tot;
pair<long long,long long>dp[100005][20];
long long a[5],mod[5];
int mm[100005];
pair<long long,long long> Union(pair<long long,long long>p1,pair<long long,long long>p2)
{
    long long LCM=lcm(p1.second,p2.second);
    if(p1.first==-1||p2.first==-1)
        return make_pair(-1,LCM);
    else
    {
        a[0]=p1.first;
        mod[0]=p1.second;
        a[1]=p2.first;
        mod[1]=p2.second;
        return make_pair(china(2,a,mod),LCM);
    }
}
bool check(int l,int r)
{
    int two=mm[r-l+1];
    return ~(Union(dp[l][two],dp[r-(1<<two)+1][two]).first);
}
void solve()
{
    if(tot==0)return ;
    for(int i=0; i<20; i++)
        for(int j=0; j<tot; j++)
        {
            if(i==0)
                dp[j][i]=make_pair(pr[j].first,k[pr[j].second]);
            else if(j+(1<<i)-1<tot)
            {
                dp[j][i]=Union(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
            }
        }
    ans=max(ans,1);
    int head=0;
    for(int i=1;i<tot;i++)
    {
        while(head<i&&check(head,i)==0)head++;
        ans=max(ans,i-head+1);
    }
}
int main()
{
    mm[0] = -1;
    for(int i = 1; i < 100005; i++)
    {
        if((i & (i - 1)) == 0) mm[i] = mm[i - 1] + 1;
        else mm[i] = mm[i - 1];
    }
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&k[i]);
        for(int j=0; j<k[i]; j++)
        {
            scanf("%d",&num[i][j]);
            vec[num[i][j]].push_back(make_pair(j,i));
        }
    }
    for(int i=1; i<=m; i++)
    {
        ans=0;
        tot=0;
        int siz=vec[i].size();
        if(siz==0)
        {
            printf("0\n");
            continue;
        }
        pr[tot++]=vec[i][0];
        for(int j=1; j<siz; j++)
        {
            if(vec[i][j].second==pr[tot-1].second+1)
            {
                pr[tot++]=vec[i][j];
            }
            else
            {
                solve();
                tot=0;
                pr[tot++]=vec[i][j];
            }
        }
        solve();
        printf("%d\n",ans);
    }
    return 0;
}
