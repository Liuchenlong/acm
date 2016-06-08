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
int main()
{
    int n;
    scanf("%d",&n);
    if(n<10)
    {
        printf("%d\n",n);
        return 0;
    }
    long long sum=0;
    long long ten=10;
    int num=1;
    long long psum=1;
    while(1)
    {
        if(ten<n)
            sum+=(ten-psum)*num;
        else if(ten==n)
        {
            sum+=(ten-psum)*num+num+1;
            break;
        }
        else
        {
            ten/=10;
            sum+=(n-ten+1)*num;
            break;
        }
        ten*=10;
        psum*=10;
        num++;
    }
    printf("%I64d\n",sum);
    return 0;
}
