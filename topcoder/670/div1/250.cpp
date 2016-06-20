// BEGIN CUT HERE

// END CUT HERE
#line 5 "Bracket107.cpp"
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

bool check(string str)
{
    int res=0;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]=='(')
            res++;
        else
        {
            if(res==0)
                return false;
            res--;
        }
    }
    return true;
}
class Bracket107
{
public:
    int yetanother(string s)
    {
        int len=s.length();
        set<string>ss;
        for(int i=0; i<len; i++)
        {
            string tmp;
            tmp=s.substr(0,i)+s.substr(i+1,len-i-1);
            for(int j=0; j<len-1; j++)
            {
                string ins;
                ins=tmp.substr(0,j)+s[i]+tmp.substr(j,len-1-j);
                if(ins!=s)
                    ss.insert(ins);
            }
        }
        int ans=0;
        while(ss.size())
        {
            string str=*ss.begin();
            ss.erase(ss.begin());
            if(check(str))
                ans++;
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
        string Arg0 = "(())";
        int Arg1 = 1;
        verify_case(0, Arg1, yetanother(Arg0));
    }
    void test_case_1()
    {
        string Arg0 = "(())()";
        int Arg1 = 3;
        verify_case(1, Arg1, yetanother(Arg0));
    }
    void test_case_2()
    {
        string Arg0 = "()()()";
        int Arg1 = 3;
        verify_case(2, Arg1, yetanother(Arg0));
    }
    void test_case_3()
    {
        string Arg0 = "(((())))";
        int Arg1 = 5;
        verify_case(3, Arg1, yetanother(Arg0));
    }
    void test_case_4()
    {
        string Arg0 = "((())())";
        int Arg1 = 9;
        verify_case(4, Arg1, yetanother(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Bracket107 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
