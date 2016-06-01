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

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n;
        scanf("%d",&n);
        char name[10];
        scanf("%s",name);
        printf("Case %d: ",cas);
        if(name[0]=='A')
        {
            if(n%3==1)
                printf("Bob\n");
            else
                printf("Alice\n");
        }
        else
        {
            if(n%3==0)
                printf("Alice\n");
            else
                printf("Bob\n");
        }
    }
    return 0;
}
