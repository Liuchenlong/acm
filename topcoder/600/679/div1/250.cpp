// BEGIN CUT HERE

// END CUT HERE
#line 5 "FiringEmployees.cpp"
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
int n;
int profit[3333];
class FiringEmployees
{
public:
    int fire(vector <int> manager, vector <int> salary, vector <int> productivity)
    {
        memset(profit,0,sizeof(profit));
        n=manager.size();
        for(int i=n; i>=1; i--)
        {
            profit[i]+=productivity[i-1]-salary[i-1];
            profit[manager[i-1]]+=profit[i];
        }
        for(int i=n; i>=1; i--)
        {
            if(profit[i]<0)
            {
                int det=profit[i];
                int now=i;
                while(1)
                {
                    if(now==0)
                        break;
                    now=manager[now-1];
                    profit[now]-=det;
                }
            }
        }
        return profit[0];
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
        int Arr0[] = {0,0,0};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1,2,3};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {3,2,1};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 2;
        verify_case(0, Arg3, fire(Arg0, Arg1, Arg2));
    }
    void test_case_1()
    {
        int Arr0[] = {0,1,2,3};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {4,3,2,1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {2,3,4,5};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 4;
        verify_case(1, Arg3, fire(Arg0, Arg1, Arg2));
    }
    void test_case_2()
    {
        int Arr0[] = {0,1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1,10};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {5,5};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 4;
        verify_case(2, Arg3, fire(Arg0, Arg1, Arg2));
    }
    void test_case_3()
    {
        int Arr0[] = {0,1,2,1,2,3,4,2,3};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {5,3,6,8,4,2,4,6,7};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {2,5,7,8,5,3,5,7,9};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 6;
        verify_case(3, Arg3, fire(Arg0, Arg1, Arg2));
    }
    void test_case_4()
    {
        int Arr0[] = {0,0,1,1,2,2};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1,1,1,2,2,2};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {2,2,2,1,1,1};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 3;
        verify_case(4, Arg3, fire(Arg0, Arg1, Arg2));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FiringEmployees ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
