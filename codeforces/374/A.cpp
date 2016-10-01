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
char str[105];
int len;
int main()
{
    scanf("%d",&len);
    scanf("%s",str);
    vector<int>vec;
    int now=0;
    for(int i=0;i<=len;i++)
    {
        if(i==len||str[i]=='W')
        {
            if(now>0)
            vec.push_back(now);
            now=0;
        }
        else
            if(str[i]=='B')
                now++;
    }
    printf("%d\n",vec.size());
    for(int i=0;i<vec.size();i++)printf("%d ",vec[i]);
    return 0;
}
