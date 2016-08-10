#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define eps 1e-9
const double pi=acos(-1.0);

int main()
{
    int a,b;
    while(1)
    {

        scanf("%d%d",&a,&b);
        vector<int>vec;
        if(a==0&&b==0)break;
        for(int i=0;i<100;i++)
        {
            if((a*100+i)%b==0)
                vec.push_back(i);
        }
        for(int i=0;i<vec.size();i++)
        {
            if(i)printf(" ");
            printf("%02d",vec[i]);
        }
        printf("\n");
    }
    return 0;
}
