#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8

char str[1005];
double cal(string s)
{
    int len=s.length();
    double ans=0;
    if(len>3&&s[len-3]=='.')
    {
        ans+=(s[len-2]-'0')*0.1+(s[len-1]-'0')*0.01;
        len-=3;
    }
    double ans2=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='.')continue;
        ans2=ans2*10+s[i]-'0';
    }
//    printf("%f\n",ans2+ans);
    return ans2+ans;
}
void output(double n)
{
    int l=(int)n;
    if(fabs(n-l)<=eps)
    {
        if(l<1000)
            printf("%d",l);
        else
        {
            output(l/1000);
            printf(".%03d",l%1000);
        }
    }
    else
    {
        output(l);
        printf(".%02d\n",(int)((n-l+eps)*100));
    }
}
int main()
{
    scanf("%s",str);
    string s;
    int len=strlen(str);
    double ans=0;
    for(int i=0;i<len;)
    {
        if(str[i]<='z'&&str[i]>='a')
        {
            s="";
            i++;
        }
        else
        {
            while(i<len&&!(str[i]<='z'&&str[i]>='a'))
                s+=str[i++];
            ans+=cal(s);
        }
    }
    output(ans);
    return 0;
}
