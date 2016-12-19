#include <bits/stdc++.h>

using namespace std;

bool check(int n)
{
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
        return false;
    return true;
}
int main()
{
    int n;
    scanf("%d",&n);
    if(check(n))
        printf("1\n");
    else
    {
        if(n%2==0)
            printf("2\n");
        else
        {
            if(check(n-2))
                printf("2\n");
            else
                printf("3\n");
        }
    }
    return 0;
}
