// BEGIN CUT HERE

// END CUT HERE
#line 5 "DoubleWeights.cpp"
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
int d1[22];
int d2[22];
int dist1[22][22];
int dist2[22][22];
bool vis[22];
int n;
void dijkstra(int x)
{
    memset(vis,0,sizeof(vis));
    for(int i=0; i<n; i++)
    {
        d1[i]=1000;
        d2[i]=1000;
    }
    d1[x]=0;
    d2[x]=0;
    for(int k=0; k<n; k++)
    {
        int mindist=1e9;
        int chos=0;
        for(int i=0; i<n; i++)
        {
            if(vis[i]==0&&(d1[i]*d2[i]<mindist))
            {
                mindist=d1[i]*d2[i];
                chos=i;
            }
        }
        vis[chos]=1;
        for(int i=0; i<n; i++)
        {
            if(vis[i]==false&&d1[i]*d2[i]>(d1[chos]+dist1[chos][i])*(d2[chos]+dist2[chos][i]))
            {
                d1[i]=d1[chos]+dist1[chos][i];
                d2[i]=d2[chos]+dist2[chos][i];
            }
        }
    }
}
class DoubleWeights
{
        public:
        int minimalCost(vector <string> weight1, vector <string> weight2)
        {
                n=weight1.size();
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(weight1[i][j]=='.')
                            dist1[i][j]=1000;
                        else
                            dist1[i][j]=weight1[i][j]-'0';
                        if(weight2[i][j]=='.')
                            dist2[i][j]=1000;
                        else
                            dist2[i][j]=weight2[i][j]-'0';
                    }
                }
                dijkstra(0);
                if(d1[1]*d2[1]==1000000)
                    return -1;
                return d1[1]*d2[1];
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..14",
 "..94",
 "19..",
 "44.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..94",
 "..14",
 "91..",
 "44.."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 64; verify_case(0, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"..14",
 "..14",
 "11..",
 "44.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..94",
 "..94",
 "99..",
 "44.."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 36; verify_case(1, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"..",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..",
 ".."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".....9",
 "..9...",
 ".9.9..",
 "..9.9.",
 "...9.9",
 "9...9."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".....9",
 "..9...",
 ".9.9..",
 "..9.9.",
 "...9.9",
 "9...9."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2025; verify_case(3, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {".4...1",
 "4.1...",
 ".1.1..",
 "..1.1.",
 "...1.1",
 "1...1."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".4...1",
 "4.1...",
 ".1.1..",
 "..1.1.",
 "...1.1",
 "1...1."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16; verify_case(4, Arg2, minimalCost(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        DoubleWeights ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
