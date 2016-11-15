// BEGIN CUT HERE

// END CUT HERE
#line 5 "WinterAndPresents.cpp"
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


class WinterAndPresents
{
public:
    long long getNumber(vector <int> apple, vector <int> orange)
    {
        int maxx=2000000;
        int n=apple.size();
        for(int i=0;i<n;i++)
            maxx=min(maxx,apple[i]+orange[i]);
        long long sum=0;
        for(int i=1;i<=maxx;i++)
        {
            int maxa=0,maxo=0;
            for(int j=0;j<n;j++)
                maxa+=min(i,apple[j]);
            for(int j=0;j<n;j++)
                maxo+=min(i,orange[j]);
            sum+=(1LL*maxa-(1LL*n*i-maxo)+1);
        }
        return sum;
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
    void verify_case(int Case, const long long &Expected, const long long &Received)
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
        int Arr0[] = {1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        long long Arg2 = 3LL;
        verify_case(0, Arg2, getNumber(Arg0, Arg1));
    }
    void test_case_1()
    {
        int Arr0[] = {1, 2, 0, 3};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {4, 5, 0, 6};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        long long Arg2 = 0LL;
        verify_case(1, Arg2, getNumber(Arg0, Arg1));
    }
    void test_case_2()
    {
        int Arr0[] = {2, 2, 2};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {2, 2, 2};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        long long Arg2 = 16LL;
        verify_case(2, Arg2, getNumber(Arg0, Arg1));
    }
    void test_case_3()
    {
        int Arr0[] = {7, 4, 5};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1, 10, 2};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        long long Arg2 = 46LL;
        verify_case(3, Arg2, getNumber(Arg0, Arg1));
    }
    void test_case_4()
    {
        int Arr0[] = {1000000};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1000000};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        long long Arg2 = 1000002000000LL;
        verify_case(4, Arg2, getNumber(Arg0, Arg1));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    WinterAndPresents ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
