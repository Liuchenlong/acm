#include<stdio.h>
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

int n;
int main()
{
    scanf("%d",&n);
    long long now=2;
    for(int i=1;i<=n;i++)
    {
        long long nxt=1LL*i*(i+1);
        printf("%I64d\n",(nxt/i*nxt-now/i));
        now=nxt;
    }
    return 0;
}
