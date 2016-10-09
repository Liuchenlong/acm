#include <bits/stdc++.h>
using namespace std ;
int m;
int len;
char str[100005];
vector<int>pos[26];
bool vis[100005];

int N=100000;
int a[100005];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int info)
{
    for(int i=x;i<=N;i+=lowbit(i))
        a[i]+=info;
}
int sum(int x)
{
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i))
        ans+=a[i];
    return ans;
}
bool check(int ps)
{
    for(int i=0;i<pos[ps].size();i++)
        add(pos[ps][i],1);
    bool flag=true;
    for(int i=m;i<=len;i++)
    {
        if(sum(i)-sum(i-m)==0)
        {
            flag=false;
            break;
        }
    }
    if(flag)
    for(int i=0;i<pos[ps].size();i++)
        add(pos[ps][i],-1);
    return flag;
}
void solve(int ps)
{
    int siz=pos[ps].size();
    for(int i=m;i<=len;i++)
    {
        if(sum(i)-sum(i-m)==0)
        {
            printf("%c",'a'+ps);
            int pps=upper_bound(pos[ps].begin(),pos[ps].end(),i)-pos[ps].begin()-1;
            add(pos[ps][pps],1);
        }
    }
}
int main()
{
    scanf("%d",&m);
    scanf("%s",str+1);
    len=strlen(str+1);
    for(int i=1;i<=len;i++)
    {
        pos[str[i]-'a'].push_back(i);
    }
    for(int i=0;i<26;i++)
    {
        if(check(i))
        {
            solve(i);
            return 0;
        }
        for(int j=0;j<pos[i].size();j++)
            printf("%c",'a'+i);
    }
    printf("\n");
    return 0;
}
