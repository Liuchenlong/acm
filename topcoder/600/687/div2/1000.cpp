// BEGIN CUT HERE

// END CUT HERE
#line 5 "Queueing.cpp"
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

double dp[1005][1005];

class Queueing
{
        public:
        double probFirst(int len1, int len2, int p1, int p2)
        {
            memset(dp,0,sizeof(dp));
            double q1=1.0/p1;
            double q2=1.0/p2;
            for(int i=1;i<=len2;i++)
                dp[0][i]=1.0;
            for(int i=1;i<=len1;i++)
            {
                for(int j=1;j<=len2;j++)
                {
                    dp[i][j]=(q1*q2*dp[i-1][j-1]+(1-q1)*q2*dp[i][j-1]+q1*(1-q2)*dp[i-1][j])/(1.0-(1-q1)*(1-q2));
                }
            }
            return dp[len1][len2];
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; double Arg4 = 0.5; verify_case(0, Arg4, probFirst(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 3; int Arg3 = 7; double Arg4 = 0.9835390946502058; verify_case(1, Arg4, probFirst(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 7; int Arg3 = 3; double Arg4 = 0.010973936899862834; verify_case(2, Arg4, probFirst(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 12; int Arg1 = 34; int Arg2 = 56; int Arg3 = 78; double Arg4 = 0.999996203228025; verify_case(3, Arg4, probFirst(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 6; int Arg2 = 8; int Arg3 = 4; double Arg4 = 0.5229465300297028; verify_case(4, Arg4, probFirst(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        Queueing ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
