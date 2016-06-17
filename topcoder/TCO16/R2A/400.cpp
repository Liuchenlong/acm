// BEGIN CUT HERE

// END CUT HERE
#line 5 "LCMGCD.cpp"
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

int num[3][3];
int two,three;
bool check()
{
    if(num[0][1]+num[1][1]+num[2][1]==0)
        return false;
    if(num[1][0]+num[1][1]+num[1][2]==0)
        return false;
    if(num[0][1]>0&&num[1][0]>0)
        return true;
    if(num[1][2]>0&&num[2][1]>0)
        return true;
    if(num[0][1]==0&&num[1][0]==0&&num[1][2]==0&&num[2][1]==0)
    {
        if(num[1][1]>0)
        {
            if(num[0][0]>0||num[2][2]>0)
                return true;
            else if(num[0][2]==0&&num[2][0]==0)
                return true;
            else if(num[0][2]>0&&num[2][0]>0)
                return true;
            else
            {
                if(num[1][1]==1)
                    return false;
                return true;
            }
        }
        else
            return false;
    }
    else
    {
        int tt=0;
        if(num[0][1])tt++;
        if(num[1][0])tt++;
        if(num[1][2])tt++;
        if(num[2][1])tt++;
        if(tt>=3)return true;
        else if(tt==2)
        {
            if(num[0][1]>0&&num[1][0]>0)
                return true;
            if(num[0][1]>0&&num[1][2]>0)
            {
                if(num[1][1]>0||num[2][0]>0)
                    return true;
                return false;
            }
            if(num[0][1]>0&&num[2][1]>0)
            {
                if(num[1][1]>0)
                    return true;
                return false;
            }
            if(num[1][0]>0&&num[1][2]>0)
            {
                if(num[1][1]>0)
                    return true;
                return false;
            }
            if(num[1][0]>0&&num[2][1]>0)
            {
                if(num[0][2]>0||num[1][1]>0)
                    return true;
                return false;
            }
            if(num[1][2]>0&&num[2][1]>0)
                return true;
        }
        else if(tt==1)
        {
            if(num[1][1]>0)
                return true;
            else
                return false;
        }
    }
    return false;
}
class LCMGCD
{
        public:
        string isPossible(vector <int> x, int t)
        {
            memset(num,0,sizeof(num));
            two=0;
            three=0;
            while(t%2==0)
            {
                two++;
                t/=2;
            }
            while(t%3==0)
            {
                three++;
                t/=3;
            }
            for(int i=0;i<x.size();i++)
            {
                int to=0,te=0;
                while(x[i]%2==0){to++;x[i]/=2;}
                while(x[i]%3==0){te++;x[i]/=3;}
                if(to<two)
                {
                    if(te<three)
                        num[0][0]++;
                    else if(te==three)num[0][1]++;
                    else num[0][2]++;
                }
                else if(to==two)
                {
                    if(te<three)
                        num[1][0]++;
                    else if(te==three)num[1][1]++;
                    else num[1][2]++;
                }
                else
                {
                    if(te<three)
                        num[2][0]++;
                    else if(te==three)num[2][1]++;
                    else num[2][2]++;
                }
            }
            if(check())
                return "Possible";
            else
                return "Impossible";
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = "Possible"; verify_case(0, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = "Impossible"; verify_case(1, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {6,12,24,18,36,72,54,108,216}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; string Arg2 = "Possible"; verify_case(2, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {6,27,81,729}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = "Impossible"; verify_case(3, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arg2 = "Possible"; verify_case(4, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {72,16,16,16,16,16,27,27,27,27,27,27,27,27,27}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 72; string Arg2 = "Possible"; verify_case(5, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {100663296, 544195584, 229582512, 59049}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60466176; string Arg2 = "Possible"; verify_case(6, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_7() { int Arr0[] = {2,4,8,16,32,64}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 256; string Arg2 = "Impossible"; verify_case(7, Arg2, isPossible(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        LCMGCD ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
