// BEGIN CUT HERE

// END CUT HERE
#line 5 "WinterAndSnowmen.cpp"
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
long long dp[2005][2100][2];
int n,m;
void run(int pos)
{
    dp[0][0][0]=1;
    for(int i=1; i<=max(n,m); i++)
    {
        for(int j=0; j<2048; j++)
        {
            for(int k=0; k<2; k++)
            {
                dp[i][j][k]=dp[i-1][j][k];
                if(i<=n)
                {
                    dp[i][j][k]+=dp[i-1][j^(i>>pos)][k^((i>>pos)&1)];
                }
                if(i<=m)
                {
                    dp[i][j][k]+=dp[i-1][j^(i>>pos)][k];
                }
                dp[i][j][k]%=mod;
            }
        }
    }
}
class WinterAndSnowmen
{
public:
    int getNumber(int N, int M)
    {
        n=N;
        m=M;
        long long ans=0;
        for(int i=0; i<11; i++)
        {
            run(i);
            ans+=dp[max(N,M)][1][0];
        }
        return (int)(ans%mod);
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
        int Arg0 = 2;
        int Arg1 = 2;
        int Arg2 = 4;
        verify_case(0, Arg2, getNumber(Arg0, Arg1));
    }
    void test_case_1()
    {
        int Arg0 = 1;
        int Arg1 = 1;
        int Arg2 = 1;
        verify_case(1, Arg2, getNumber(Arg0, Arg1));
    }
    void test_case_2()
    {
        int Arg0 = 3;
        int Arg1 = 5;
        int Arg2 = 74;
        verify_case(2, Arg2, getNumber(Arg0, Arg1));
    }
    void test_case_3()
    {
        int Arg0 = 7;
        int Arg1 = 4;
        int Arg2 = 216;
        verify_case(3, Arg2, getNumber(Arg0, Arg1));
    }
    void test_case_4()
    {
        int Arg0 = 47;
        int Arg1 = 74;
        int Arg2 = 962557390;
        verify_case(4, Arg2, getNumber(Arg0, Arg1));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    WinterAndSnowmen ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
