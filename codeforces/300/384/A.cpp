#include <bits/stdc++.h>
using namespace std;
int n,a,b;
char str[1000005];
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    scanf("%s",str+1);
    if(str[a]==str[b])puts("0");
    else puts("1");
    return 0;
}
