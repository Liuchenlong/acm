// BEGIN CUT HERE

// END CUT HERE
#line 5 "DivFree.cpp"
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
int MOD = 1e9+7;
long long dp[22][50005];
long long seq[22];
long long bad[50005];
long long good[50005];
long long powk[50005];
class DivFree
{
public:
    int dfcount(int n, int k)
    {
        memset(seq,0,sizeof(seq));
        memset(dp,0,sizeof(dp));
        powk[0]=1;
        for(int i=1; i<=n; i++)
            powk[i]=(powk[i-1]*k)%MOD;
        int maxk=20;
        for(int i=1; i<=k; i++)
            dp[1][i]=1;
        for(int i=2; i<=20; i++)
        {
            for(int j=1; j<=k; j++)
            {
                for(int t=2*j; t<=k; t+=j)
                    dp[i][t]=(dp[i][t]+dp[i-1][j])%MOD;
            }
            for(int j=1; j<=k; j++)
                seq[i]=(seq[i]+dp[i][j])%MOD;
        }

        good[0]=1;
        good[1]=k;
        bad[1]=0;
        for(int i=2;i<=n;i++)
        {
            bad[i]=bad[i-1]*k%MOD;
            for(int j=2;j<=i&&j<=20;j++)
            {
                long long sig;
                if(j%2==0)
                    sig=1;
                else
                    sig=(MOD-1);
                bad[i]=bad[i]+sig*good[i-j]%MOD*seq[j]%MOD;
                bad[i]%=MOD;
            }
            good[i]=((powk[i]-bad[i])%MOD+MOD)%MOD;
        }
        return good[n];
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
        int Arg1 = 2;
        int Arg2 = 3;
        verify_case(0, Arg2, dfcount(Arg0, Arg1));
    }
    void test_case_1()
    {
        int Arg0 = 3;
        int Arg1 = 2;
        int Arg2 = 4;
        verify_case(1, Arg2, dfcount(Arg0, Arg1));
    }
    void test_case_2()
    {
        int Arg0 = 3;
        int Arg1 = 3;
        int Arg2 = 15;
        verify_case(2, Arg2, dfcount(Arg0, Arg1));
    }
    void test_case_3()
    {
        int Arg0 = 1;
        int Arg1 = 107;
        int Arg2 = 107;
        verify_case(3, Arg2, dfcount(Arg0, Arg1));
    }
    void test_case_4()
    {
        int Arg0 = 5;
        int Arg1 = 6;
        int Arg2 = 2292;
        verify_case(4, Arg2, dfcount(Arg0, Arg1));
    }
    void test_case_5()
    {
        int Arg0 = 42;
        int Arg1 = 23;
        int Arg2 = 301026516;
        verify_case(5, Arg2, dfcount(Arg0, Arg1));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    DivFree ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
