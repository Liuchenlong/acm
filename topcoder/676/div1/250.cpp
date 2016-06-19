// BEGIN CUT HERE

// END CUT HERE
#line 5 "WaterTank.cpp"
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
#define eps 1e-20
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))

bool check(vector <int> t, vector <int> x, int C,double v)
{
    double sum=0.0;
    for(int i=0;i<t.size();i++)
    {
        sum=sum+(double)t[i]*x[i]-(double)t[i]*v;
        sum=MAX(sum,0);
        if(sum>C+eps)
            return false;
    }
    return true;
}

class WaterTank
{
        public:
        double minOutputRate(vector <int> t, vector <int> x, int C)
        {
                double l=0,r=1e10;
                int tim=200;
                while(tim--)
                {
                    double mid=(r+l)/2.0;
                    if(check(t,x,C,mid))
                        r=mid;
                    else
                        l=mid;
                }
                return l;
        }


};

