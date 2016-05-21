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
map<string,int>mp;
char str[44];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        sort(str,str+strlen(str));
        string s(str);
        printf("%d\n",mp[s]);
        mp[s]++;
    }
    return 0;
}
