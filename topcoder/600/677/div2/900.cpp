// BEGIN CUT HERE

// END CUT HERE
#line 5 "PalindromePath.cpp"
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


class PalindromePath
{
public:
    int shortestLength(int n, vector <int> a, vector <int> b, string c)
    {
        int INF=100000000;
        int dp[22][22];
        char edge[22][22];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                edge[i][j]='#';
                dp[i][j]=INF;
            }
            dp[i][i]=0;
        }
        for(int i=0; i<a.size(); i++)
        {
            edge[a[i]][b[i]]=c[i];
            edge[b[i]][a[i]]=c[i];
            dp[a[i]][b[i]]=1;
            dp[b[i]][a[i]]=1;
        }

        for(int tim=0; tim<400; tim++)
        {
            for(int a=0; a<n; a++)for(int b=0; b<n; b++)
                {
                    if(dp[a][b]!=INF)
                    {
                        for(int i=0; i<n; i++)for(int j=0; j<n; j++)
                            {
                                if(edge[i][a]!='#'&&edge[i][a]==edge[b][j])
                                {
                                    dp[i][j]=MIN(dp[i][j],2+dp[a][b]);
                                }
                            }
                    }
                }
        }
        return (dp[0][1]==INF?-1:dp[0][1]);

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
        int Arg0 = 5;
        int Arr1[] = {2,2,0,3,4};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {0,1,3,4,1};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "abxyx";
        int Arg4 = 3;
        verify_case(0, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_1()
    {
        int Arg0 = 5;
        int Arr1[] = {2,2,0,3,4};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {0,1,3,4,1};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "abxyz";
        int Arg4 = -1;
        verify_case(1, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_2()
    {
        int Arg0 = 7;
        int Arr1[] = {0,0,3,4,5,6};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {2,3,4,5,6,1};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "abaaaa";
        int Arg4 = 9;
        verify_case(2, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_3()
    {
        int Arg0 = 6;
        int Arr1[] = {0,0,3,4,5};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {2,3,4,5,1};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "abaaa";
        int Arg4 = -1;
        verify_case(3, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_4()
    {
        int Arg0 = 2;
        int Arr1[] = {0};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "x";
        int Arg4 = 1;
        verify_case(4, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_5()
    {
        int Arg0 = 20;
        int Arr1[] = {18};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {19};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "z";
        int Arg4 = -1;
        verify_case(5, Arg4, shortestLength(Arg0, Arg1, Arg2, Arg3));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PalindromePath ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
