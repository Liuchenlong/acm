// BEGIN CUT HERE

// END CUT HERE
#line 5 "CliqueParty.cpp"
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


class CliqueParty
{
        public:
        int maxsize(vector <int> a, int k)
        {
            vector <long long >b;
            long long K=k;
            for(int i=0;i<a.size();i++)
            {
                b.push_back(a[i]);
            }
            sort(b.begin(),b.end());
            int n=b.size();
            int ans=0;
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    long long dis=b[j]-b[i];
                    vector <long long>vec;
                    long long tmp=b[i];
                    for(int k=i-1;k>=0;k--)
                    {
                        if(tmp-b[k]>=dis)
                        {
                            vec.push_back(b[k]);
                            tmp=b[k];
                        }
                    }
                    tmp=b[j];
                    for(int k=j+1;k<n;k++)
                    {
                        if(b[k]-tmp>=dis)
                        {
                            vec.push_back(b[k]);
                            tmp=b[k];
                        }
                    }
                    vec.push_back(b[i]);
                    vec.push_back(b[j]);
                    sort(vec.begin(),vec.end());
                    for(int t=0;t<vec.size();t++)
                    {
                        if(vec[t]>b[i])
                            break;
                        int pos=upper_bound(vec.begin(),vec.end(),vec[t]+K*dis)-vec.begin()-1;
                        if(vec[pos]>=b[j])
                        {
                            ans=max(ans,pos-t+1);
                        }
                    }
                }
            }
            return ans;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, maxsize(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, maxsize(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4,10,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(2, Arg2, maxsize(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 4; verify_case(3, Arg2, maxsize(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {10,9,25,24,23,30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 4; verify_case(4, Arg2, maxsize(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        CliqueParty ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
