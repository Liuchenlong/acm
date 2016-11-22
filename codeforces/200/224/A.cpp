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
char str[1005];
string s1,s2;
int main()
{
    scanf("%s",str);
    string s=string(str);
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        if(s[i]=='|')
        {
            s1=s.substr(0,i);
            s2=s.substr(i+1);
        }
    }
    scanf("%s",str);
    s=string(str);
    len=s.length();
    int l1=s1.length();
    int l2=s2.length();
    if((len+l1+l2)%2==0&&abs(l1-l2)<=len)
    {
        if(l1<l2)
        {
            int ll1=l2-l1+(len-(l2-l1))/2;
            s1=s1+s.substr(0,ll1);
            s2=s2+s.substr(ll1);
        }
        else
        {
            int ll2=l1-l2+(len-(l1-l2))/2;
            s2=s2+s.substr(0,ll2);
            s1=s1+s.substr(ll2);
        }
        cout<<s1<<"|"<<s2<<endl;
    }
    else
        puts("Impossible");
    return 0;
}
