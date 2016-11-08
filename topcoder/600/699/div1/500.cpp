// BEGIN CUT HERE

// END CUT HERE
#line 5 "FromToDivisible.cpp"
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

long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
bool vis[1005];
int step[1005];
class FromToDivisible
{
public:
    int shortest(int N, int S, int T, vector <int> a, vector <int> b)
    {
        queue<int>q;
        memset(vis,0,sizeof(vis));
        memset(step,0,sizeof(step));
        int m=a.size();
        for(int i=0;i<m;i++)
        {
            if(S%a[i]==0)
            {
                if(T%b[i]==0)
                    return 1;
                q.push(i);
                vis[i]=1;
                step[i]=1;
            }
        }
        while(!q.empty())
        {
            int head=q.front();
            q.pop();
            for(int i=0;i<m;i++)
            {
                if(vis[i])continue;
                if(lcm(b[head],a[i])<=N)
                {
                    if(T%b[i]==0)
                        return step[head]+1;
                    vis[i]=1;
                    step[i]=step[head]+1;
                    q.push(i);
                }
            }
        }
        return -1;
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
        int Arg0 = 11;
        int Arg1 = 9;
        int Arg2 = 6;
        int Arr3[] = {3,10};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arr4[] = {5,2};
        vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
        int Arg5 = 2;
        verify_case(0, Arg5, shortest(Arg0, Arg1, Arg2, Arg3, Arg4));
    }
    void test_case_1()
    {
        int Arg0 = 123456789;
        int Arg1 = 18;
        int Arg2 = 12;
        int Arr3[] = {1,42,50};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arr4[] = {1,17,3};
        vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
        int Arg5 = 1;
        verify_case(1, Arg5, shortest(Arg0, Arg1, Arg2, Arg3, Arg4));
    }
    void test_case_2()
    {
        int Arg0 = 60;
        int Arg1 = 30;
        int Arg2 = 8;
        int Arr3[] = {16,15,12};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arr4[] = {2,20,5};
        vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
        int Arg5 = -1;
        verify_case(2, Arg5, shortest(Arg0, Arg1, Arg2, Arg3, Arg4));
    }
    void test_case_3()
    {
        int Arg0 = 77;
        int Arg1 = 10;
        int Arg2 = 62;
        int Arr3[] = {2,5,7,4,17,26};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arr4[] = {25,7,11,13,31,34};
        vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
        int Arg5 = 4;
        verify_case(3, Arg5, shortest(Arg0, Arg1, Arg2, Arg3, Arg4));
    }
    void test_case_4()
    {
        int Arg0 = 100;
        int Arg1 = 90;
        int Arg2 = 40;
        int Arr3[] = {20,30,100,99,100};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arr4[] = {10,30,100,100,99};
        vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
        int Arg5 = 2;
        verify_case(4, Arg5, shortest(Arg0, Arg1, Arg2, Arg3, Arg4));
    }
    void test_case_5()
    {
        int Arg0 = 1000000000;
        int Arg1 = 7000;
        int Arg2 = 424212345;
        int Arr3[] = {35000000,120000000,424212345,200000000,3500,19};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arr4[] = {15,1,7000,200000000,400000000,17};
        vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
        int Arg5 = 3;
        verify_case(5, Arg5, shortest(Arg0, Arg1, Arg2, Arg3, Arg4));
    }
    void test_case_6()
    {
        int Arg0 = 2;
        int Arg1 = 1;
        int Arg2 = 2;
        int Arr3[] = {2};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arr4[] = {1};
        vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0])));
        int Arg5 = -1;
        verify_case(6, Arg5, shortest(Arg0, Arg1, Arg2, Arg3, Arg4));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FromToDivisible ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
