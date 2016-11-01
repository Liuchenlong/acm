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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
char str[1005];
char ans[1005];
int main()
{
    scanf("%s",str);
    int len=strlen(str);
    int res=0;
    int pose=0;
    for(int i=0; i<len; i++)
    {
        if(str[i]=='e')
        {
            pose=i;
            for(int j=i+1; j<len; j++)
            {
                res=res*10+str[j]-'0';
            }
            break;
        }
    }
    int l=0;
    int flag=0;
    for(int i=0; i<pose; i++)
    {
        if(str[i]=='.')
        {
            flag=1;
            continue;
        }
        if(flag)
        {
            if(res)
            {
                ans[l++]=str[i];
                res--;
            }
            else
            {
                ans[l++]='.';
                ans[l++]=str[i];
                flag=false;
            }
        }
        else
        {
            ans[l++]=str[i];
        }
    }
    while(res--)
    {
        ans[l++]='0';
    }
    int head=0;
    int tail=l-1;
    while(head<l-1&&ans[head]=='0')head++;
    if(ans[head]=='.')head--;
    int flg=0;
    for(int i=head; i<l; i++)if(ans[i]=='.')
        {
            flg=1;
            break;
        }
    if(flg)
    {
        while(tail>head&&ans[tail]=='0')tail--;
        if(ans[tail]=='.')tail--;
    }
    for(int i=head; i<=tail; i++)printf("%c",ans[i]);
    printf("\n");
    return 0;
}
