// BEGIN CUT HERE

// END CUT HERE
#line 5 "Dubs.cpp"
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


class Dubs
{
public:
    long long count(long long L, long long R)
    {
        int n1=L%10;
        int n2=(L/10)%10;
        if(n1<=n2)
            L=L/10;
        else
            L=L/10+1;
        n1=R%10;
        n2=(R/10)%10;
        if(n1<n2)
            R=R/10-1;
        else
            R=R/10;
        return max(0LL,R-L+1);
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
    void verify_case(int Case, const long long &Expected, const long long &Received)
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
        long long Arg0 = 10LL;
        long long Arg1 = 10LL;
        long long Arg2 = 0LL;
        verify_case(0, Arg2, count(Arg0, Arg1));
    }
    void test_case_1()
    {
        long long Arg0 = 10LL;
        long long Arg1 = 20LL;
        long long Arg2 = 1LL;
        verify_case(1, Arg2, count(Arg0, Arg1));
    }
    void test_case_2()
    {
        long long Arg0 = 49LL;
        long long Arg1 = 101LL;
        long long Arg2 = 6LL;
        verify_case(2, Arg2, count(Arg0, Arg1));
    }
    void test_case_3()
    {
        long long Arg0 = 1111111LL;
        long long Arg1 = 111111111LL;
        long long Arg2 = 11000001LL;
        verify_case(3, Arg2, count(Arg0, Arg1));
    }
    void test_case_4()
    {
        long long Arg0 = 91750002841LL;
        long long Arg1 = 91751522033LL;
        long long Arg2 = 151920LL;
        verify_case(4, Arg2, count(Arg0, Arg1));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Dubs ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
