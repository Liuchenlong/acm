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
int n,m;
char str[1005][1005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",str[i]);
    }
    set<int>s;
    for(int i=0;i<n;i++)
    {
        int pre=-1;
        for(int j=0;j<m;j++)
        {
            if(str[i][j]=='G')
            {
                pre=j;
            }
            if(str[i][j]=='S')
            {
                if(pre==-1)
                {
                    printf("-1\n");
                    return 0;
                }
                s.insert(j-pre);
            }
        }
    }
    printf("%d\n",s.size());
    return 0;
}
