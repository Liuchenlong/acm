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
int h[24];
int H1,H2;
int a,b;
int cal(int tim)
{
    if(tim<=21&&tim>=10)
        return a;
    return -b;
}
int main()
{
    scanf("%d%d",&H1,&H2);
    scanf("%d%d",&a,&b);
    int ans=0;
    int pos=14;
    for(int i=0; i<24; i++)
        h[i]=-999999;
    h[14]=H1;
    while(1)
    {
        int det=cal(pos);
        if(h[pos]+det<=h[(pos+1)%24])
        {
            ans=-1;
            break;
        }
        if(h[pos]+det>=H2)
            break;
        h[(pos+1)%24]=h[pos]+det;
        pos++;
        if(pos==24)
        {
            ans++;
            pos=0;
        }
    }
    printf("%d\n",ans);
    return 0;
}
