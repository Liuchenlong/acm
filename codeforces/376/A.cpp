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
int main()
{
    scanf("%s",str+1);
    str[0]='a';
    int len=strlen(str);
    int ans=0;
    for(int i=0;i<len-1;i++)
    {
        if(str[i]<str[i+1])
            ans+=min(str[i+1]-str[i],str[i]+26-str[i+1]);
        else
            ans+=min(str[i]-str[i+1],str[i+1]+26-str[i]);
    }
    printf("%d\n",ans);
    return 0;
}
