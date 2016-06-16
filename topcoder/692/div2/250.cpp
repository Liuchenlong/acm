// BEGIN CUT HERE

// END CUT HERE
#line 5 "PriorityQueue.cpp"
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


class PriorityQueue
{
public:
    int findAnnoyance(string S, vector <int> a)
    {
        int sum[101];
        sum[0]=0;
        for(int i=1; i<a.size(); i++)
        {
            sum[i]=sum[i-1]+a[i-1];
        }
        int ans=0;
        for(int i=0; i<S.length(); i++)
            if(S[i]=='b')
                ans+=sum[i];
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
        string Arg0 = "bbbbb";
        int Arr1[] = {1,1,1,1,1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 10;
        verify_case(0, Arg2, findAnnoyance(Arg0, Arg1));
    }
    void test_case_1()
    {
        string Arg0 = "bee";
        int Arr1[] = {50,40,30};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 0;
        verify_case(1, Arg2, findAnnoyance(Arg0, Arg1));
    }
    void test_case_2()
    {
        string Arg0 = "ebbe";
        int Arr1[] = {5,2,11,1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 12;
        verify_case(2, Arg2, findAnnoyance(Arg0, Arg1));
    }
    void test_case_3()
    {
        string Arg0 = "bbeebeebeeeebbb";
        int Arr1[] = {58,517,301,524,79,375,641,152,810,778,222,342,911,313,336};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 20485;
        verify_case(3, Arg2, findAnnoyance(Arg0, Arg1));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PriorityQueue ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
