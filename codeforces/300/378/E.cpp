#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
int n;
char str[1000005];
int numu[1000005],numd[1000005];
vector<int>posu,posd;
int sizu,sizd;
long long sumu[1000005];
long long sumd[1000005];
long long ans[1000005];
int main()
{
    scanf("%d",&n);
    scanf("%s",str+1);
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        numu[i]=cnt;
        if(str[i]=='U')cnt++;
    }
    cnt=0;
    for(int i=n; i>=1; i--)
    {
        numd[i]=cnt;
        if(str[i]=='D')cnt++;
    }
    posu.push_back(0);
    posd.push_back(0);
    for(int i=1; i<=n; i++)
    {
        if(str[i]=='U')posu.push_back(i);
        else posd.push_back(i);
    }
    sizu=posu.size();
    sizd=posd.size();
    for(int i=0; i<sizu; i++)
    {
        if(i)
            sumu[i]=sumu[i-1]+posu[i];
        else
            sumu[i]=posu[i];
    }
    for(int i=0; i<sizd; i++)
    {
        if(i)
            sumd[i]=sumd[i-1]+posd[i];
        else
            sumd[i]=posd[i];
    }
    for(int i=1;i<=n; i++)
    {
        if(str[i]=='U')///U
        {
            if(numd[i]<=numu[i])///up
            {
                ans[i]+=n-i+1;
                if(numd[i]>0)
                {
                    int pos=lower_bound(posd.begin(),posd.end(),i)-posd.begin();
                    ans[i]+=2LL*((sumd[sizd-1]-sumd[pos-1])-1LL*i*numd[i]);
                    pos=lower_bound(posu.begin(),posu.end(),i)-posu.begin()-1;
                    ans[i]+=2LL*(1LL*i*numd[i]-(sumu[pos]-sumu[pos-numd[i]]));
                }
            }
            else///down
            {
                ans[i]+=i;
                if(numu[i]>0)
                {
                    int pos=lower_bound(posd.begin(),posd.end(),i)-posd.begin();
                    ans[i]+=2LL*(sumd[pos+numu[i]]-sumd[pos-1]-1LL*i*(numu[i]+1));
                    pos=lower_bound(posu.begin(),posu.end(),i)-posu.begin()-1;
                    ans[i]+=2LL*(1LL*i*numu[i]-sumu[pos]);
                }
                else if(numu[i]==0)
                {
                    int pos=lower_bound(posd.begin(),posd.end(),i)-posd.begin();
                    ans[i]+=2LL*(posd[pos]-i);
                }
            }
        }
        else///D
        {
            if(numu[i]<=numd[i])///down
            {
                ans[i]+=i;
                if(numu[i]>0)
                {
                    int pos=lower_bound(posd.begin(),posd.end(),i)-posd.begin();
                    ans[i]+=2LL*(sumd[pos+numu[i]]-sumd[pos]-1LL*i*numu[i]);
                    pos=lower_bound(posu.begin(),posu.end(),i)-posu.begin()-1;
                    ans[i]+=2LL*(1LL*i*numu[i]-sumu[pos]);
                }
            }
            else///up
            {
                ans[i]+=n-i+1;
                if(numd[i]>0)
                {
                    int pos=lower_bound(posd.begin(),posd.end(),i)-posd.begin();
                    ans[i]+=2LL*((sumd[sizd-1]-sumd[pos])-1LL*i*numd[i]);
                    pos=lower_bound(posu.begin(),posu.end(),i)-posu.begin()-1;
                    ans[i]+=2LL*(1LL*i*(numd[i]+1)-(sumu[pos]-sumu[pos-numd[i]-1]));
                }
                else
                {
                    int pos=lower_bound(posu.begin(),posu.end(),i)-posu.begin()-1;
                    ans[i]+=2LL*(i-posu[pos]);
                }
            }
        }
        printf("%I64d ",ans[i]);
    }
    printf("\n");
    return 0;
}
