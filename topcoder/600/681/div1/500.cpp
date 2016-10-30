// BEGIN CUT HERE

// END CUT HERE
#line 5 "LimitedMemorySeries2.cpp"
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
const long long m=1LL<<50;
const int mod=1e9+7;
long long getnext(long long x,long long a,long long b)
{
    return ((x^a)+b)&(m-1);
}
long long getpre(long long x,long long a,long long b)
{
    return ((x+m-b)^a)&(m-1);
}
class LimitedMemorySeries2
{
public:
    int getSum(int n, long long x0, long long a, long long b)
    {
        int ans=0;
        long long now=x0;
        for(int i=0; i<n; i++)
        {
            long long pre=now,nxt=now;
            int pl=i,pr=i;
            while(1)
            {
                pre=getpre(pre,a,b);
                nxt=getnext(nxt,a,b);
                pl--;
                pr++;
                if(pl<0||pr>=n||pre>=now||nxt>=now)
                {
                    ans=ans+(i-pl-1);
                    break;
                }
            }
            now=getnext(now,a,b);
            ans=ans%mod;
        }
        return ans;
    }

// BEGIN CUT HERE
public:
    void run_test(int Case)
    {
        if ((Case == -1) || (Case == 0)) test_case_0();
        if ((Case == -1) || (Case == 1)) test_case_1();
        if ((Case == -1) || (Case == 2)) test_case_2();
        if ((Case == -1) || (Case == 3)) test_case_3();
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
        int Arg0 = 6;
        long long Arg1 = 2LL;
        long long Arg2 = 23LL;
        long long Arg3 = 1LL;
        int Arg4 = 2;
        verify_case(0, Arg4, getSum(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_1()
    {
        int Arg0 = 100;
        long long Arg1 = 0LL;
        long long Arg2 = 0LL;
        long long Arg3 = 1LL;
        int Arg4 = 0;
        verify_case(1, Arg4, getSum(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_2()
    {
        int Arg0 = 234234;
        long long Arg1 = 1125899906842623LL;
        long long Arg2 = 123456789123456LL;
        long long Arg3 = 987654321549687LL;
        int Arg4 = 1144970;
        verify_case(2, Arg4, getSum(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_3()
    {
        int Arg0 = 10000000;
        long long Arg1 = 12345678912345LL;
        long long Arg2 = 98765094309812LL;
        long long Arg3 = 34893049812392LL;
        int Arg4 = 65420804;
        verify_case(3, Arg4, getSum(Arg0, Arg1, Arg2, Arg3));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    LimitedMemorySeries2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
