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
string str;
long long cal(int l,int r)
{
    long long ans=0;
    long long tmp=str[l]-'0';
    for(int i=l+1;;)
    {
        if(i==r+1)
        {
            ans+=tmp;
            break;
        }
        if(str[i]=='+')
        {
            ans+=tmp;
            tmp=str[i+1]-'0';
            i+=2;
            continue;
        }
        if(str[i]=='*')
        {
            tmp*=str[i+1]-'0';
            i+=2;
            continue;
        }
    }
    return ans;
}
int main()
{
    cin>>str;
    str="1*"+str+"*1";
    int len=str.length();
    long long ans=0;
    for(int i=0;i<len;i++)
    {
        if(str[i]!='*')
            continue;
        for(int j=i+1;j<len;j++)
        {
            if(str[j]=='*')
            {
                long long tmp=0;
                long long t=cal(i+1,j-1);
                long long num=1;
                for(int pos=1;;)
                {
                    if(pos==len)
                    {
                        tmp+=num;
                        break;
                    }
                    if(pos==i)
                    {
                        num=num*t;
                        pos=j;
                        continue;
                    }
                    if(str[pos]=='*')
                    {
                        num*=str[pos+1]-'0';
                        pos+=2;
                        continue;
                    }
                    if(str[pos]=='+')
                    {
                        tmp+=num;
                        num=str[pos+1]-'0';
                        pos+=2;
                        continue;
                    }
                }
                ans=max(ans,tmp);
            }
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
