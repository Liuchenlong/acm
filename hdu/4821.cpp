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
const double pi=acos(-1.0);
unsigned long long seed=131;
unsigned long long pw[100005];
unsigned long long hs[100005];
int m,l;
char str[100005];
int len;
unsigned long long gethash(int l,int r)
{
    if(l==0)return hs[r];
    return hs[r]-hs[l-1]*pw[r-l+1];
}
int main()
{
    pw[0]=1;
    for(int i=1;i<=100000;i++)pw[i]=pw[i-1]*seed;
    while(scanf("%d%d",&m,&l)!=EOF)
    {
        scanf("%s",str);
        len=strlen(str);
        hs[0]=str[0]-'a'+1;
        for(int i=1;i<len;i++)hs[i]=hs[i-1]*seed+str[i]-'a'+1;
        int ans=0;
        for(int i=0;i<l;i++)
        {
            map<unsigned long long,int>mp;
            int cnt=0;
            for(int j=0;j<m;j++)
            {
                unsigned long long hh=gethash(i+j*l,i+(j+1)*l-1);
                if(mp[hh]==0)cnt++;
                mp[hh]++;
            }
            if(cnt==m)ans++;
            int head=i,tail=i+m*l;
            while(tail+l<=len)
            {
                unsigned long long hh=gethash(head,head+l-1);
                if(mp[hh]==1)cnt--;
                mp[hh]--;
                head+=l;
                hh=gethash(tail,tail+l-1);
                if(mp[hh]==0)cnt++;
                mp[hh]++;
                tail+=l;
                if(cnt==m)
                    ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
