#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int numx,numy;
char str[1000005];
int main()
{
    scanf("%s",str);
    for(int i=0;str[i];i++)
    {
        if(str[i]=='x')
            numx++;
        else numy++;
    }
    int t=min(numx,numy);
    numx-=t;
    numy-=t;
    for(int i=0;i<numx;i++)
        printf("x");
    for(int i=0;i<numy;i++)
        printf("y");
    printf("\n");

    return 0;
}
