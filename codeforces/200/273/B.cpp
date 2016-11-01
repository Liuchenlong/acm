#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
long long maxx,minn;
int main()
{
  long long n,m;
  while(1)
  {
      maxx=0;
      minn=0;
      scanf("%I64d%I64d",&n,&m);
      if(n==m)
      {
          maxx=0;
          minn=0;
      }
      else
      {
          maxx=(n-m+1)*(n-m)/2;
          long long tmp=n/m;
          long long num=n-(m*tmp);
          minn=minn+num*(tmp+1)*(tmp)/2;
          minn=minn+(m-num)*(tmp)*(tmp-1)/2;
      }
  }
  printf("%I64d %I64d\n",minn,maxx);
  return 0;
}
