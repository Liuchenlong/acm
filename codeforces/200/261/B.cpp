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
#define SIZE 1000005

int num[200005];
map<int,long long>mp;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        mp[num[i]]++;
    }
    sort(num,num+n);
    if(num[0]==num[n-1])
        printf("0 %I64d\n",mp[num[0]]*(mp[num[0]]-1)/2);
    else
    {
        printf("%d %I64d\n",num[n-1]-num[0],mp[num[0]]*mp[num[n-1]]);
    }
    return 0;
}
