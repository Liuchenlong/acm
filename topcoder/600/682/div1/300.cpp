// BEGIN CUT HERE

// END CUT HERE
#line 5 "SmilesTheFriendshipUnicorn.cpp"
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
int n;
vector<int>vec[2005];
int siz[2005];
bool vis[2005];
int step[2005];
bool flag;
void dfs(int pos,int step)
{
    if(step==4)
    {
        flag=1;
        return ;
    }
    for(int i=0; i<siz[pos]; i++)
    {
        if(vec[pos][i]==pos||vis[vec[pos][i]])continue;
        vis[vec[pos][i]]=true;
        dfs(vec[pos][i],step+1);
        vis[vec[pos][i]]=false;
    }
}
class SmilesTheFriendshipUnicorn
{
public:
    string hasFriendshipChain(int N, vector <int> A, vector <int> B)
    {
        n=N;
        for(int i=0; i<n; i++)vec[i].clear();
        for(int i=0; i<A.size(); i++)
        {
            vec[A[i]].push_back(B[i]);
            vec[B[i]].push_back(A[i]);
        }
        for(int i=0; i<n; i++)
            siz[i]=vec[i].size();
        flag=0;
        for(int i=0; i<n; i++)
        {
            if(flag)
                break;
            vis[i]=true;
            dfs(i,0);
            vis[i]=false;
        }
        if(flag)
            return "Yay!";
        else
            return ":(";
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
        int Arg0 = 5;
        int Arr1[] = {0, 0, 0, 2, 2};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1, 2, 3, 3, 4};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "Yay!";
        verify_case(0, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2));
    }
    void test_case_1()
    {
        int Arg0 = 5;
        int Arr1[] = {0, 1, 2, 3, 1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1, 2, 3, 0, 4};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "Yay!";
        verify_case(1, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2));
    }
    void test_case_2()
    {
        int Arg0 = 6;
        int Arr1[] = {0, 0, 0, 0, 0};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1, 2, 3, 4, 5};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = ":(";
        verify_case(2, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2));
    }
    void test_case_3()
    {
        int Arg0 = 8;
        int Arr1[] = {1, 3, 4, 3, 4, 3, 0, 2};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {7, 7, 7, 4, 6, 5, 4, 7};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "Yay!";
        verify_case(3, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2));
    }
    void test_case_4()
    {
        int Arg0 = 7;
        int Arr1[] = {0, 1, 1, 5, 4, 5};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {5, 2, 3, 6, 1, 1};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = ":(";
        verify_case(4, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2));
    }
    void test_case_5()
    {
        int Arg0 = 42;
        int Arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41}
                     ;
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 0};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "Yay!";
        verify_case(5, Arg3, hasFriendshipChain(Arg0, Arg1, Arg2));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SmilesTheFriendshipUnicorn ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
