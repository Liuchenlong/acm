#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
const double pi=acos(-1.0);
struct line
{
    int sum;
} l[505];
int num[505][505];
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0; i<n; i++)
    {
        int s=0;
        for(int j=0; j<m; j++)
        {
            scanf("%d",&num[i][j]);
        }
    }
    for(int i=0; i<n; i++)
    {
        int s=0;
        int pos=0;
        while(pos<m)
        {
            int term=0;
            if(num[i][pos]==1)
            {
                int j;
                for(j=pos; j<m; j++)
                {
                    if(num[i][j]==1)
                        term++;
                    else
                    {
                        break;
                    }
                }
                pos=j;
                s=max(s,term);
            }
            else
                pos++;
        }
        l[i].sum=s;
    }
    for(int i=0; i<q; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        num[a-1][b-1]^=1;
        int maxans=0;

        int s=0;
        int pos=0;
        while(pos<m)
        {
            int term=0;
            if(num[a-1][pos]==1)
            {
                int j;
                for(j=pos; j<m; j++)
                {
                    if(num[a-1][j]==1)
                        term++;
                    else
                    {
                        break;
                    }
                }
                pos=j;
                s=max(s,term);
            }
            else
                pos++;
        }
        l[a-1].sum=s;

        for(int j=0; j<n; j++)
        {
            maxans=max(maxans,l[j].sum);
        }
        printf("%d\n",maxans);
    }
    return 0;
}
