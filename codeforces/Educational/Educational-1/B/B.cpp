#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) (a<0?-a:a)

#define eps 1e-8


char str[10005];
char chg[10005];

int main()
{
    scanf("%s",str);
    int n;
    scanf("%d",&n);
    while(n--)
    {
        memset(chg,0,sizeof(chg));
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        k=k%(r-l+1);
        int len=r-l+1;
        for(int i=0;i<len;i++)
        {
            chg[i]=str[l-1+((i-k)%len+len)%len];
        }
        for(int i=0;i<len;i++)
            str[l-1+i]=chg[i];

//        printf("%s\n",str);
    }
//    printf("\n");
    printf("%s\n",str);
    return 0;
}
