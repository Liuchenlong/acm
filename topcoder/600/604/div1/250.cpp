// BEGIN CUT HERE

// END CUT HERE
#line 5 "PowerOfThree.cpp"
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

long long three[25];
int cal(long long x)
{
    int ans=0;
    for(int i=24;i>=0;i--)
    {
        if(abs(x-three[i])<abs(x))
        {
            x-=three[i];
            ans|=(1<<i);
        }
        else if(abs(x+three[i])<abs(x))
        {
            x+=three[i];
            ans|=(1<<i);
        }
    }
    if(x!=0)
        return -1;
    return ans;
}
class PowerOfThree
{
public:
    string ableToGet(int x, int y)
    {
        three[0]=1;
        for(int i=1; i<24; i++)
            three[i]=three[i-1]*3;
        int s1=cal(x);
        int s2=cal(y);
        if(s1==-1||s2==-1||(s1&s2)!=0)
            return "Impossible";
        int ans=s1|s2;
        ans++;
        while(ans%2==0)ans/=2;
        if(ans!=1)
            return "Impossible";
        return "Possible";
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
        if ((Case == -1) || (Case == 6)) test_case_6();
        if ((Case == -1) || (Case == 7)) test_case_7();
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
    void verify_case(int Case, const string &Expected, const string &Received)
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
        int Arg0 = 1;
        int Arg1 = 3;
        string Arg2 = "Possible";
        verify_case(0, Arg2, ableToGet(Arg0, Arg1));
    }
    void test_case_1()
    {
        int Arg0 = 0;
        int Arg1 = 2;
        string Arg2 = "Possible";
        verify_case(1, Arg2, ableToGet(Arg0, Arg1));
    }
    void test_case_2()
    {
        int Arg0 = 1;
        int Arg1 = 9;
        string Arg2 = "Impossible";
        verify_case(2, Arg2, ableToGet(Arg0, Arg1));
    }
    void test_case_3()
    {
        int Arg0 = 3;
        int Arg1 = 0;
        string Arg2 = "Impossible";
        verify_case(3, Arg2, ableToGet(Arg0, Arg1));
    }
    void test_case_4()
    {
        int Arg0 = 1;
        int Arg1 = 1;
        string Arg2 = "Impossible";
        verify_case(4, Arg2, ableToGet(Arg0, Arg1));
    }
    void test_case_5()
    {
        int Arg0 = -6890;
        int Arg1 = 18252;
        string Arg2 = "Possible";
        verify_case(5, Arg2, ableToGet(Arg0, Arg1));
    }
    void test_case_6()
    {
        int Arg0 = 1000000000;
        int Arg1 = -1000000000;
        string Arg2 = "Impossible";
        verify_case(6, Arg2, ableToGet(Arg0, Arg1));
    }
    void test_case_7()
    {
        int Arg0 = 0;
        int Arg1 = 0;
        string Arg2 = "Possible";
        verify_case(7, Arg2, ableToGet(Arg0, Arg1));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PowerOfThree ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
