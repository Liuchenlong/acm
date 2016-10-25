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
long long n;
char ch;
int main()
{
    scanf("%I64d%c",&n,&ch);
    n--;
    long long cnt=n/4;
    n%=4;
    long long ans=0;
    if(cnt)
    {
        ans+=cnt*(6+1+6+3);
    }
    if(n%2!=0)ans+=7;
    if(ch=='f');
    if(ch=='e')ans++;
    if(ch=='d')ans+=2;
    if(ch=='a')ans+=3;
    if(ch=='b')ans+=4;
    if(ch=='c')ans+=5;
    printf("%I64d\n",ans+1);
    return 0;
}
