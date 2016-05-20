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
const double eps = 1e-15;
long long ten[16];
bool check(string s)
{
    reverse(s.begin(),s.end());
    if(atoi(s.c_str())==1)
        return true;
    return false;
}
long long solve(long long x)
{
    char str[20];
    sprintf(str,"%I64d",x);
    string s=str;
    int len=s.length();
    long long ans=1;
    if(len==1)
        return x;
    for(int i=1;i<len;i++)
    {
        ans=ans+ten[(i+1)/2]-1;
        if(i>1)
        {
            ans++;
            ans=ans+ten[i/2]-1;
        }
    }
    string L=s.substr(0,len/2);
    string R=s.substr(len/2);
    if(atoi(R.c_str())==0)
        return solve(x-1)+1LL;
    if(check(L))
        return ans+atoi(R.c_str());
    reverse(L.begin(),L.end());
    ans+=atoi(L.c_str());
    ans++;
    ans+=atoi(R.c_str())-1;
    return ans;
}
int main()
{
//    freopen("A-small-practice.in","r",stdin);
//    freopen("A-small-practice.out","w",stdout);
//    freopen("A-large-practice.in","r",stdin);
//    freopen("A-large-practice.out","w",stdout);
    ten[0]=1;
    for(int i=1;i<16;i++)
        ten[i]=ten[i-1]*10LL;
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        long long n;
        scanf("%I64d",&n);
        printf("Case #%d: %I64d\n",cas,solve(n));
    }
    return 0;
}
