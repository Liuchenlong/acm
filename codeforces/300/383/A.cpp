#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if(n==0)puts("1");
    else
    {
        if(n%4==1)puts("8");
        else if(n%4==2)puts("4");
        else if(n%4==3)puts("2");
        else puts("6");
    }
    return 0;
}
