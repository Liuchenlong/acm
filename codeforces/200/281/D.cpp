#include<stdio.h>
#include<math.h>
#include<cmath>
#include<vector>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) (a<b?a:b)
#define ll long long
#define INF 9223372036854775807
int main()
{
    int n;
    scanf("%d",&n);
    if(n%2==1)
        printf("black\n");
    else
    {
        printf("white\n1 2\n");
    }
    return 0;
}
