// BEGIN CUT HERE

// END CUT HERE
#line 5 "GerrymanderEasy.cpp"
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


class GerrymanderEasy
{
public:
    double getmax(vector <int> A, vector <int> B, int K)
    {
        double ans=0;
        int n=A.size();
        int suma[1005],sumb[1005];
        memset(suma,0,sizeof(suma));
        memset(sumb,0,sizeof(sumb));
        for(int i=1; i<=n; i++)
        {
            suma[i]=suma[i-1]+A[i-1];
            sumb[i]=sumb[i-1]+B[i-1];
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=i+K-1; j<=n; j++)
            {
                double val=1.0*(sumb[j]-sumb[i-1])/(suma[j]-suma[i-1]);
                ans=max(ans,val);
            }
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
    void verify_case(int Case, const double &Expected, const double &Received)
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
        int Arr0[] = {5,1,2,7};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {4,0,2,2};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 2;
        double Arg3 = 0.75;
        verify_case(0, Arg3, getmax(Arg0, Arg1, Arg2));
    }
    void test_case_1()
    {
        int Arr0[] = {12,34,56,78,90};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1,1,1,1,1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 1;
        double Arg3 = 0.08333333333333333;
        verify_case(1, Arg3, getmax(Arg0, Arg1, Arg2));
    }
    void test_case_2()
    {
        int Arr0[] = {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {3,1,4,1,5,9,2,6,5,3};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 5;
        double Arg3 = 5.4E-4;
        verify_case(2, Arg3, getmax(Arg0, Arg1, Arg2));
    }
    void test_case_3()
    {
        int Arr0[] = {123,4,46,88,22,34,564,87,56,311,886};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {0,0,0,0,0,0,0,0,0,0,0};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 1;
        double Arg3 = 0.0;
        verify_case(3, Arg3, getmax(Arg0, Arg1, Arg2));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    GerrymanderEasy ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
