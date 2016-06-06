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

long long numx[50005];
long long numy[50005];
long long sumxp[50005],sumxl[50005];
long long sumyp[50005],sumyl[50005];
int n,m,q;

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        memset(numx,0,sizeof(numx));
        memset(numy,0,sizeof(numy));
        memset(sumxp,0,sizeof(sumxp));
        memset(sumyp,0,sizeof(sumyp));
        memset(sumxl,0,sizeof(sumxl));
        memset(sumyl,0,sizeof(sumyl));
        scanf("%d%d%d",&n,&m,&q);
        for(int i=0;i<q;i++)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            numx[x]+=w;
            numy[y]+=w;
        }
        long long resx=0,resy=0;
        for(int i=1;i<=50000;i++)
        {
            sumxp[i]=sumxp[i-1]+resx;
            resx+=numx[i];
            sumyp[i]=sumyp[i-1]+resy;
            resy+=numy[i];
        }
        resx=0;
        resy=0;
        for(int i=50000;i>=1;i--)
        {
            sumxl[i]=sumxl[i+1]+resx;
            resx+=numx[i];
            sumyl[i]=sumyl[i+1]+resy;
            resy+=numy[i];
        }
        int ansx=1,ansy=1;
        for(int i=2;i<=50000;i++)
        {
            if(sumxp[i]+sumxl[i]<sumxp[ansx]+sumxl[ansx])
                ansx=i;
            if(sumyp[i]+sumyl[i]<sumyp[ansy]+sumyl[ansy])
                ansy=i;
        }
        printf("Case %d: %d %d\n",cas,ansx,ansy);
    }
    return 0;
}
