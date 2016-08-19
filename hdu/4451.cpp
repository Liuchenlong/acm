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
#define maxn 105
int n,m,k;
int cp,ps;
int c2p[1005][1005];
int p2s[1005];
int main()
{
    while(1)
    {
        cp=0;
        ps=0;
        memset(c2p,0,sizeof(c2p));
        memset(p2s,0,sizeof(p2s));
        scanf("%d%d%d",&n,&m,&k);
        if(n==0&&m==0&&k==0)
            break;
        int p;
        scanf("%d",&p);
        for(int i=0; i<p; i++)
        {
            char str1[10],str2[10];
            int tmp1,tmp2;
            scanf("%s%d%s%d",str1,&tmp1,str2,&tmp2);
            if(str1[0]=='c')
            {
                cp++;
                c2p[tmp1][tmp2]=1;
            }
            else
            {
                ps++;
                p2s[tmp1]++;
            }
        }
        int ans=n*m*k-k*cp-n*ps;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
                ans=ans+c2p[i][j]*p2s[j];
        }
        printf("%d\n",ans);
    }
    return 0;
}
