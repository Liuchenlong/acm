// BEGIN CUT HERE

// END CUT HERE
#line 5 "RepeatString.cpp"
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

int dp[55][55];
int run(string s1,string s2)
{
    int n=s1.length(),m=s2.length();
    for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)dp[i][j]=100000;
    for(int i=0;i<=n;i++)dp[i][0]=i;
    for(int i=0;i<=m;i++)dp[0][i]=i;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    {
        dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(s1[i-1]!=s2[j-1]));
        dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
        dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
    }
    return dp[n][m];
}

class RepeatString
{
public:
    int minimalModify(string s)
    {
        int ans=1000000;
        for(int i=0;i<s.length();i++)
        {
            ans=min(ans,run(s.substr(0,i),s.substr(i)));
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
        string Arg0 = "aba";
        int Arg1 = 1;
        verify_case(0, Arg1, minimalModify(Arg0));
    }
    void test_case_1()
    {
        string Arg0 = "adam";
        int Arg1 = 1;
        verify_case(1, Arg1, minimalModify(Arg0));
    }
    void test_case_2()
    {
        string Arg0 = "x";
        int Arg1 = 1;
        verify_case(2, Arg1, minimalModify(Arg0));
    }
    void test_case_3()
    {
        string Arg0 = "aaabbbaaaccc";
        int Arg1 = 3;
        verify_case(3, Arg1, minimalModify(Arg0));
    }
    void test_case_4()
    {
        string Arg0 = "repeatstring";
        int Arg1 = 6;
        verify_case(4, Arg1, minimalModify(Arg0));
    }
    void test_case_5()
    {
        string Arg0 = "aaaaaaaaaaaaaaaaaaaa";
        int Arg1 = 0;
        verify_case(5, Arg1, minimalModify(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    RepeatString ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
