// BEGIN CUT HERE

// END CUT HERE
#line 5 "ANewHope.cpp"
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
int scd[3333];
struct Int
{
    int x;
    Int() {}
    Int(int X)
    {
        x=X;
    }
    bool operator < (const Int &y)const
    {
        return scd[x]<scd[y.x];
    }
};
class ANewHope
{
public:
    int count(vector <int> firstWeek, vector <int> lastWeek, int D)
    {
        int n=firstWeek.size();
        for(int i=0; i<firstWeek.size(); i++)
        {
            scd[lastWeek[i]]=i;
        }
        set<Int>s;
        int tim=0;
        int dp[2][2505];
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++)
            dp[0][i]=firstWeek[i];
        int now=0,next=1;
        int ans=1;
        while(1)
        {
            for(int i=0; i+D<n; i++)
                s.insert(Int(dp[now][i]));
            int flag=1;
            for(int i=0; i<n; i++)
                if(dp[now][i]!=lastWeek[i])
                {
                    flag=0;
                    break;
                }
            if(flag)
                break;
            for(int i=0; i<n; i++)
            {
                if(i<D)
                    s.insert(Int(dp[now][n-D+i]));
                dp[next][i]=(*s.begin()).x;
                s.erase(s.begin());
            }
            ans++;
            swap(now,next);
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
        int Arr0[] = {1,2,3,4};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {4,3,2,1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 3;
        int Arg3 = 4;
        verify_case(0, Arg3, count(Arg0, Arg1, Arg2));
    }
    void test_case_1()
    {
        int Arr0[] = {8,5,4,1,7,6,3,2};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {2,4,6,8,1,3,5,7};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 3;
        int Arg3 = 3;
        verify_case(1, Arg3, count(Arg0, Arg1, Arg2));
    }
    void test_case_2()
    {
        int Arr0[] = {44, 36, 71, 33, 13, 59, 32, 11, 54, 19, 74, 69, 16, 50, 24, 49, 41, 73, 7, 43, 58, 1, 46, 57, 62, 12, 3, 6, 55, 40, 65, 2, 23, 67, 29, 15, 4, 39, 17, 52, 18, 21, 10, 5, 31, 60, 56, 20, 64, 38, 47, 61, 42, 68, 72, 26, 34, 9, 25, 45, 30, 22, 53, 28, 27, 37, 63, 8, 48, 51, 35, 70, 14, 66};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {40, 26, 38, 53, 22, 3, 18, 46, 20, 65, 74, 72, 58, 42, 34, 57, 39, 61, 24, 45, 17, 44, 71, 41, 29, 23, 33, 73, 30, 10, 9, 14, 12, 60, 31, 27, 32, 6, 13, 70, 1, 4, 28, 19, 25, 59, 35, 69, 5, 47, 21, 15, 67, 8, 55, 62, 16, 7, 51, 43, 50, 37, 66, 54, 48, 2, 11, 64, 56, 36, 63, 68, 52, 49};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 71;
        int Arg3 = 21;
        verify_case(2, Arg3, count(Arg0, Arg1, Arg2));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ANewHope ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
