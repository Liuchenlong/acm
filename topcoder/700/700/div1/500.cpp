// BEGIN CUT HERE

// END CUT HERE
#line 5 "CrazyFunctions.cpp"
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
long long qpow(long long x,long long k)
{
    long long ans=1;
    while(k)
    {
        if(k&1)
            ans=ans*x%mod;
        k>>=1;
        x=x*x%mod;
    }
    return ans;
}

class CrazyFunctions
{
public:
    int count(int n, int k)
    {
        long long fac[5005];
        fac[0]=1;
        for(int i=1; i<=n; i++)
        {
            fac[i]=fac[i-1]*i%mod;
        }
        long long ans=fac[n]*qpow(fac[n-k],mod-2)%mod;
        ans=ans*k%mod;
        ans=ans*qpow(n,n-k+mod-2)%mod;
        return (int)ans;
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
        if ((Case == -1) || (Case == 6)) test_case_6();
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
        int Arg0 = 2;
        int Arg1 = 1;
        int Arg2 = 2;
        verify_case(0, Arg2, count(Arg0, Arg1));
    }
    void test_case_1()
    {
        int Arg0 = 2;
        int Arg1 = 2;
        int Arg2 = 2;
        verify_case(1, Arg2, count(Arg0, Arg1));
    }
    void test_case_2()
    {
        int Arg0 = 1;
        int Arg1 = 1;
        int Arg2 = 1;
        verify_case(2, Arg2, count(Arg0, Arg1));
    }
    void test_case_3()
    {
        int Arg0 = 3;
        int Arg1 = 1;
        int Arg2 = 9;
        verify_case(3, Arg2, count(Arg0, Arg1));
    }
    void test_case_4()
    {
        int Arg0 = 3;
        int Arg1 = 3;
        int Arg2 = 6;
        verify_case(4, Arg2, count(Arg0, Arg1));
    }
    void test_case_5()
    {
        int Arg0 = 5;
        int Arg1 = 3;
        int Arg2 = 900;
        verify_case(5, Arg2, count(Arg0, Arg1));
    }
    void test_case_6()
    {
        int Arg0 = 5000;
        int Arg1 = 5000;
        int Arg2 = 541108809;
        verify_case(6, Arg2, count(Arg0, Arg1));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    CrazyFunctions ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
