#include <bits/stdc++.h>
using namespace std;

long long len[55];
int n;
long long k;
int cal(long long l)
{
    if(l==1)
        return 1;
    for(int i=50;i>=1;i--)
    {
        if(l>len[i-1]&&l<=len[i])
        {
            if(l==len[i-1]+1)
            return i;
            return cal(l-len[i-1]-1);
        }
    }
}
int main()
{
    len[1]=1;
    for(int i=2;i<=50;i++)len[i]=len[i-1]*2+1;
    scanf("%d%I64d",&n,&k);
    printf("%d\n",cal(k));
    return 0;
}
