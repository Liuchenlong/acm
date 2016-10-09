#include <bits/stdc++.h>
using namespace std ;

int n,m;
int num[55][55];
int nnum[55][55];
bool check(int x,int y)
{
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        nnum[i][j]=num[i][j];
    for(int i=1;i<=n;i++)swap(nnum[i][x],nnum[i][y]);
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int j=1;j<=m;j++)
        {
            if(nnum[i][j]!=j)cnt++;
        }
        if(cnt>2)return false;
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&num[i][j]);
    for(int i=1;i<=m;i++)
    {
        for(int j=i;j<=m;j++)
        {
            if(check(i,j))
            {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
