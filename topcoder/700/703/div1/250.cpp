// BEGIN CUT HERE

// END CUT HERE
#line 5 "DAGConstruction.cpp"
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
class DAGConstruction
{
public:
    vector <int> construct(vector <int> x)
    {
        vector<int>ok;
        vector<int>wa;
        wa.push_back(-1);
        int n=x.size();
        pair<int,int>pr[55];
        for(int i=0;i<n;i++)pr[i]=make_pair(x[i],i);
        sort(pr,pr+n);
        for(int i=0;i<n;i++)
        {
            if(pr[i].first-1>i)return wa;
            for(int j=0;j<pr[i].first-1;j++)
            {
                ok.push_back(pr[i].second);
                ok.push_back(pr[j].second);
            }
        }
        return ok;
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
    void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received)
    {
        cerr << "Test Case #" << Case << "...";
        if (Expected == Received) cerr << "PASSED" << endl;
        else
        {
            cerr << "FAILED" << endl;
            cerr << "\tExpected: " << print_array(Expected) << endl;
            cerr << "\tReceived: " << print_array(Received) << endl;
        }
    }
    void test_case_0()
    {
        int Arr0[] = {2, 1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {0, 1 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(0, Arg1, construct(Arg0));
    }
    void test_case_1()
    {
        int Arr0[] = {1, 1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = { };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(1, Arg1, construct(Arg0));
    }
    void test_case_2()
    {
        int Arr0[] = {1, 3, 1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1, 0, 1, 2 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(2, Arg1, construct(Arg0));
    }
    void test_case_3()
    {
        int Arr0[] = {5,5,5,5,5};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {-1 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(3, Arg1, construct(Arg0));
    }
    void test_case_4()
    {
        int Arr0[] = {4,2,2,1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {0, 1, 0, 2, 1, 3, 2, 3 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(4, Arg1, construct(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    DAGConstruction ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
