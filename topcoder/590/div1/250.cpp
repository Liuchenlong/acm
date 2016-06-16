// BEGIN CUT HERE

// END CUT HERE
#line 5 "FoxAndChess.cpp"
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


class FoxAndChess
{
public:
    string ableToMove(string begin, string target)
    {
        int len=begin.length();
        int sum1=0,sum2=0;
        int pos=0;
        vector<int>vec;
        for(int i=0; i<len; i++)
        {
            if(begin[i]!='.')
                sum1++;
            if(target[i]!='.')
            {
                vec.push_back(i);
                sum2++;
            }
        }
        if(sum1!=sum2)
            return "Impossible";
        for(int i=0; i<len; i++)
        {
            if(begin[i]=='.')
                continue;
            if(begin[i]=='L')
            {
                if(target[vec[pos]]!='L')
                    return "Impossible";
                if(vec[pos]<=i)
                {
                    pos++;
                }
                else
                    return "Impossible";
            }
            else
            {
                if(target[vec[pos]]!='R')
                    return "Impossible";
                if(vec[pos]<i)
                    return "Impossible";
                for(int j=i+1;j<=vec[pos];j++)
                    if(begin[j]=='L')
                    return "Impossible";
                pos++;
            }
        }
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
        string Arg0 = "R...";
        string Arg1 = "..R.";
        string Arg2 = "Possible";
        verify_case(0, Arg2, ableToMove(Arg0, Arg1));
    }
    void test_case_1()
    {
        string Arg0 = "..R.";
        string Arg1 = "R...";
        string Arg2 = "Impossible";
        verify_case(1, Arg2, ableToMove(Arg0, Arg1));
    }
    void test_case_2()
    {
        string Arg0 = ".L.R.R.";
        string Arg1 = "L...R.R";
        string Arg2 = "Possible";
        verify_case(2, Arg2, ableToMove(Arg0, Arg1));
    }
    void test_case_3()
    {
        string Arg0 = ".L.R.";
        string Arg1 = ".R.L.";
        string Arg2 = "Impossible";
        verify_case(3, Arg2, ableToMove(Arg0, Arg1));
    }
    void test_case_4()
    {
        string Arg0 = "LRLLRLRLLRLLRLRLRL";
        string Arg1 = "LRLLRLRLLRLLRLRLRL";
        string Arg2 = "Possible";
        verify_case(4, Arg2, ableToMove(Arg0, Arg1));
    }
    void test_case_5()
    {
        string Arg0 = "L";
        string Arg1 = ".";
        string Arg2 = "Impossible";
        verify_case(5, Arg2, ableToMove(Arg0, Arg1));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FoxAndChess ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
