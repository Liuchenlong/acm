// BEGIN CUT HERE

// END CUT HERE
#line 5 "FourStrings.cpp"
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

int vis[4];
string str[4];
int ans;
void dfs(int pos,string ss)
{
    if(pos==4)
    {
        ans=MIN(ans,ss.length());
        return ;
    }
    for(int i=0; i<4; i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            string tt=ss;
            for(int j=0; j<=tt.length(); j++)
            {
                int flag=1;
                int k;
                for(k=0; k<str[i].length()&&j+k<tt.length(); k++)
                {
                    if(str[i][k]!=tt[j+k])
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                {
                    for(; k<str[i].length(); k++)
                        tt=tt+str[i][k];
                    break;
                }
            }
            dfs(pos+1,tt);
            vis[i]=0;
        }
    }
}
class FourStrings
{
public:
    int shortestLength(string a, string b, string c, string d)
    {
        str[0]=a;
        str[1]=b;
        str[2]=c;
        str[3]=d;
        ans=9999;
        dfs(0,"");
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
        string Arg0 = "abc";
        string Arg1 = "ab";
        string Arg2 = "bc";
        string Arg3 = "b";
        int Arg4 = 3;
        verify_case(0, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_1()
    {
        string Arg0 = "a";
        string Arg1 = "bc";
        string Arg2 = "def";
        string Arg3 = "ghij";
        int Arg4 = 10;
        verify_case(1, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_2()
    {
        string Arg0 = "top";
        string Arg1 = "coder";
        string Arg2 = "opco";
        string Arg3 = "pcode";
        int Arg4 = 8;
        verify_case(2, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_3()
    {
        string Arg0 = "thereare";
        string Arg1 = "arelots";
        string Arg2 = "lotsof";
        string Arg3 = "ofcases";
        int Arg4 = 19;
        verify_case(3, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_4()
    {
        string Arg0 = "aba";
        string Arg1 = "b";
        string Arg2 = "b";
        string Arg3 = "b";
        int Arg4 = 3;
        verify_case(4, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_5()
    {
        string Arg0 = "x";
        string Arg1 = "x";
        string Arg2 = "x";
        string Arg3 = "x";
        int Arg4 = 1;
        verify_case(5, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FourStrings ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
