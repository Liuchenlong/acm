#include <bits/stdc++.h>

using namespace std;


int n;
int n1,n2;
double v[1000005];
int main()
{
    scanf("%d%d%d",&n,&n1,&n2);
    if(n1>n2)
        swap(n1,n2);
    for(int i=0;i<n;i++)scanf("%lf",&v[i]);
    double sum1=0,sum2=0;
    sort(v,v+n);
    for(int i=0;i<n1;i++)sum1+=v[n-1-i];
    for(int i=0;i<n2;i++)sum2+=v[n-n1-1-i];
    printf("%f\n",sum1/n1+sum2/n2);
    return 0;
}
