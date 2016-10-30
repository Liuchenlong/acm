// BEGIN CUT HERE

// END CUT HERE
#line 5 "AlmostFibonacciKnapsack.cpp"
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

vector<long long>vec;
map<long long,int>mp;
int siz;
vector<int>tvec;
bool cal(long long x)
{
    if(x==0)
        return true;
    if(x<0)
        return false;
    int pos=upper_bound(vec.begin(),vec.end(),x)-vec.begin()-1;
    if(vec[pos]==x)
    {
        tvec.push_back(mp[vec[pos]]);
        return true;
    }
    if(cal(x-vec[pos]))
    {
        tvec.push_back(mp[vec[pos]]);
        return true;
    }
    else if(pos>=1&&cal(x-vec[pos-1]))
    {
        tvec.push_back(mp[vec[pos-1]]);
        return true;
    }
    return false;
}
class AlmostFibonacciKnapsack
{
public:
    vector <int> getIndices(long long x)
    {
        tvec.clear();
        vec.clear();
        vec.push_back(2);
        vec.push_back(3);
        mp[2]=1;
        mp[3]=2;
        int n=2;
        while(1)
        {
            long long t=vec[n-2]+vec[n-1]-1LL;
            mp[t]=n+1;
            if(t>x)
                break;
            vec.push_back(t);
            n++;
        }
        siz=vec.size();
//        for(int i=0; i<n; i++)
//            printf("%I64d ",vec[i]);
//        printf("\n");
        if(cal(x))
        {
//            printf("!\n");
            return tvec;
        }
        else
        {
            vector<int>ans;
            ans.push_back(-1);
            return ans;
        }

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
        long long Arg0 = 148LL;
        int Arr1[] = {6, 10, 8, 5 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(0, Arg1, getIndices(Arg0));
    }
    void test_case_1()
    {
        long long Arg0 = 2LL;
        int Arr1[] = {1 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(1, Arg1, getIndices(Arg0));
    }
    void test_case_2()
    {
        long long Arg0 = 13LL;
        int Arr1[] = {2, 3, 4 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(2, Arg1, getIndices(Arg0));
    }
    void test_case_3()
    {
        long long Arg0 = 3LL;
        int Arr1[] = {2 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(3, Arg1, getIndices(Arg0));
    }
    void test_case_4()
    {
        long long Arg0 = 86267769395LL;
        int Arr1[] = {3, 14, 15, 9, 26, 53, 5, 8 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(4, Arg1, getIndices(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    AlmostFibonacciKnapsack ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
