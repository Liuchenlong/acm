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
long long mod=1e9+7;
char table[1005][1005];
int num[1005][1005];
int stepl[1005][1005];
int stepr[1005][1005];
int stepu[1005][1005];
int stepd[1005][1005];
int steplu[1005][1005];
int stepld[1005][1005];
int stepru[1005][1005];
int steprd[1005][1005];
double suml[1005][1005],sumr[1005][1005],sumu[1005][1005],sumd[1005][1005];
double sumlu[1005][1005],sumld[1005][1005],sumru[1005][1005],sumrd[1005][1005];
int n;
double cal(int i,int j)
{
    if(num[i][j]==0)
        return 0;
    return log(num[i][j]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%s",table[i]+1);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        num[i][j]=table[i][j]-'0';
    int flag=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        if(num[i][j]!=0)
        flag=1;
    if(flag==0)
    {
        printf("0\n");
        return 0;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
    {
        suml[i][j]=suml[i][j-1];
        sumu[i][j]=sumu[i-1][j];
        sumlu[i][j]=sumlu[i-1][j-1];
        if(num[i][j]==0)
            continue;
        suml[i][j]+=log(num[i][j]);
        sumu[i][j]+=log(num[i][j]);
        sumlu[i][j]+=log(num[i][j]);
        stepl[i][j]=stepl[i][j-1]+1;
        stepu[i][j]=stepu[i-1][j]+1;
        steplu[i][j]=steplu[i-1][j-1]+1;
    }
    for(int i=1;i<=n;i++)for(int j=n;j>=1;j--)
    {
        sumru[i][j]=sumru[i-1][j+1];
        sumr[i][j]=sumr[i][j+1];
        if(num[i][j]==0)
            continue;
        sumru[i][j]+=log(num[i][j]);
        sumr[i][j]+=log(num[i][j]);
        stepru[i][j]=stepru[i-1][j+1]+1;
        stepr[i][j]=stepr[i][j+1]+1;
    }
    for(int i=n;i>=1;i--)for(int j=1;j<=n;j++)
    {
        sumld[i][j]=sumld[i+1][j-1];
        sumd[i][j]=sumd[i+1][j];
        if(num[i][j]==0)
            continue;
        sumld[i][j]+=log(num[i][j]);
        sumd[i][j]+=log(num[i][j]);
        stepld[i][j]=stepld[i+1][j-1]+1;
        stepd[i][j]=stepd[i+1][j]+1;
    }
    for(int i=n;i>=1;i--)for(int j=n;j>=1;j--)
    {
        sumrd[i][j]=sumrd[i+1][j+1];
        if(num[i][j]==0)
            continue;
        sumrd[i][j]+=log(num[i][j]);
        steprd[i][j]=steprd[i+1][j+1]+1;
    }
    double ans=-1;
    int ansx,ansy;
    int ansd;
    int ansflag;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int d=min(stepl[i][j],stepr[i][j]);
            d=min(stepu[i][j],d);
            d=min(stepd[i][j],d);
            double sum=suml[i][j+d-1]-suml[i][j-d];
            sum+=sumu[i+d-1][j]-sumu[i-d][j];
            sum-=cal(i,j);
            if(sum>ans)
            {
                ans=sum;
                ansx=i;
                ansy=j;
                ansd=d;
                ansflag=0;
            }
            d=min(steplu[i][j],stepld[i][j]);
            d=min(d,stepru[i][j]);
            d=min(d,steprd[i][j]);
            sum=sumlu[i+d-1][j+d-1]-sumlu[i-d][j-d];
            sum+=sumld[i-d+1][j+d-1]-sumld[i+d][j-d];
            sum-=cal(i,j);
            if(sum>ans)
            {
                ans=sum;
                ansx=i;
                ansy=j;
                ansd=d;
                ansflag=1;
            }
        }
    }
    long long tans=1;
    if(ansflag==0)
    {
        for(int i=ansx-ansd+1;i<=ansx+ansd-1;i++)
            tans=tans*num[i][ansy]%mod;
        for(int j=ansy-ansd+1;j<=ansy+ansd-1;j++)
        {
            if(j==ansy)
                continue;
            tans=tans*num[ansx][j]%mod;
        }
    }
    if(ansflag==1)
    {
        for(int i=-(ansd-1);i<=(ansd-1);i++)
            tans=tans*num[ansx+i][ansy+i]%mod;
        for(int i=-(ansd-1);i<=(ansd-1);i++)
        {
            if(i==0)
                continue;
            tans=tans*num[ansx-i][ansy+i]%mod;
        }
    }
    printf("%I64d\n",tans);
    return 0;
}
