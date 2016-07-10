// BEGIN CUT HERE

// END CUT HERE
#line 5 "TrySail.cpp"
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

bool dp[2][256][256][256];
class TrySail
{
public:
    int get(vector <int> strength)
    {
        dp[0][0][0][0]=true;
        int now=0;
        int next=1;
        for(int i=0; i<strength.size(); i++)
        {
            memset(dp[next],0,sizeof(dp[next]));
            int nw=strength[i];
            for(int j=0;j<256;j++)for(int k=0;k<256;k++)for(int w=0;w<256;w++)
            {
                if(dp[now][j][k][w])
                {
                    dp[next][j^nw][k][w]=true;
                    dp[next][j][k^nw][w]=true;
                    dp[next][j][k][w^nw]=true;
                }
            }
            swap(now,next);
        }
        int ans=0;
        for(int i=0;i<256;i++)for(int j=0;j<256;j++)for(int k=0;k<256;k++)
        {
            if(dp[now][i][j][k])
                ans=max(ans,i+j+k);
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
        int Arr0[] = {2,3,3};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 8;
        verify_case(0, Arg1, get(Arg0));
    }
    void test_case_1()
    {
        int Arr0[] = {7,3,5,2};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 17;
        verify_case(1, Arg1, get(Arg0));
    }
    void test_case_2()
    {
        int Arr0[] = {13,13,13,13,13,13,13,13};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 26;
        verify_case(2, Arg1, get(Arg0));
    }
    void test_case_3()
    {
        int Arr0[] = {114,51,4,191,9,81,0,89,3};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 470;
        verify_case(3, Arg1, get(Arg0));
    }
    void test_case_4()
    {
        int Arr0[] = {108,66,45,82,163,30,83,244,200,216,241,249,89,128,36,28,250,190,70,95,117,196,19,160,255,129,10,109,189,24,22,25,134,144,110,15,235,205,186,103,116,191,119,183,45,217,156,44,97,197};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 567;
        verify_case(4, Arg1, get(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TrySail ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
