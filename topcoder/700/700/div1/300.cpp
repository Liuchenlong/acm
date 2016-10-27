// BEGIN CUT HERE

// END CUT HERE
#line 5 "FindingFriend.cpp"
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


class FindingFriend
{
public:
    int find(int roomSize, vector <int> leaders, int friendPlace)
    {
        sort(leaders.begin(),leaders.end());
        int cnt=0;
        int pre=0;
        for(int i=0; i<leaders.size(); i++)
        {
            if(friendPlace==leaders[i])return 1;
            if(friendPlace<leaders[i])
                return cnt;
            if(i==0)
            {
                pre+=roomSize-1;
                cnt++;
            }
            else
            {
                int res=leaders[i]-leaders[i-1]-1;
                if(res==pre)
                {
                    pre=roomSize-1;
                    cnt=1;
                }
                else
                {
                    pre-=res;
                    pre+=roomSize-1;
                    cnt++;
                }
            }
        }
        return cnt;
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
        int Arg0 = 2;
        int Arr1[] = {5,1,2};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 4;
        int Arg3 = 2;
        verify_case(0, Arg3, find(Arg0, Arg1, Arg2));
    }
    void test_case_1()
    {
        int Arg0 = 5;
        int Arr1[] = {1,2,3,4,5};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 4;
        int Arg3 = 1;
        verify_case(1, Arg3, find(Arg0, Arg1, Arg2));
    }
    void test_case_2()
    {
        int Arg0 = 6;
        int Arr1[] = {10,5,1,4,2,20};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 9;
        int Arg3 = 4;
        verify_case(2, Arg3, find(Arg0, Arg1, Arg2));
    }
    void test_case_3()
    {
        int Arg0 = 1000000000;
        int Arr1[] = {1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 700700700;
        int Arg3 = 1;
        verify_case(3, Arg3, find(Arg0, Arg1, Arg2));
    }
    void test_case_4()
    {
        int Arg0 = 2;
        int Arr1[] = {3,6,8,1,2};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 10;
        int Arg3 = 5;
        verify_case(4, Arg3, find(Arg0, Arg1, Arg2));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FindingFriend ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
