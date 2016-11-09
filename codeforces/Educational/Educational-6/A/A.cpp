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

int main()
{
    int x1,y1;
    int x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    printf("%d\n",max(abs(x1-x2),abs(y1-y2)));
    return 0;
}
