#include <bits/stdc++.h>

using namespace std;


int n,m;
char str[105];
bool vis[105];
int len;
bool check(int pos)
{
    vis[pos]=1;
    if(str[pos]=='T')
        return true;
    int ans=0;
    if(pos+m<len&&str[pos+m]!='#'&&vis[pos+m]==0)
        ans|=check(pos+m);
    if(pos-m>=0&&str[pos-m]!='#'&&vis[pos-m]==0)
        ans|=check(pos-m);
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",str);
    len=strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]=='G')
        {
            if(check(i))
                printf("YES\n");
            else
                printf("NO\n");
            return 0;
        }
    }
    return 0;
}
