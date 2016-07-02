// BEGIN CUT HERE

// END CUT HERE
#line 5 "Moneymanager.cpp"
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

int dp[26][26][505];
int sum[55];
struct project
{
    int a;
    int b;
    project(){}
    project(int A,int B)
    {
        a=A;
        b=B;
    }
    bool operator <(const project x)const
    {
        return a*x.b<b*x.a;
    }
};

class Moneymanager
{
public:
    int getbest(vector <int> a, vector <int> b, int X)
    {
        int n=a.size();
        vector<project>vec;
        for(int i=0;i<n;i++)
            vec.push_back(project(a[i],b[i]));
        sort(vec.begin(),vec.end());
        sum[0]=vec[0].b;
        for(int i=1;i<n;i++)
            sum[i]=sum[i-1]+vec[i].b;
        int N=n/2;
        int ans=0;
        for(int sb=1;sb<=N*10;sb++)
        {
            memset(dp,-1,sizeof(dp));
            dp[0][0][0]=0;
//            printf("\t%d\n",sb);
            for(int i=0;i<=N;i++)
            {
                for(int j=0;j<=N;j++)
                {
                    project nxt=vec[i+j];
                    for(int s=0;s<=j*10;s++)
                    {
                        if(dp[i][j][s]==-1)
                            continue;
                        if(i<N)
                        {
                            dp[i+1][j][s]=max(dp[i+1][j][s],dp[i][j][s]+nxt.a*(sb+sum[i+j]-s));
                        }
                        if(j<N)
                        {
                            dp[i][j+1][s+nxt.b]=max(dp[i][j+1][s+nxt.b],dp[i][j][s]+nxt.a*(s+nxt.b));
                        }
//                        if(sb<=2)
//                        {
//                            printf("%d %d %d %d\n",i,j,s,dp[i][j][s]);
//                        }
                    }
                }
            }
            if(dp[N][N][sb]>=0)
                ans=max(ans,dp[N][N][sb]+X*sb);
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
        int Arr0[] = {1,1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {2,1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 0;
        int Arg3 = 5;
        verify_case(0, Arg3, getbest(Arg0, Arg1, Arg2));
    }
    void test_case_1()
    {
        int Arr0[] = {1,1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1,5};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 10;
        int Arg3 = 61;
        verify_case(1, Arg3, getbest(Arg0, Arg1, Arg2));
    }
    void test_case_2()
    {
        int Arr0[] = {4,4,6,6};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {2,2,3,3};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 100;
        int Arg3 = 726;
        verify_case(2, Arg3, getbest(Arg0, Arg1, Arg2));
    }
    void test_case_3()
    {
        int Arr0[] = {30,13,28,59,26,62,48,75,6,69,94,51};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {4,6,4,5,4,3,1,5,6,5,2,2};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arg2 = 62;
        int Arg3 = 22096;
        verify_case(3, Arg3, getbest(Arg0, Arg1, Arg2));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Moneymanager ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
