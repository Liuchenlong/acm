// BEGIN CUT HERE

// END CUT HERE
#line 5 "FoxConnection2.cpp"
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

vector<int>to[55];
vector<int>son[55];
int father[55];
void dfs(int rt)
{
    for(int i=0;i<to[rt].size();i++)
    {
        int nxt=to[rt][i];
        if(father[rt]!=nxt)
        {
            father[nxt]=rt;
            son[rt].push_back(nxt);
            dfs(nxt);
        }
    }
}
int n;
long long mod=1e9+7;
long long dp[55][55];
void getdp(int rt)
{
    memset(dp[rt],0,sizeof(dp[rt]));
    dp[rt][0]=1;
    dp[rt][1]=1;
    for(int i=0;i<son[rt].size();i++)
    {
        int nxt=son[rt][i];
        getdp(nxt);
        for(int j=n;j>=2;j--)
        {
            for(int k=1;k<j;k++)
                dp[rt][j]+=dp[rt][k]*dp[nxt][j-k]%mod;
            dp[rt][j]%=mod;
        }
    }
}
class FoxConnection2
{
public:
    int ways(vector <int> A, vector <int> B, int k)
    {
        memset(father,-1,sizeof(father));
        for(int i=0;i<50;i++)to[i].clear();
        for(int i=0;i<50;i++)son[i].clear();
        for(int i=0;i<A.size();i++)
        {
            to[A[i]-1].push_back(B[i]-1);
            to[B[i]-1].push_back(A[i]-1);
        }
        dfs(0);
        n=A.size()+1;
        getdp(0);
        long long ans=0;
        for(int i=0;i<n;i++)ans+=dp[i][k];
        return ans%mod;
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
        int Arr0[] = {1,2,3};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {2,3,4};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 2;
        int Arg3 = 3;
        verify_case(0, Arg3, ways(Arg0, Arg1, Arg2));
    }
    void test_case_1()
    {
        int Arr0[] = {1,1,1,1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {2,3,4,5};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 3;
        int Arg3 = 6;
        verify_case(1, Arg3, ways(Arg0, Arg1, Arg2));
    }
    void test_case_2()
    {
        int Arr0[] = {1,2,3,4};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {2,3,4,5};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 3;
        int Arg3 = 3;
        verify_case(2, Arg3, ways(Arg0, Arg1, Arg2));
    }
    void test_case_3()
    {
        int Arr0[] = {1,2,2,4,4};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {2,3,4,5,6};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 3;
        int Arg3 = 6;
        verify_case(3, Arg3, ways(Arg0, Arg1, Arg2));
    }
    void test_case_4()
    {
        int Arr0[] = {1,2,2,4,4};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {2,3,4,5,6};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 5;
        int Arg3 = 4;
        verify_case(4, Arg3, ways(Arg0, Arg1, Arg2));
    }
    void test_case_5()
    {
        int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 20;
        int Arg3 = 923263934;
        verify_case(5, Arg3, ways(Arg0, Arg1, Arg2));
    }
    void test_case_6()
    {
        int Arr0[] = {2};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 1;
        int Arg3 = 2;
        verify_case(6, Arg3, ways(Arg0, Arg1, Arg2));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FoxConnection2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
