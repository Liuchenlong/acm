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
char str[20005];
int a[2][20005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m;
        long long n;
        scanf("%d%I64d",&m,&n);
        scanf("%s",str);
        for(int i=0;i<m;i++)
            a[0][i]=str[i]-'0';
        while(n)
        {
            long long tmp=1;
            while(tmp*3LL<=n)tmp*=3;
            for(int i=0;i<m;i++)
            {
                a[1][i]=(a[0][i]+a[0][(i+tmp)%m])%3;
            }
            for(int i=0;i<m;i++)
                a[0][i]=a[1][i];
            n-=tmp;
        }
        for(int i=0;i<m;i++)
            printf("%d",a[0][i]);
        printf("\n");
    }
    return 0;
}
