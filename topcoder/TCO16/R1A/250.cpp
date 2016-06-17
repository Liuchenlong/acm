// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysTimeMachine.cpp"
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


class EllysTimeMachine
{
        public:
        string getTime(string time)
        {
                int tim1,tim2;
                tim1=(time[0]-'0')*10+time[1]-'0';
                tim2=(time[3]-'0')*10+time[4]-'0';
                tim2=tim2/5;
//                swap(tim1,tim2);
                tim1*=5;
                string ans=":::::";
                ans[0]='0'+tim2/10;
                ans[1]='0'+tim2%10;
                ans[3]='0'+tim1/10;
                ans[4]='0'+tim1%10;
                if(ans[0]=='0'&&ans[1]=='0')
                {
                    ans[0]='1';
                    ans[1]='2';
                }
                if(ans[3]=='6')
                    ans[3]='0';
//                ans=ans+(""+tim2/10+tim2%10)+":"+(""+tim1/10+tim1%10);
                return ans;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "11:20"; string Arg1 = "04:55"; verify_case(0, Arg1, getTime(Arg0)); }
	void test_case_1() { string Arg0 = "02:25"; string Arg1 = "05:10"; verify_case(1, Arg1, getTime(Arg0)); }
	void test_case_2() { string Arg0 = "06:30"; string Arg1 = "06:30"; verify_case(2, Arg1, getTime(Arg0)); }
	void test_case_3() { string Arg0 = "05:55"; string Arg1 = "11:25"; verify_case(3, Arg1, getTime(Arg0)); }
	void test_case_4() { string Arg0 = "03:45"; string Arg1 = "09:15"; verify_case(4, Arg1, getTime(Arg0)); }
	void test_case_5() { string Arg0 = "01:00"; string Arg1 = "12:05"; verify_case(5, Arg1, getTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        EllysTimeMachine ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
