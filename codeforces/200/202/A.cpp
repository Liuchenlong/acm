#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define eps 1e-12

int cnt[3];
int main()
{
    int n;
    scanf("%d",&n);
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x==25)
            cnt[0]++;
        else if(x==50)
        {
            if(cnt[0])
            {
                cnt[0]--;
                cnt[1]++;
            }
            else
                flag=0;
        }
        else
        {
            if(cnt[1]&&cnt[0])
            {
                cnt[1]--;
                cnt[0]--;
                cnt[2]++;
            }
            else if(cnt[0]>=3)
            {
                cnt[0]-=3;
                cnt[2]++;
            }
            else
                flag=0;
        }
    }
    if(flag)printf("YES\n");
    else printf("NO\n");
    return 0;
}
