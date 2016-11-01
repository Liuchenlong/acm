#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
int n,k;
unsigned long long seed=131;
unsigned long long Hash[2000005];
unsigned long long pw[2000005];
unsigned long long gethash(int l,int r)
{
    if(l==0)
        return Hash[r];
    else
        return Hash[r]-Hash[l-1]*pw[r-l+1];
}
unsigned long long gethash(string str)
{
    int len=str.length();
    unsigned long long H=0;
    for(int i=0;i<len;i++)
        H=H*seed+str[i]-'a'+1;
    return H;
}
map<unsigned long long ,vector<int> >mp;
vector<int>vec[100005];
bool vis[100005];
string str;
string str2[100005];
bool check(int pos)
{
    vector<int>ans;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
    {
        vector<int>v=mp[gethash(pos+i*k,pos+(i+1)*k-1)];
        if(v.size()==0)return false;
        else if(v.size()==1)
        {
            if(vis[v[0]])return false;
            ans.push_back(v[0]);
            vis[v[0]]=1;
        }
        else
        {
            string sub=str.substr(pos+i*k,k);
            bool flag=false;
            for(int j=0;j<v.size();j++)
            {
                if(sub==str2[v[j]])
                {
                    if(vis[v[j]])return false;
                    flag=true;
                    ans.push_back(v[j]);
                    vis[v[j]]=1;
                    break;
                }
            }
            if(!flag)
                return false;
        }
    }
    printf("YES\n");
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    printf("\n");
    return true;
}

int main()
{
    pw[0]=1;
    for(int i=1;i<2000005;i++)pw[i]=pw[i-1]*seed;
    scanf("%d%d",&n,&k);
    cin>>str;
    int len=n*k;
    unsigned long long hs=0;
    for(int i=0;i<len*2;i++)
    {
        hs=hs*seed+(str[i%len]-'a'+1);
        Hash[i]=hs;
    }
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        cin>>str2[i];
        mp[gethash(str2[i])].push_back(i);
    }
    for(int i=0;i<k;i++)
    {
        if(check(i))
        {
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
