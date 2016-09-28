#include<stdio.h>
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
char str[50005];
int cnt[27];
int len;
void update(char ch,int info)
{
    if(ch=='?')return ;
    cnt[ch-'A']+=info;
}
bool check()
{
    for(int i=0;i<26;i++)if(cnt[i]>1)return false;
    return true;
}
int main()
{
    scanf("%s",str);
    len=strlen(str);
    if(len<26)printf("-1\n");
    else
    {
        for(int i=0;i<25;i++)if(str[i]!='?')
        cnt[str[i]-'A']++;
        for(int i=25;i<len;i++)
        {
            update(str[i],1);
            if(check())
            {
                vector<int>vec;
                int head=0;
                for(int j=0;j<26;j++)if(cnt[j]==0)vec.push_back(j);
                for(int j=i-25;j<=i;j++)
                {
                    if(str[j]=='?')
                        str[j]='A'+vec[head++];
                }
                for(int j=0;j<len;j++)if(str[j]=='?')str[j]='A';
                puts(str);
                return 0;
            }
            update(str[i-25],-1);
        }
        puts("-1");
    }
    return 0;
}
