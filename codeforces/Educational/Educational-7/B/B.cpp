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
char str[11];
int main()
{
    scanf("%s",str);
    int hour,minute;
    hour=10*(str[0]-'0')+str[1]-'0';
    minute=10*(str[3]-'0')+str[4]-'0';
    int det;
    scanf("%d",&det);
    minute+=det;
    hour=hour+minute/60;
    minute%=60;
    hour%=24;
    printf("%02d:%02d\n",hour,minute);
    return 0;
}
