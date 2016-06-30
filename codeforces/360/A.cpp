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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
int n,k;
int type[105];
char table[105][105];
bool check(char str[])
{
    for(int i=0;i<n;i++)
        if(str[i]=='0')
        return true;
    return false;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++)
        scanf("%s",table[i]);
    for(int i=0;i<k;i++)
        type[i]=check(table[i]);
    int ans=0;
    for(int i=0;i<k;i++)
    {
        if(type[i]==1)
        {
            int num=1;
            for(int j=i+1;j<k;j++)
            {
                if(type[j]==1)
                    num++;
                else
                    break;
            }
            ans=max(ans,num);
        }
    }
    printf("%d\n",ans);
    return 0;
}
