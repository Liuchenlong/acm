#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

//int num[1005];
int main()
{

    int a;
    int sum=0;
    for(int i=0;i<5;i++)
    {
        scanf("%d",&a);
        sum+=a;
    }
    if(sum%5==0&&sum!=0)
        printf("%d\n",sum/5);
    else printf("-1\n");
    return 0;
}
