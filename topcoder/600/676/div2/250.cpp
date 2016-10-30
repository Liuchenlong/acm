// BEGIN CUT HERE

// END CUT HERE
#line 5 "FarmvilleDiv2.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
#define eps 1e-8
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))

struct sol
{
    int tim;
    int cos;
};
bool cmp(sol a,sol b)
{
    return a.cos<b.cos;
}

class FarmvilleDiv2
{
public:
    int minTime(vector<int> time, vector<int> cost, int budget)
    {
        sol thi[105];
        int n=time.size();
        for(int i=0;i<n;i++)
        {
            thi[i].tim=time[i];
            thi[i].cos=cost[i];
        }
        sort(thi,thi+n,cmp);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int num=MIN(budget/thi[i].cos,thi[i].tim);
            budget-=num*thi[i].cos;
            thi[i].tim-=num;
            ans+=thi[i].tim;
        }
        return ans;
    }

};
