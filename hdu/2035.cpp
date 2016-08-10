#include<stdio.h>
int qpow(int a,int b)
{
    if(b==0)
        return 1;
    if(b%2==0)
    {
        int term=qpow(a,b/2);
        return term*term%1000;
    }
    else
    {
        int term=qpow(a,(b-1)/2);
        return (a%1000)*term*term%1000;
    }
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)&&(a||b))
    {
        printf("%d\n",qpow(a,b));
    }
    return 0;
}
