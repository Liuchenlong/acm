// BEGIN CUT HERE

// END CUT HERE
#line 5 "ReplacingDigit.cpp"
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

vector <int>vec[10];
int ten[]={1,10,100,1000,10000,100000,1000000,10000000};
class ReplacingDigit
{
public:
    int getMaximumStockWorth(vector <int> A, vector <int> D)
    {
        for(int i=0;i<8;i++)
            vec[i].clear();
        for(int i=0; i<A.size(); i++)
        {
            int pos=0;
            while(A[i])
            {
                vec[pos].push_back(A[i]%10);
                A[i]/=10;
                pos++;
            }
        }
        for(int i=0;i<8;i++)
            sort(vec[i].begin(),vec[i].end());
        for(int i=9;i>=1;i--)
        {
            if(D[i-1]==0)
                continue;
            for(int j=8;j>=0;j--)
            {
                if(D[i-1]==0)
                    break;
                for(int k=0;k<vec[j].size();k++)
                {
                    if(D[i-1]==0)
                        break;
                    if(vec[j][k]<i)
                    {
                        vec[j][k]=i;
                        D[i-1]--;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<vec[i].size();j++)
                ans=ans+ten[i]*vec[i][j];
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
        int Arr0[] = {100, 90};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {0, 0, 0, 0, 2, 1, 0, 0, 0};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 745;
        verify_case(0, Arg2, getMaximumStockWorth(Arg0, Arg1));
    }
    void test_case_1()
    {
        int Arr0[] = {9};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1, 1, 1, 1, 1, 1, 1, 1, 0};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 9;
        verify_case(1, Arg2, getMaximumStockWorth(Arg0, Arg1));
    }
    void test_case_2()
    {
        int Arr0[] = {123456};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 988777;
        verify_case(2, Arg2, getMaximumStockWorth(Arg0, Arg1));
    }
    void test_case_3()
    {
        int Arr0[] = {10, 970019, 1976, 10936, 68750, 756309, 37600, 559601, 6750, 76091, 640, 312, 312, 90, 8870};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {11, 2, 8, 10, 7, 6, 3, 1, 3};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 3297500;
        verify_case(3, Arg2, getMaximumStockWorth(Arg0, Arg1));
    }
    void test_case_4()
    {
        int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {111, 111, 111, 111, 111, 111, 111, 111, 111};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 198;
        verify_case(4, Arg2, getMaximumStockWorth(Arg0, Arg1));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ReplacingDigit ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
