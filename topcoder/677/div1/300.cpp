// BEGIN CUT HERE

// END CUT HERE
#line 5 "DoubleOrOneEasy.cpp"
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
int INF=1000000000;

class DoubleOrOneEasy
{
public:
    int minimalSteps(int a, int b, int newA, int newB)
    {
        int ans=INF;
        int p=1;
        int m=0;
        while((a<=newA/p)&&(b<=newB/p))
        {
            if(newA-p*a==newB-p*b)
            {
                int tmp=newA-p*a;
                int q=p;
                int m2=0;
                while(tmp)
                {
                    m2+=tmp/q;
                    tmp%=q;
                    q/=2;
                }
                ans=MIN(ans,m+m2);
            }
            p*=2;
            m++;
        }
        return (ans==INF?-1:ans);
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
        int Arg0 = 100;
        int Arg1 = 1000;
        int Arg2 = 101;
        int Arg3 = 1001;
        int Arg4 = 1;
        verify_case(0, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_1()
    {
        int Arg0 = 100;
        int Arg1 = 1000;
        int Arg2 = 202;
        int Arg3 = 2002;
        int Arg4 = 2;
        verify_case(1, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_2()
    {
        int Arg0 = 2;
        int Arg1 = 2;
        int Arg2 = 1;
        int Arg3 = 1;
        int Arg4 = -1;
        verify_case(2, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_3()
    {
        int Arg0 = 1;
        int Arg1 = 111111111;
        int Arg2 = 8;
        int Arg3 = 888888888;
        int Arg4 = 3;
        verify_case(3, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_4()
    {
        int Arg0 = 1;
        int Arg1 = 111111111;
        int Arg2 = 9;
        int Arg3 = 999999999;
        int Arg4 = -1;
        verify_case(4, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    DoubleOrOneEasy ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
