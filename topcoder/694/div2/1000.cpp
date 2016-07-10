// BEGIN CUT HERE

// END CUT HERE
#line 5 "UpDownNess.cpp"
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
const long long mod=1e9+7;
long long dp[2][5005];
class UpDownNess
{
public:
    int count(int N, int K)
    {
        int now=0,next=1;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=2; i<=N; i++)
        {
            memset(dp[next],0,sizeof(dp[next]));
            for(int j=0; j<i; j++)
            {
                int det=j*(i-1-j);
                for(int k=det; k<=5000; k++)
                {
                    dp[next][k]+=dp[now][k-det];
                }
            }
            for(int j=0; j<=5000; j++)
                dp[next][j]%=mod;
            swap(now,next);
        }
        return (int)dp[now][K];
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
        int Arg0 = 3;
        int Arg1 = 1;
        int Arg2 = 2;
        verify_case(0, Arg2, count(Arg0, Arg1));
    }
    void test_case_1()
    {
        int Arg0 = 3;
        int Arg1 = 0;
        int Arg2 = 4;
        verify_case(1, Arg2, count(Arg0, Arg1));
    }
    void test_case_2()
    {
        int Arg0 = 4;
        int Arg1 = 3;
        int Arg2 = 4;
        verify_case(2, Arg2, count(Arg0, Arg1));
    }
    void test_case_3()
    {
        int Arg0 = 19;
        int Arg1 = 19;
        int Arg2 = 24969216;
        verify_case(3, Arg2, count(Arg0, Arg1));
    }
    void test_case_4()
    {
        int Arg0 = 50;
        int Arg1 = 2000;
        int Arg2 = 116596757;
        verify_case(4, Arg2, count(Arg0, Arg1));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    UpDownNess ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
