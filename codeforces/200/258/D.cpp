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
char str[100005];
int a[2],b[2];
int main()
{
    scanf("%s",str);
    long long ans1=0,ans2=0;
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {

        if(str[i]=='a')
        {
            a[i&1]++;
            ans1+=a[i&1];
            ans2+=a[1^(i&1)];
        }
        else
        {
            b[i&1]++;
            ans1+=b[i&1];
            ans2+=b[1^(i&1)];
        }
    }
    printf("%I64d %I64d\n",ans2,ans1);
    return 0;
}
