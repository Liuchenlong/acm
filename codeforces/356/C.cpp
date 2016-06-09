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

vector<int>vec;
bool prime(int x)
{
    if(x==2)return true;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
int main()
{
    for(int i=2;i<=100;i++)
    {
        if(prime(i))
            vec.push_back(i);
    }
    int sum=0;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]>50)
            break;
        printf("%d\n",vec[i]);
        fflush(stdout);
        char str[5];
        scanf("%s",str);
        if(str[0]=='n')
            ;
        else
        {
            sum++;
            if(vec[i]*vec[i]<=100)
            {
                printf("%d\n",vec[i]*vec[i]);
                fflush(stdout);
                scanf("%s",str);
                if(str[0]=='y')
                {
                    printf("composite\n");
                    fflush(stdout);
                    return 0;
                }
            }
        }
    }
    if(sum>1)
    {
        printf("composite\n");
        fflush(stdout);
    }
    else
    {
        printf("prime\n");
        fflush(stdout);
    }
    return 0;
}
