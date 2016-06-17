// BEGIN CUT HERE

// END CUT HERE
#line 5 "ExploringNumbers.cpp"
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

bool isprime(int n)
{
    if(n==1)
        return false;
    if(n==2||n==3)
        return true;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int cal(int n)
{
    int ans=0;
    while(n)
    {
        int t=n%10;
        ans=ans+(t*t);
        n/=10;
    }
    return ans;
}
bool vis[1005];
class ExploringNumbers
{
        public:
        int numberOfSteps(int n)
        {
            int t=n;
            int len=0;
            while(1)
            {
                len++;
                if(isprime(n))
                    return len;
                if(t==len)
                    return -1;
                if(n<1000)
                    vis[n]=1;
                n=cal(n);
                if(vis[n])
                    return -1;
            }
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; verify_case(0, Arg1, numberOfSteps(Arg0)); }
	void test_case_1() { int Arg0 = 57; int Arg1 = 4; verify_case(1, Arg1, numberOfSteps(Arg0)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = -1; verify_case(2, Arg1, numberOfSteps(Arg0)); }
	void test_case_3() { int Arg0 = 6498501; int Arg1 = 2; verify_case(3, Arg1, numberOfSteps(Arg0)); }
	void test_case_4() { int Arg0 = 989113; int Arg1 = 6; verify_case(4, Arg1, numberOfSteps(Arg0)); }
	void test_case_5() { int Arg0 = 12366; int Arg1 = -1; verify_case(5, Arg1, numberOfSteps(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        ExploringNumbers ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
