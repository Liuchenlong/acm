// BEGIN CUT HERE

// END CUT HERE
#line 5 "GroupSRMDiv2.cpp"
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

int num[505];
class GroupSRMDiv2
{
public:
    int FindGroups(vector <int> t)
    {
        memset(num,0,sizeof(num));
        int ans=0;
        for(int i=0; i<t.size(); i++)
            num[t[i]]++;
        for(int i=1; i<=500; i++)
        {
            if(num[i]%i!=0)
                return -1;
            ans+=num[i]/i;
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
        int Arr0[] = {1,1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 2;
        verify_case(0, Arg1, FindGroups(Arg0));
    }
    void test_case_1()
    {
        int Arr0[] = {1,2};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = -1;
        verify_case(1, Arg1, FindGroups(Arg0));
    }
    void test_case_2()
    {
        int Arr0[] = {2,2};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 1;
        verify_case(2, Arg1, FindGroups(Arg0));
    }
    void test_case_3()
    {
        int Arr0[] = {2,2,3,3,3};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 2;
        verify_case(3, Arg1, FindGroups(Arg0));
    }
    void test_case_4()
    {
        int Arr0[] = {3,3,2,2,2};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = -1;
        verify_case(4, Arg1, FindGroups(Arg0));
    }
    void test_case_5()
    {
        int Arr0[] = {2,3,2,3,2,3,2,1,1,2,2};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 6;
        verify_case(5, Arg1, FindGroups(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    GroupSRMDiv2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
