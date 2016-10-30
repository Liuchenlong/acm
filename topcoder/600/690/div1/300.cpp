// BEGIN CUT HERE

// END CUT HERE
#line 5 "WolfCardGame.cpp"
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


class WolfCardGame
{
public:
    vector <int> createAnswer(int N, int K)
    {
        for(int i=4; i*K<=100&&i<=7; i++)
        {
            if(N%i!=0)
            {
                vector<int>ans;
                for(int j=1; j<=K; j++)
                    ans.push_back(i*j);
                return ans;
            }
        }
        vector<int>ans;
        ans.push_back(1);
        for(int i=1; i<=14; i++)ans.push_back(i*7);
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
        int Arg0 = 20;
        int Arg1 = 4;
        int Arr2[] = {1, 2, 3, 4 };
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        verify_case(0, Arg2, createAnswer(Arg0, Arg1));
    }
    void test_case_1()
    {
        int Arg0 = 40;
        int Arg1 = 1;
        int Arr2[] = {39 };
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        verify_case(1, Arg2, createAnswer(Arg0, Arg1));
    }
    void test_case_2()
    {
        int Arg0 = 97;
        int Arg1 = 6;
        int Arr2[] = {7, 68, 9, 10, 62, 58 };
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        verify_case(2, Arg2, createAnswer(Arg0, Arg1));
    }
    void test_case_3()
    {
        int Arg0 = 2;
        int Arg1 = 12;
        int Arr2[] = {33, 69, 42, 45, 96, 15, 57, 12, 93, 9, 54, 99 };
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        verify_case(3, Arg2, createAnswer(Arg0, Arg1));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    WolfCardGame ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
