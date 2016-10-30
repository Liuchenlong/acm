// BEGIN CUT HERE

// END CUT HERE
#line 5 "BiconnectedDiv1.cpp"
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

long long dp[105][3];
class BiconnectedDiv1
{
public:
    int minimize(vector <int> w1, vector <int> w2)
    {
        int n=w1.size()+1;
        memset(dp,0x3f,sizeof(dp));
        dp[1][1]=w1[0]+w2[0];
        for(int i=2; i<n; i++)
        {
            dp[i][1]=min(dp[i][1],dp[i-1][1]+w2[i-1]);
            dp[i][1]=min(dp[i][1],dp[i-1][2]+w1[i-1]+w2[i-1]);
            dp[i][2]=dp[i-1][1]+w1[i-1];
            dp[i][2]=min(dp[i][2],dp[i-1][2]+w1[i-1]+w2[i-2]);
        }
        return (int)dp[n-1][2];
    }

// BEGIN CUT HERE
public:
    void run_test(int Case)
    {
        if ((Case == -1) || (Case == 0)) test_case_0();
        if ((Case == -1) || (Case == 1)) test_case_1();
        if ((Case == -1) || (Case == 2)) test_case_2();
        if ((Case == -1) || (Case == 3)) test_case_3();
    }
private:
    template <typename T> string print_array(const vector<T> &V)
    {
        ostringstream os;
        os << "{ ";
        for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\",";
        os << " }";
        return os.str();
    }
    void verify_case(int Case, const int &Expected, const int &Received)
    {
        cerr << "Test Case #" << Case << "...";
        if (Expected == Received) cerr << "PASSED" << endl;
        else
        {
            cerr << "FAILED" << endl;
            cerr << "\tExpected: \"" << Expected << '\"' << endl;
            cerr << "\tReceived: \"" << Received << '\"' << endl;
        }
    }
    void test_case_0()
    {
        int Arr0[] = {5428, 6273, 3854, 7841, 1547};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {9267, 8368, 5955, 3866};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 34431;
        verify_case(0, Arg2, minimize(Arg0, Arg1));
    }
    void test_case_1()
    {
        int Arr0[] = {3,0,4};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1,2};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 10;
        verify_case(1, Arg2, minimize(Arg0, Arg1));
    }
    void test_case_2()
    {
        int Arr0[] = {3,3,3,3};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {3,6,3};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 18;
        verify_case(2, Arg2, minimize(Arg0, Arg1));
    }
    void test_case_3()
    {
        int Arr0[] = {7243,7525,8467,6351,9453,8456,8175,5874,6869,7400,6438,8926,6876};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {2642,1743,3546,4100,2788,3019,2678,1935,1790,2674,3775,1920};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 46729;
        verify_case(3, Arg2, minimize(Arg0, Arg1));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    BiconnectedDiv1 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
