// BEGIN CUT HERE

// END CUT HERE
#line 5 "VampireTree.cpp"
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
class VampireTree
{
public:
    int maxDistance(vector <int> num)
    {
        int n=num.size();
        int sum=0;
        for(int i=0; i<n; i++)sum+=num[i];
        int ones=0;
        for(int i=0;i<n;i++)ones+=(num[i]==1);
        if(sum!=(n-1)*2)
            return -1;
        return n-ones+1;
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
        int Arr0[] = {1, 2, 2, 1, 3, 4, 1, 1, 1, 2, 2};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 7;
        verify_case(0, Arg1, maxDistance(Arg0));
    }
    void test_case_1()
    {
        int Arr0[] = {2, 2, 2};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = -1;
        verify_case(1, Arg1, maxDistance(Arg0));
    }
    void test_case_2()
    {
        int Arr0[] = {1, 1, 1, 1, 4};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 2;
        verify_case(2, Arg1, maxDistance(Arg0));
    }
    void test_case_3()
    {
        int Arr0[] = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = -1;
        verify_case(3, Arg1, maxDistance(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    VampireTree ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
