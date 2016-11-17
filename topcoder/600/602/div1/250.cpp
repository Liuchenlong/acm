// BEGIN CUT HERE

// END CUT HERE
#line 5 "TypoCoderDiv1.cpp"
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

int dp[55][2300];
class TypoCoderDiv1
{
public:
    int getmax(vector <int> D, int X)
    {
        int n=D.size();
        memset(dp,-1,sizeof(dp));
        dp[0][X]=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<2200; j++)
            {
                if(dp[i][j]==-1)continue;
                dp[i+1][max(0,j-D[i])]=max(dp[i+1][max(0,j-D[i])],dp[i][j]);
                if(j+D[i]<2200)
                    dp[i+1][j+D[i]]=max(dp[i+1][j+D[i]],dp[i][j]);
                else
                {
                    if(i==n-1)
                        dp[i+1][2200]=max(dp[i+1][2200],dp[i][j]+1);
                    else if(j+D[i]-D[i+1]<2200)
                        dp[i+2][max(0,j+D[i]-D[i+1])]=max(dp[i+2][max(0,j+D[i]-D[i+1])],dp[i][j]+2);
                }
            }
        }
        int ans=0;
        for(int i=0; i<=2200; i++)ans=max(ans,dp[n][i]);
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
        int Arr0[] = {100,200,100,1,1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 2000;
        int Arg2 = 3;
        verify_case(0, Arg2, getmax(Arg0, Arg1));
    }
    void test_case_1()
    {
        int Arr0[] = {0,0,0,0,0};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 2199;
        int Arg2 = 0;
        verify_case(1, Arg2, getmax(Arg0, Arg1));
    }
    void test_case_2()
    {
        int Arr0[] = {90000,80000,70000,60000,50000,40000,30000,20000,10000};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 0;
        int Arg2 = 1;
        verify_case(2, Arg2, getmax(Arg0, Arg1));
    }
    void test_case_3()
    {
        int Arr0[] = {1000000000,1000000000,10000,100000,2202,1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 1000;
        int Arg2 = 4;
        verify_case(3, Arg2, getmax(Arg0, Arg1));
    }
    void test_case_4()
    {
        int Arr0[] = {2048,1024,5012,256,128,64,32,16,8,4,2,1,0};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 2199;
        int Arg2 = 0;
        verify_case(4, Arg2, getmax(Arg0, Arg1));
    }
    void test_case_5()
    {
        int Arr0[] = {61,666,512,229,618,419,757,217,458,883,23,932,547,679,565,767,513,798,870,31,379,294,929,892,173,127,796,353,913,115,802,803,948,592,959,127,501,319,140,694,851,189,924,590,790,3,669,541,342,272};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 1223;
        int Arg2 = 29;
        verify_case(5, Arg2, getmax(Arg0, Arg1));
    }
    void test_case_6()
    {
        int Arr0[] = {34,64,43,14,58,30,2,16,90,58,35,55,46,24,14,73,96,13,9,42,64,36,89,42,42,64,52,68,53,76,52,54,23,88,32,52,28,96,70,32,26,3,23,78,47,23,54,30,86,32};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 1328;
        int Arg2 = 20;
        verify_case(6, Arg2, getmax(Arg0, Arg1));
    }
// END CUT HERE
};
// BEGIN CUT HERE
int main()
{
    TypoCoderDiv1 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
