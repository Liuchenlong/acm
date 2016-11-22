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
int n;
int num[100005];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
    if(n==1)
    {
        puts("-1");
    }
    else if(n==2)
    {
        sort(num,num+n);
        if(num[0]==num[1])
        {
            printf("1\n%d\n",num[0]);
        }
        else
        {
            if((num[1]-num[0])%2==0)
            {
                printf("3\n%d %d %d\n",num[0]-(num[1]-num[0]),(num[0]+num[1])/2,num[1]+(num[1]-num[0]));
            }
            else
            {
                printf("2\n%d %d\n",num[0]-(num[1]-num[0]),num[1]+(num[1]-num[0]));
            }
        }
    }
    else
    {
        sort(num,num+n);
        int det=num[1]-num[0];
        for(int i=1;i<n;i++)
            det=min(det,num[i]-num[i-1]);
        if(det==0)
        {
            if(num[n-1]==num[0])
            {
                printf("1\n%d\n",num[0]);
            }
            else
                printf("0\n");
        }
        else
        {
            int cnt=0;
            int ans;
            for(int i=1;i<n;i++)
            {
                if((num[i]-num[i-1])%det==0)
                {
                    int d=(num[i]-num[i-1])/det;
                    if(d==2)
                    {
                        cnt++;
                        ans=num[i-1]+det;
                    }
                    else if(d>2)
                    {
                        printf("0\n");
                        return 0;
                    }
                }
                else
                {
                    printf("0\n");
                    return 0;
                }
            }
            if(cnt>1)
            {
                printf("0\n");
            }
            else if(cnt==1)
            {
                printf("1\n%d\n",ans);
            }
            else
            {
                printf("2\n%d %d\n",num[0]-det,num[n-1]+det);
            }
        }
    }
    return 0;
}
