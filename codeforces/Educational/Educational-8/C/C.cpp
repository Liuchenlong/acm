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
vector <char>vec;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",str);
    for(int i=0;i<n;i++)
    {
        int t=min(max('z'-str[i],str[i]-'a'),k);
        k-=t;
        if(str[i]+t<='z')
            vec.push_back(str[i]+t);
        else if(str[i]-t>='a')
            vec.push_back(str[i]-t);
    }
    if(k)
        puts("-1");
    else
    {
        for(int i=0;i<vec.size();i++)
            printf("%c",vec[i]);
        printf("\n");
    }
    return 0;
}
