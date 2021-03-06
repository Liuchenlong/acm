// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysSocks.cpp"
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

bool vis[1005];
int n;
int num[1005];
bool check(int len,int p)
{
    int ans=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
    {
        if(vis[i])
            continue;
        for(int j=i+1;j<n;j++)
        {
            if(vis[j])
                continue;
            if(num[j]-num[i]<=len)
            {
                ans++;
                vis[j]=1;
                vis[i]=1;
                break;
            }
        }
    }
    if(ans>=p)
        return true;
    return false;
}
class EllysSocks
{
        public:
        int getDifference(vector <int> S, int P)
        {
            n=S.size();
                sort(S.begin(),S.end());
             for(int i=0;i<n;i++)
             {
                 num[i]=S[i];
             }
                int l=0,r=S[S.size()-1];
                while(l<r)
                {
                    int mid=(l+r)/2;
                    if(check(mid,P))
                        r=mid;
                    else
                        l=mid+1;
                }
                return r;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {42, 37, 84, 36, 41, 42}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; verify_case(0, Arg2, getDifference(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {42, 37, 84, 36, 41, 42}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 42; verify_case(1, Arg2, getDifference(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5, 2, 8, 8, 6, 7, 3, 7, 4, 2, 4, 5, 3, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 0; verify_case(2, Arg2, getDifference(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {17, 3, 13, 3, 2, 17, 11, 5, 5, 7, 11, 7, 13, 19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 4; verify_case(3, Arg2, getDifference(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {795755685, 581869303, 404620563, 708632712, 545404205, 133711906, 372047868, 949333986, 579004999, 323567404,
 418932836, 944672732, 196140741, 809094427, 946129058, 30574577, 182506778, 15198493, 150802600, 138749191,
 676943010, 177512688, 126303054, 81133258, 183966551, 471852627, 84672537, 867128744, 857788837, 275731772,
 609397213, 20544910, 811450930, 483031419, 361913171, 547204602, 892462744, 522136404, 173978710, 131752569,
 478582453, 867889991, 153380496, 551745921, 647984700, 910208077, 283496852, 368550363, 379821990, 712568903,
 40498239, 113911604, 103237637, 39073007, 684602223, 812852787, 479711181, 746745228, 735241235, 296707007,
 262522458, 870676136, 136721027, 359573809, 189375153, 547914047, 198304613, 640439653, 417177802, 25475624,
 758242872, 764919655, 310701088, 537655880, 361931892, 14685971, 213794688, 107063881, 147944789, 444803289,
 884392679, 540721924, 638781100, 902841101, 7097711, 219972874, 879609715, 156513984, 802611721, 755486970,
 103522060, 967048445, 913778155, 94092596, 519074050, 884870761, 248268555, 339840186, 53612697, 826647953}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 42; int Arg2 = 12866316; verify_case(4, Arg2, getDifference(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        EllysSocks ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
