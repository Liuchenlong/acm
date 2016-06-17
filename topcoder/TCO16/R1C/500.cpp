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
char str[55];
char ans[55];
int n;
int numa,numb,numc;
bool dfs(int pos,int num)
{
    if(num==0)
    {
        int tb=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='C')
            {
                ans[i]='C';
                continue;
            }
            if((i>0&&ans[i-1]=='B')||(tb==numb))
            {
                ans[i]='A';
            }
            else
            {
               ans[i]='B';
               tb++;
            }
        }
        if(tb<numb)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    if(pos>=n)
        return false;
    if(dfs(pos+1,num))
        return true;
    str[pos]='C';
    if(dfs(pos+3,num-1))
        return true;
    str[pos]=' ';
    return false;
}
class 	ThreeProgrammers
{
public :
    string validCodeHistory(string code)
    {
        memset(str,0,sizeof(str));
        numa=0,numb=0,numc=0;
        for(int i=0;i<code.length();i++)
        {
            if(code[i]=='A')
                numa++;
            else if(code[i]=='B')
                numb++;
            else if(code[i]=='C')
                numc++;
        }
        n=code.length();
        if(dfs(0,numc))
        {
            return string(ans);
        }
        else
            return "impossible";

    }
};
