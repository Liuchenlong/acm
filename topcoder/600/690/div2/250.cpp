// BEGIN CUT HERE

// END CUT HERE
#line 5 "DoubleString.cpp"
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


class DoubleString
{
public:
    string check(string S)
    {
        int n=S.length();
        if(n%2==1)
            return "not square";
        string s=S.substr(0,n/2);
        s=s+s;
        if(s==S)
            return "square";
        else
            return "not square";
    }

// BEGIN CUT HERE
public:
    void run_test(int Case)
    {
        if ((Case == -1) || (Case == 0)) test_case_0();
        if ((Case == -1) || (Case == 1)) test_case_1();
        if ((Case == -1) || (Case == 2)) test_case_2();
        if ((Case == -1) || (Case == 3)) test_case_3();
        if ((Case == -1) || (Case == 4)) test_case_4();
        if ((Case == -1) || (Case == 5)) test_case_5();
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
    void verify_case(int Case, const string &Expected, const string &Received)
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
        string Arg0 = "MAZAIMAZAI";
        string Arg1 = "square";
        verify_case(0, Arg1, check(Arg0));
    }
    void test_case_1()
    {
        string Arg0 = "MAMAZAIZAI";
        string Arg1 = "not square";
        verify_case(1, Arg1, check(Arg0));
    }
    void test_case_2()
    {
        string Arg0 = "IOI";
        string Arg1 = "not square";
        verify_case(2, Arg1, check(Arg0));
    }
    void test_case_3()
    {
        string Arg0 = "AA";
        string Arg1 = "square";
        verify_case(3, Arg1, check(Arg0));
    }
    void test_case_4()
    {
        string Arg0 = "ABCCBA";
        string Arg1 = "not square";
        verify_case(4, Arg1, check(Arg0));
    }
    void test_case_5()
    {
        string Arg0 = "Y";
        string Arg1 = "not square";
        verify_case(5, Arg1, check(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    DoubleString ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
