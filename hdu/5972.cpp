#include <cstdio>
#include <cstring>
#include <set>
#include <bitset>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
int n;
bitset<1010>p[11],ans;
char str[5000005];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<10;i++)p[i].set();
        for(int i=0;i<n;i++)
        {
            int k;
            scanf("%d",&k);
            for(int j=0;j<k;j++)
            {
                int x;scanf("%d",&x);
                p[x][i]=0;
            }
        }
        scanf("%s",str);
        int len=strlen(str);
        ans.set();
        for(int i=0;i<len;i++)
        {
            ans=(ans<<1)|p[str[i]-'0'];
            if(ans[n-1]==0)
            {
                char ch=str[i+1];
                str[i+1]='\0';
                printf("%s\n",str+i-n+1);
                str[i+1]=ch;
            }
        }
    }
    return 0;
}
