// BEGIN CUT HERE

// END CUT HERE
#line 5 "FoxAirline2.cpp"
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
bool ans;
int pre[11];
void dfs(int n,vector<int>a,vector<int>b,int pos,int num)
{
    if(pos==n)
    {
        int sum=0;
        for(int i=0;i<a.size();i++)
            if(pre[a[i]]!=pre[b[i]])
            sum++;
        if(sum<2*(num-1))
            ans=false;
        return ;
    }
    else
    {
        for(int i=0;i<num;i++)
        {
            pre[pos]=i;
            dfs(n,a,b,pos+1,num);
        }
        pre[pos]=num;
        dfs(n,a,b,pos+1,num+1);
    }
}
class FoxAirline2
{
public:
    string isPossible(int n, vector <int> a, vector <int> b)
    {
        ans=true;
        for(int i=0;i<n;i++)pre[i]=-1;
        pre[0]=0;
        dfs(n,a,b,1,1);
        if(ans)
            return "Possible";
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
        int Arr1[] = {0,0,0,1,1,2};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1,2,3,2,3,3};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "Possible";
        verify_case(0, Arg3, isPossible(Arg0, Arg1, Arg2));
    }
    void test_case_1()
    {
        int Arg0 = 6;
        int Arr1[] = {0,0,0,0,1,1,1,2,2,3,0};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1,2,3,4,2,3,4,3,4,4,5};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "Impossible";
        verify_case(1, Arg3, isPossible(Arg0, Arg1, Arg2));
    }
    void test_case_2()
    {
        int Arg0 = 5;
        int Arr1[] = {0,0,0,1,1,2,2,3};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1,2,4,2,4,3,4,4};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "Possible";
        verify_case(2, Arg3, isPossible(Arg0, Arg1, Arg2));
    }
    void test_case_3()
    {
        int Arg0 = 2;
        int Arr1[] = {0,1,1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1,0,0};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "Possible";
        verify_case(3, Arg3, isPossible(Arg0, Arg1, Arg2));
    }
    void test_case_4()
    {
        int Arg0 = 10;
        int Arr1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 7, 7, 8};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5, 6, 7, 8, 9, 3, 4, 5, 6, 7, 8, 9, 4, 5, 6, 7, 8, 9, 5, 6, 7, 8, 9, 6, 7, 8, 9, 7, 8, 9, 8, 9, 9};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "Possible";
        verify_case(4, Arg3, isPossible(Arg0, Arg1, Arg2));
    }
    void test_case_5()
    {
        int Arg0 = 2;
        int Arr1[] = {0};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "Impossible";
        verify_case(5, Arg3, isPossible(Arg0, Arg1, Arg2));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FoxAirline2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
