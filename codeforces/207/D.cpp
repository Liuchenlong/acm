#include <bits/stdc++.h>

using namespace std;

int cnt[1000005][26];

long long n,m;
char str1[1000005];
char str2[1000005];
long long len1,len2;
long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    scanf("%I64d%I64d",&n,&m);
    scanf("%s",str1);
    scanf("%s",str2);
    len1=strlen(str1);
    len2=strlen(str2);
    long long GCD=gcd(len1,len2);
    long long LCM=lcm(len1,len2);
    long long ans=n*len1;
    long long sum=n*len1/LCM;
    for(int i=0;i<len2;i++)
    {
        cnt[i%GCD][str2[i]-'a']++;
    }
    for(int i=0;i<len1;i++)
    {
        ans-=sum*cnt[i%GCD][str1[i]-'a'];
    }
    printf("%I64d\n",ans);
    return 0;
}
