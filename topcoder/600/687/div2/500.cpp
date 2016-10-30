// BEGIN CUT HERE

// END CUT HERE
#line 5 "Quacking.cpp"
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

bool vis[2505];
int get(char ch)
{
    if(ch=='q')
        return 0;
    if(ch=='u')
        return 1;
    if(ch=='a')
        return 2;
    if(ch=='c')
        return 3;
    if(ch=='k')
        return 4;
}
class Quacking
{
public:
    int quack(string s)
    {
        memset(vis,0,sizeof(vis));
        int ans=0;
        while(1)
        {
            int flag=0;
            for(int i=0; i<s.length(); i++)
                if(vis[i]==0)
                {
                    flag=1;
                    break;
                }
            if(flag==0)
                return ans;
            int pos=0;
            ans++;
            int flag2=0;
            for(int i=0;i<s.length();i++)
            {
                if(vis[i])
                    continue;
                if(get(s[i])==pos)
                {
                    flag2=1;
                    vis[i]=1;
                    pos=(pos+1)%5;
                }
            }
            if(pos!=0||flag2==0)
                return -1;
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
        string Arg0 = "quqacukqauackck";
        int Arg1 = 2;
        verify_case(0, Arg1, quack(Arg0));
    }
    void test_case_1()
    {
        string Arg0 = "kkkkk";
        int Arg1 = -1;
        verify_case(1, Arg1, quack(Arg0));
    }
    void test_case_2()
    {
        string Arg0 = "quackquackquackquackquackquackquackquackquackquack";
        int Arg1 = 1;
        verify_case(2, Arg1, quack(Arg0));
    }
    void test_case_3()
    {
        string Arg0 = "qqqqqqqqqquuuuuuuuuuaaaaaaaaaacccccccccckkkkkkkkkk";
        int Arg1 = 10;
        verify_case(3, Arg1, quack(Arg0));
    }
    void test_case_4()
    {
        string Arg0 = "quqaquuacakcqckkuaquckqauckack";
        int Arg1 = 3;
        verify_case(4, Arg1, quack(Arg0));
    }
    void test_case_5()
    {
        string Arg0 = "quackqauckquack";
        int Arg1 = -1;
        verify_case(5, Arg1, quack(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Quacking ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
