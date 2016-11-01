#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define min(a,b) a<b?a:b
long long num[3];
int main()
{
    scanf("%I64d%I64d%I64d",&num[0],&num[1],&num[2]);
    sort(num,num+3);
    if((num[0]+num[1])*2<num[2])
    {
        printf("%I64d\n",num[0]+num[1]);
    }
    else printf("%I64d\n",(num[2]+num[0]+num[1])/3);
    return 0;
}
