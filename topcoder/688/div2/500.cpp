// BEGIN CUT HERE

// END CUT HERE
#line 5 "ParenthesesDiv2Medium.cpp"
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


class ParenthesesDiv2Medium
{
        public:
        vector <int> correct(string s)
        {
            int n=s.length();
            vector<int>ans;
            int tnum=0;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='(')
                    tnum++;
                else
                {
                    if(tnum)
                        tnum--;
                    else
                    {
                        tnum++;
                        ans.push_back(i);
                        s[i]='(';
                    }
                }
            }
            if(tnum)
            {
                int wnum=0;
                for(int i=n-1;i>=0;i--)
                {
                    if(s[i]==')')
                        wnum++;
                    else
                    {
                        if(wnum)
                            wnum--;
                        else
                        {
                            wnum++;
                            ans.push_back(i);
                        }
                    }
                }
            }
            sort(ans.begin(),ans.end());
            bool vis[55];
            memset(vis,0,sizeof(vis));
            for(int i=0;i<ans.size();i++)
                vis[ans[i]]^=1;
            vector<int>tans;
            for(int i=0;i<=50;i++)
                if(vis[i])
                tans.push_back(i);
            return tans;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = ")("; int Arr1[] = {0, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, correct(Arg0)); }
	void test_case_1() { string Arg0 = ")))))((((("; int Arr1[] = {0, 2, 4, 5, 7, 9 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, correct(Arg0)); }
	void test_case_2() { string Arg0 = "((()"; int Arr1[] = {1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, correct(Arg0)); }
	void test_case_3() { string Arg0 = ")))(()(())))))"; int Arr1[] = {0, 1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, correct(Arg0)); }
	void test_case_4() { string Arg0 = "()()()()()()()()()()()()()"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, correct(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        ParenthesesDiv2Medium ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
