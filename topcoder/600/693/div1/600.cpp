// BEGIN CUT HERE

// END CUT HERE
#line 5 "BipartiteConstruction.cpp"
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

class BipartiteConstruction
{
public:
    vector <int> construct(int K)
    {

        vector<int>ans;
        ans.push_back(20);
        for(int i=0; i<20; i++)
        {
            if(i<19)
            {
                ans.push_back(i*20+i);
                ans.push_back(i*20+i);
                ans.push_back(i*20+i);
            }
            if(i)
                ans.push_back(i*20+i-1);
        }
        int t=K;
        int pos=0;
        while(t)
        {
            int res=t%3;
            t/=3;
            for(int i=0; i<res; i++)
                ans.push_back(pos*20+19);
            pos++;
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
        int Arg0 = 2;
        int Arr1[] = {3, 8, 1, 7, 4, 3, 0 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(0, Arg1, construct(Arg0));
    }
    void test_case_1()
    {
        int Arg0 = 5;
        int Arr1[] = {1, 0, 0, 0, 0, 0 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(1, Arg1, construct(Arg0));
    }
    void test_case_2()
    {
        int Arg0 = 0;
        int Arr1[] = {2, 1, 0 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(2, Arg1, construct(Arg0));
    }
    void test_case_3()
    {
        int Arg0 = 2333333;
        int Arr1[] = {20, 93, 195, 195, 211, 87, 114, 369, 390, 216, 195, 305, 17, 370, 356, 308, 150, 263, 20, 153, 331, 79, 344, 108, 114, 257, 245, 289, 211, 388, 388, 359, 293, 263, 219, 131, 201, 293, 279, 204, 97, 367, 90, 279, 308, 324, 323, 359, 338, 63, 26, 318, 218, 226, 164, 361, 276, 388, 343, 149, 17, 336, 88, 161, 76, 237, 136, 278, 302, 107, 271, 15, 382, 45, 338, 264, 78, 150, 220, 341, 180, 20, 252, 94, 114, 161 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(3, Arg1, construct(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    BipartiteConstruction ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
