#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
#define eps 1e-8
int n;
vector<int>vec;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        vec.push_back(x);
    }
    sort(vec.begin(),vec.end());
    n=unique(vec.begin(),vec.end())-vec.begin();
    if(n==1||n==2)puts("YES");
    else if(n==3)
    {
        if(vec[0]+vec[2]==2*vec[1])
            puts("YES");
        else puts("NO");
    }
    else puts("NO");
    return 0;
}
