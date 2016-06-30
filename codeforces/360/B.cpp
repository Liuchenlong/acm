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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
char str[1000005];
int main()
{
    scanf("%s",str);
    printf("%s",str);
    reverse(str,str+strlen(str));
    printf("%s\n",str);
    return 0;
}
