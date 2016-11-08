// BEGIN CUT HERE

// END CUT HERE
#line 5 "OthersXor.cpp"
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

class OthersXor
{
public:
    long long minSum(vector <int> x)
    {
        long long ans=0;
        int n=x.size();
        for(int i=0; i<30; i++)
        {
            int zero=0;
            int one=0;
            int unknown=0;
            for(int j=0; j<n; j++)
            {
                if(x[j]==-1)unknown++;
                else if(x[j]&(1<<i))one++;
                else zero++;
            }
            int best=-1;
            for(int j=0; j<=unknown; j++)
            {
                int zeros=zero+j;
                int ones=n-zeros;
                if(n%2==1&&ones%2==1)continue;
                for(int k=0; k<=1; k++)
                {
                    if(n%2==0&&ones%2!=k)continue;
                    int ans=(k==1?zeros:ones);
                    if(best==-1)best=ans;
                    else best=min(best,ans);
                }
            }
            if(best==-1)return -1;
            ans+=(1LL<<i)*best;
        }
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
        if ((Case == -1) || (Case == 6)) test_case_6();
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
    void verify_case(int Case, const long long &Expected, const long long &Received)
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
        int Arr0[] = {1,-1,3};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        long long Arg1 = 3LL;
        verify_case(0, Arg1, minSum(Arg0));
    }
    void test_case_1()
    {
        int Arr0[] = {0,0,1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        long long Arg1 = -1LL;
        verify_case(1, Arg1, minSum(Arg0));
    }
    void test_case_2()
    {
        int Arr0[] = {70,100};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        long long Arg1 = 170LL;
        verify_case(2, Arg1, minSum(Arg0));
    }
    void test_case_3()
    {
        int Arr0[] = {-1,0,-1,100,36};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        long long Arg1 = 164LL;
        verify_case(3, Arg1, minSum(Arg0));
    }
    void test_case_4()
    {
        int Arr0[] = {0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,
                      0,536870912,0,536870912,0,536870912,0,536870912,0,536870912,
                      1073741823,1073741823,1073741823,123456789,987654321,804289383
                     };
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        long long Arg1 = 11992352010LL;
        verify_case(4, Arg1, minSum(Arg0));
    }
    void test_case_5()
    {
        int Arr0[] = {1287325,424244444,92759185,812358213,1000000000,825833522,749092703};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        long long Arg1 = -1LL;
        verify_case(5, Arg1, minSum(Arg0));
    }
    void test_case_6()
    {
        int Arr0[] = {-1,-1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        long long Arg1 = 0LL;
        verify_case(6, Arg1, minSum(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    OthersXor ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
