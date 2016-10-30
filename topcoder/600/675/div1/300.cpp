// BEGIN CUT HERE

// END CUT HERE
#line 5 "TreeAndPathLength3.cpp"
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


class TreeAndPathLength3
{
public:
    vector <int> construct(int s)
    {
        vector<int>ans;
        ans.push_back(0);
        ans.push_back(1);
        int x=(int)sqrt(s)-1;
        s-=x*x;
        int pos=2;
        for(int tim=0; tim<x; tim++)
        {
            ans.push_back(pos++);
            ans.push_back(0);
            ans.push_back(pos++);
            ans.push_back(1);
        }
        for(int i=0; i<s; i++)
        {
            ans.push_back(pos);
            ans.push_back(pos-1);
            pos++;
            if(i==0)
            {
                s-=x;
                s++;
            }
        }
        return ans;
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
    void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received)
    {
        cerr << "Test Case #" << Case << "...";
        if (Expected == Received) cerr << "PASSED" << endl;
        else
        {
            cerr << "FAILED" << endl;
            cerr << "\tExpected: " << print_array(Expected) << endl;
            cerr << "\tReceived: " << print_array(Received) << endl;
        }
    }
    void test_case_0()
    {
        int Arg0 = 1;
        int Arr1[] = {0, 1, 1, 2, 2, 3 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(0, Arg1, construct(Arg0));
    }
    void test_case_1()
    {
        int Arg0 = 2;
        int Arr1[] = {0, 1, 1, 2, 2, 3, 3, 4 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(1, Arg1, construct(Arg0));
    }
    void test_case_2()
    {
        int Arg0 = 6;
        int Arr1[] = {0, 1, 1, 2, 0, 3, 3, 4, 0, 5, 5, 6 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(2, Arg1, construct(Arg0));
    }
    void test_case_3()
    {
        int Arg0 = 8;
        int Arr1[] = {0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 5, 6, 5, 7 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(3, Arg1, construct(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TreeAndPathLength3 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
