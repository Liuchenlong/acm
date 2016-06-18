// BEGIN CUT HERE

// END CUT HERE
#line 5 "DarkMatterParticles.cpp"
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
int pre[1005];
void init()
{
    for(int i=0; i<=1000; i++)
        pre[i]=i;
}
int find(int x)
{
    if(pre[x]!=x)
    {
        int fx=find(pre[x]);
        pre[x]=fx;
    }
    return pre[x];
}
void unite(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    pre[fx]=fy;
}
int num[1005];
class DarkMatterParticles
{
public:
    string SplitParticles(int n, int k, vector <int> x, vector <int> y)
    {
        init();
        memset(num,0,sizeof(num));
        for(int i=0;i<x.size();i++)
            unite(x[i],y[i]);
        for(int i=0;i<n;i++)
            num[find(i)]++;
        vector<int>vec;
        for(int i=0;i<n;i++)
            if(num[i])vec.push_back(num[i]);
        bool dp[1005];
        memset(dp,0,sizeof(dp));
        dp[0]=true;
        for(int i=0;i<vec.size();i++)
        {
            for(int j=k;j>=vec[i];j--)
                dp[j]|=dp[j-vec[i]];
        }
        if(dp[k])
            return "Possible";
        else
            return "Impossible";
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
        if ((Case == -1) || (Case == 7)) test_case_7();
        if ((Case == -1) || (Case == 8)) test_case_8();
        if ((Case == -1) || (Case == 9)) test_case_9();
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
        int Arg0 = 4;
        int Arg1 = 2;
        int Arr2[] = {0,1,2,3};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {1,2,3,0};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        string Arg4 = "Impossible";
        verify_case(0, Arg4, SplitParticles(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_1()
    {
        int Arg0 = 4;
        int Arg1 = 4;
        int Arr2[] = {0,1,2,3};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {1,2,3,0};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        string Arg4 = "Possible";
        verify_case(1, Arg4, SplitParticles(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_2()
    {
        int Arg0 = 4;
        int Arg1 = 2;
        int Arr2[] = {0,1,2,3};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {2,3,0,1};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        string Arg4 = "Possible";
        verify_case(2, Arg4, SplitParticles(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_3()
    {
        int Arg0 = 4;
        int Arg1 = 3;
        int Arr2[] = {0,1,2,3};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {2,3,0,1};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        string Arg4 = "Impossible";
        verify_case(3, Arg4, SplitParticles(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_4()
    {
        int Arg0 = 3;
        int Arg1 = 3;
        int Arr2[] = {0,1,2};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {1,2,0};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        string Arg4 = "Possible";
        verify_case(4, Arg4, SplitParticles(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_5()
    {
        int Arg0 = 3;
        int Arg1 = 2;
        int Arr2[] = {0,1,2};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {1,2,0};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        string Arg4 = "Impossible";
        verify_case(5, Arg4, SplitParticles(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_6()
    {
        int Arg0 = 6;
        int Arg1 = 1;
        int Arr2[] = {0,1,4};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {1,2,5};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        string Arg4 = "Possible";
        verify_case(6, Arg4, SplitParticles(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_7()
    {
        int Arg0 = 6;
        int Arg1 = 2;
        int Arr2[] = {0,1,4};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {1,2,5};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        string Arg4 = "Possible";
        verify_case(7, Arg4, SplitParticles(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_8()
    {
        int Arg0 = 6;
        int Arg1 = 3;
        int Arr2[] = {0,1,4};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {1,2,5};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        string Arg4 = "Possible";
        verify_case(8, Arg4, SplitParticles(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_9()
    {
        int Arg0 = 6;
        int Arg1 = 6;
        int Arr2[] = {0,1,4};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {1,2,5};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        string Arg4 = "Possible";
        verify_case(9, Arg4, SplitParticles(Arg0, Arg1, Arg2, Arg3));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    DarkMatterParticles ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
