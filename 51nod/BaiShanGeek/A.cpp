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

int main()
{
//    for(int i=1;i<10;i++)
//    {
//        for(int j=1;j<10;j++)
//        {
//            printf("%d %d \n",(i*j)/10,(i*j)%10);
//        }
//    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b,d,n;
        scanf("%d%d%d%d",&a,&b,&d,&n);
        if(a*b<10)
        {
            if(a*b==d)
                printf("%d\n",n);
            else
                printf("0\n");
        }
        else
        {
            int n1,n2,n3;
            n1=a*b/10;
            n2=a*b%10;
            n3=n1+n2;
            if(n3<10)
            {
                int ans=0;
                if(n1==d)
                    ans++;
                if(n2==d)
                    ans++;
                if(n3==d)
                    ans+=n-1;
                printf("%d\n",ans);
            }
            else
            {
                int ans=0;
                if(n2==d)
                    ans++;
                if(n3%10==d&&n>1)
                {
                    ans++;
                }
                if(n1+1==d&&n>1)
                {
                    ans++;
                }
                if(n1==d&&n==1)
                    ans++;
                if(n3%10+1==d&&n>2)
                {
                    ans+=n-2;
                }
                printf("%d\n",ans);

            }
        }

    }
    return 0;
}
