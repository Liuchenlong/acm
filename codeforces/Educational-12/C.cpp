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
char str[200005];
int main()
{
    scanf("%s",str);
    int len=strlen(str);
    for(int i=1; i<len-1; i++)
    {
        if(str[i]==str[i-1])
        {
            for(int j=0; j<26; j++)
            {
                if(str[i-1]-'a'==j)
                    continue;
                if(str[i+1]-'a'==j)
                    continue;
                str[i]='a'+j;
                break;
            }
        }
    }
    if(str[len-1]==str[len-2])
    {
        for(int j=0; j<26; j++)
        {
            if(str[len-2]-'a'==j)
                continue;
            str[len-1]='a'+j;
        }
    }
    printf("%s\n",str);
    return 0;
}
