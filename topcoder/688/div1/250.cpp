// BEGIN CUT HERE

// END CUT HERE
#line 5 "ParenthesesDiv1Easy.cpp"
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


class ParenthesesDiv1Easy
{
public:
    vector <int> correct(string s)
    {
        int n=s.length();
        if(s.length()%2==1)
        {
            vector<int>ans;
            ans.push_back(-1);
            return ans;
        }
        vector<int>L,R;
        int num=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
                num++;
            else
            {
                if(num)
                    num--;
                else
                    L.push_back(i);
            }
        }
        num=0;
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]==')')
                num++;
            else
            {
                if(num)
                    num--;
                else
                    R.push_back(i);
            }
        }
        vector<int>ans;
        if(L.size()==0&&R.size()==0)
            return ans;
        if(L.size()==R.size())
        {
            ans.push_back(L[0]);
            ans.push_back(L[L.size()-1]);
            ans.push_back(R[R.size()-1]);
            ans.push_back(R[0]);
            return ans;
        }
        if(L.size()>R.size())
        {
            int pos=(L.size()+R.size())/2;
            ans.push_back(L[0]);
            ans.push_back(L[pos-1]);
            if(R.size())
            {
                ans.push_back(R[R.size()-1]);
                ans.push_back(R[0]);
            }
            return ans;
        }
        if(L.size()<R.size())
        {
            int pos=(L.size()+R.size())/2;
            if(L.size())
            {
                ans.push_back(L[0]);
                ans.push_back(L[L.size()-1]);
            }
            ans.push_back(R[pos-1]);
            ans.push_back(R[0]);
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
        string Arg0 = ")(";
        int Arr1[] = {0, 0, 1, 1 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(0, Arg1, correct(Arg0));
    }
    void test_case_1()
    {
        string Arg0 = "))))))((((((";
        int Arr1[] = {0, 5, 6, 11 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(1, Arg1, correct(Arg0));
    }
    void test_case_2()
    {
        string Arg0 = "))()())()";
        int Arr1[] = {-1 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(2, Arg1, correct(Arg0));
    }
    void test_case_3()
    {
        string Arg0 = ")()(((";
        int Arr1[] = {0, 0, 3, 3, 5, 5 };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(3, Arg1, correct(Arg0));
    }
    void test_case_4()
    {
        string Arg0 = "()";
        int Arr1[] = { };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(4, Arg1, correct(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ParenthesesDiv1Easy ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
