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
int a[4],b[4];
bool check(int pos)
{
    int n1=a[pos];
    int n2=0;
    char str[10];
    sprintf(str,"%d",b[pos]);
    for(int i=0;i<strlen(str);i++)
        n2=n2*2+str[i]-'0';
    return n1!=n2;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {

        scanf("%d.%d.%d.%d",&a[0],&a[1],&a[2],&a[3]);
        scanf("%d.%d.%d.%d",&b[0],&b[1],&b[2],&b[3]);
        int flag=1;
        for(int i=0;i<4;i++)
            if(check(i))
        {
            flag=0;
            break;
        }
        if(flag)
            printf("Case %d: Yes\n",cas);
        else
            printf("Case %d: No\n",cas);
    }
    return 0;
}
