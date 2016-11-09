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
long long dp[2005][2005];
long long MOD=1e9+7;
long long ten[2005];
int m,d;
void init()
{
    ten[0]=1;
    for(int i=1; i<=2000; i++)
        ten[i]=(ten[i-1]*10)%m;
    for(int i=0; i<=9; i++)
    {
        if(i==d)
            continue;
        dp[1][i%m]++;
    }
    for(int i=2; i<=2000; i++)
    {
        if(i&1)
        {
            for(int j=0; j<=9; j++)
            {
                if(j==d)
                    continue;
                for(int k=0; k<m; k++)
                {
                    dp[i][(k*10+j)%m]+=dp[i-1][k];
                    if(dp[i][(k*10+j)%m]>=MOD)
                        dp[i][(k*10+j)%m]%=MOD;
                }
            }
        }
        else
        {
            for(int j=0; j<m; j++)
            {
                dp[i][(j*10+d)%m]+=dp[i-1][j];
                if(dp[i][(j*10+d)%m]>=MOD)
                    dp[i][(j*10+d)%m]%=MOD;
            }
        }
    }
}
char str1[2002];
char str2[2002];
bool check()
{
    int len=strlen(str1);
    for(int i=0; i<len; i+=2)
    {
        if(str1[i]-'0'==d)
            return false;
        if(i!=len-1&&str1[i+1]-'0'!=d)
            return false;
    }
    int res=0;
    for(int i=0; i<len; i++)
    {
        res=(res*10+str1[i])%m;
    }
    if(res==0)
        return true;
    return false;
}
long long solve()
{
    int len=strlen(str2);
    long long ans=0;
    for(int i=1; i<len; i++)
        ans=ans+dp[i][0];
//    printf("%I64d\n",ans);
    int pos=0;
    for(int i=0; i<len; i+=2)
    {
        if(i==len-1)
        {
            int down=0;
            if(i==0)
                down=1;
            for(int j=down; j<=str2[i]-'0'; j++)
            {
                if(j==d)
                    continue;
                if((pos+j)%m==0)
                    ans++;
            }
        }
        else if(i==len-2)
        {
            int down=0;
            if(i==0)
                down=1;
            int tmp=str2[i]-'0';
            if(str2[i+1]-'0'<d)
                tmp--;
            for(int j=down; j<=tmp; j++)
            {
                if(j==d)
                    continue;
                if((pos+j*10+d)%m==0)
                    ans++;
            }
        }
        else
        {
            int down=1;
            if(i)
                down=0;
            int up=str2[i]-'0';
            if(str2[i]-'0'>d)
            {
                if(str2[i+1]-'0'<d)
                {
                    up--;
                    for(int j=down; j<=up; j++)
                    {
                        if(j==d)
                            continue;
                        int res=m-(pos+(j*10+d)*ten[len-i-2])%m;
                        res%=m;
                        ans=ans+dp[len-i-2][res];
                    }
                    break;
                }
                else if(str2[i+1]-'0'>d)
                {
                    for(int j=down; j<=up; j++)
                    {
                        if(j==d)
                            continue;
                        int res=m-(pos+(j*10+d)*ten[len-i-2])%m;
                        res%=m;
                        ans=ans+dp[len-i-2][res];
                    }
                    break;
                }
                else
                {
                    for(int j=down; j<up; j++)
                    {
                        if(j==d)
                            continue;
                        int res=m-(pos+(j*10+d)*ten[len-i-2])%m;
                        res%=m;
                        ans=ans+dp[len-i-2][res];
                    }
                }
            }
            else if(str2[i]-'0'==d)
            {
                up--;
                for(int j=down; j<=up; j++)
                {
                    if(j==d)
                        continue;
                    int res=m-(pos+(j*10+d)*ten[len-i-2])%m;
                    res%=m;
                    ans=ans+dp[len-i-2][res];
                }
                break;
            }
            else
            {
                if(str2[i+1]-'0'<d)
                {
                    up--;
                    for(int j=down; j<=up; j++)
                    {
                        if(j==d)
                            continue;
                        int res=m-(pos+(j*10+d)*ten[len-i-2])%m;
                        res%=m;
                        ans=ans+dp[len-i-2][res];
                    }
                    break;
                }
                else if(str2[i+1]-'0'>d)
                {
                    for(int j=down; j<=up; j++)
                    {
                        if(j==d)
                            continue;
                        int res=m-(pos+(j*10+d)*ten[len-i-2])%m;
                        res%=m;
                        ans=ans+dp[len-i-2][res];
                    }
                    break;
                }
                else
                {
                    for(int j=down; j<up; j++)
                    {
                        if(j==d)
                            continue;
                        int res=m-(pos+(j*10+d)*ten[len-i-2])%m;
                        res%=m;
                        ans=ans+dp[len-i-2][res];
                    }
                }
            }
        }
        pos=(pos+(str2[i]-'0')*ten[len-i-1]+d*ten[len-i-2])%m;
    }
    long long ans2=0;
    len=strlen(str1);
    for(int i=1; i<len; i++)
        ans2=ans2+dp[i][0];
    pos=0;
    for(int i=0; i<len; i+=2)
    {
        if(i==len-1)
        {
            int down=0;
            if(i==0)
                down=1;
            for(int j=down; j<=str1[i]-'0'; j++)
            {
                if(j==d)
                    continue;
                if((pos+j)%m==0)
                    ans2++;
            }
        }
        else if(i==len-2)
        {
            int down=0;
            if(i==0)
                down=1;
            int tmp=str1[i]-'0';
            if(str1[i+1]-'0'<d)
                tmp--;
            for(int j=down; j<=tmp; j++)
            {
                if(j==d)
                    continue;
                if((pos+j*10+d)%m==0)
                    ans2++;
            }
        }
        else
        {
            int down=1;
            if(i)
                down=0;
            int up=str1[i]-'0';

            if(str1[i]-'0'>d)
            {
                if(str1[i+1]-'0'<d)
                {
                    up--;
                    for(int j=down; j<=up; j++)
                    {
                        if(j==d)
                            continue;
                        int res=m-(pos+(j*10+d)*ten[len-i-2])%m;
                        res%=m;
                        ans2=ans2+dp[len-i-2][res];
                    }
                    break;
                }
                else if(str1[i+1]-'0'>d)
                {
                    for(int j=down; j<=up; j++)
                    {
                        if(j==d)
                            continue;
                        int res=m-(pos+(j*10+d)*ten[len-i-2])%m;
                        res%=m;
                        ans2=ans2+dp[len-i-2][res];
                    }
                    break;
                }
                else
                {
                    for(int j=down; j<up; j++)
                    {
                        if(j==d)
                            continue;
                        int res=m-(pos+(j*10+d)*ten[len-i-2])%m;
                        res%=m;
                        ans2=ans2+dp[len-i-2][res];
                    }
                }
            }
            else if(str1[i]-'0'==d)
            {
                up--;
                for(int j=down; j<=up; j++)
                {
                    if(j==d)
                        continue;
                    int res=m-(pos+(j*10+d)*ten[len-i-2])%m;
                    res%=m;
                    ans2=ans2+dp[len-i-2][res];
                }
                break;
            }
            else
            {
                if(str1[i+1]-'0'<d)
                {
                    up--;
                    for(int j=down; j<=up; j++)
                    {
                        if(j==d)
                            continue;
                        int res=m-(pos+(j*10+d)*ten[len-i-2])%m;
                        res%=m;
                        ans2=ans2+dp[len-i-2][res];
                    }
                    break;
                }
                else if(str1[i+1]-'0'>d)
                {
                    for(int j=down; j<=up; j++)
                    {
                        if(j==d)
                            continue;
                        int res=m-(pos+(j*10+d)*ten[len-i-2])%m;
                        res%=m;
                        ans2=ans2+dp[len-i-2][res];
                    }
                    break;
                }
                else
                {
                    for(int j=down; j<up; j++)
                    {
                        if(j==d)
                            continue;
                        int res=m-(pos+(j*10+d)*ten[len-i-2])%m;
                        res%=m;
                        ans2=ans2+dp[len-i-2][res];
                    }
                }
            }
        }
        pos=(pos+(str1[i]-'0')*ten[len-i-1]+d*ten[len-i-2])%m;
    }
    ans-=ans2;
    if(check())
        ans++;
    ans=(ans%MOD+MOD)%MOD;
    return ans;
}
int main()
{
    scanf("%d%d",&m,&d);
    init();
    scanf("%s",str1);
    scanf("%s",str2);
    printf("%I64d\n",solve());
    return 0;
}
