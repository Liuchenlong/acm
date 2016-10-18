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
#define LL long long
#define pii pair<int,int>
LL a[3];
vector<LL>vec;
int main()
{
    for(int i=0; i<3; i++)scanf("%I64d",&a[i]);
    LL mn=min(a[0],min(a[1],a[2]));
    for(int i=0; i<3; i++)a[i]-=mn;
    vec.push_back(a[0]);
    vec.push_back(a[1]);
    vec.push_back(a[2]);
    sort(vec.begin(),vec.end());
    LL mx=vec[2];
    LL smn=vec[1];
    if(smn==0)printf("%I64d\n",2*(max(0LL,mx-1)));
    else
    {
        if(mx==smn)
            printf("%I64d\n",smn-1);
        else
            printf("%I64d\n",smn+2*(max(0LL,mx-smn-1)));
    }
    return 0;
}
