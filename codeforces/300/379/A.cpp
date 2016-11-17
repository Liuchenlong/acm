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
char str[100005];
int main()
{
    int len;
    scanf("%d",&len);
    scanf("%s",str);
    int ans=0;
    for(int i=0;i<len;i++)
    {
        if(str[i]=='A')ans++;
        else ans--;
    }
    if(ans>0)puts("Anton");
    else if(ans<0)puts("Danik");
    else puts("Friendship");
    return 0;
}
