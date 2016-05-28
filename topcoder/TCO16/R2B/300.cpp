// BEGIN CUT HERE

// END CUT HERE
#line 5 "TriangleTriples.cpp"
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
long long mod=1e9+7;
long long inv=166666668;
long long C(long long x)
{
    if(x<=1)
        return 0;
    return (x+1)*x%mod*(x-1)%mod*inv%mod;
}
long long cal(int a,int b,int c)
{
    long long ans=C(c);
    ans-=C(c-a);
    ans-=C(c-b);
    ans+=C(c-a-b);
    return (ans%mod+mod)%mod;
}

class TriangleTriples
{
public:
    int count(int A, int B, int C)
    {
        long long ans=(long long)A*B%mod*C%mod;
        ans-=cal(A,B,C);
        ans-=cal(B,C,A);
        ans-=cal(C,A,B);
        return (ans%mod+mod)%mod;
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
        int Arg0 = 1;
        int Arg1 = 10;
        int Arg2 = 20;
        int Arg3 = 10;
        verify_case(0, Arg3, count(Arg0, Arg1, Arg2));
    }
    void test_case_1()
    {
        int Arg0 = 2;
        int Arg1 = 2;
        int Arg2 = 1000000000;
        int Arg3 = 6;
        verify_case(1, Arg3, count(Arg0, Arg1, Arg2));
    }
    void test_case_2()
    {
        int Arg0 = 10;
        int Arg1 = 10;
        int Arg2 = 10;
        int Arg3 = 505;
        verify_case(2, Arg3, count(Arg0, Arg1, Arg2));
    }
    void test_case_3()
    {
        int Arg0 = 1;
        int Arg1 = 1;
        int Arg2 = 1;
        int Arg3 = 1;
        verify_case(3, Arg3, count(Arg0, Arg1, Arg2));
    }
    void test_case_4()
    {
        int Arg0 = 123456789;
        int Arg1 = 987654321;
        int Arg2 = 555555555;
        int Arg3 = 64296241;
        verify_case(4, Arg3, count(Arg0, Arg1, Arg2));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TriangleTriples ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
