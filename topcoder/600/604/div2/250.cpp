// BEGIN CUT HERE

// END CUT HERE
#line 5 "FoxAndWord.cpp"
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

bool check(string s1,string s2)
{
    int len=s1.length();
    for(int i=0; i<len; i++)
    {
        string tmp=s1.substr(i)+s1.substr(0,i);
        if(tmp==s2)
            return true;
    }
    return false;
}
class FoxAndWord
{
public:
    int howManyPairs(vector <string> words)
    {
        int n=words.size();
        int ans=0;
        for(int i=0; i<n; i++)for(int j=i+1; j<n; j++)
                if(check(words[i],words[j]))
                    ans++;
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
        string Arr0[] = {"tokyo", "kyoto"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 1;
        verify_case(0, Arg1, howManyPairs(Arg0));
    }
    void test_case_1()
    {
        string Arr0[] = {"aaaaa", "bbbbb"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 0;
        verify_case(1, Arg1, howManyPairs(Arg0));
    }
    void test_case_2()
    {
        string Arr0[] = {"ababab","bababa","aaabbb"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 1;
        verify_case(2, Arg1, howManyPairs(Arg0));
    }
    void test_case_3()
    {
        string Arr0[] = {"eel", "ele", "lee"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 3;
        verify_case(3, Arg1, howManyPairs(Arg0));
    }
    void test_case_4()
    {
        string Arr0[] = {"aaa", "aab", "aba", "abb", "baa", "bab", "bba", "bbb"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 6;
        verify_case(4, Arg1, howManyPairs(Arg0));
    }
    void test_case_5()
    {
        string Arr0[] = {"top","coder"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 0;
        verify_case(5, Arg1, howManyPairs(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FoxAndWord ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
