// BEGIN CUT HERE

// END CUT HERE
#line 5 "MultiplicationTable2.cpp"
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

int tab[55][55];
int n;
bool vis[55];
class MultiplicationTable2
{
public:
    int minimalGoodSet(vector <int> table)
    {
        n=sqrt(table.size());
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                tab[i][j]=table[i*n+j];
        int ans=n;
        for(int i=0; i<n; i++)
        {
            memset(vis,0,sizeof(vis));
            vector<int>vec;
            deque<int>Q;
            Q.push_back(i);
            vis[i]=1;
            int flag=0;
            while(!Q.empty())
            {
                int top=Q.front();
                Q.pop_front();
                if(top<i)
                {
                    flag=1;
                    break;
                }
                vec.push_back(top);
                for(int j=0; j<vec.size(); j++)
                {
                    if(vis[tab[vec[j]][top]]==0)
                    {
                        vis[tab[vec[j]][top]]=1;
                        Q.push_back(tab[vec[j]][top]);
                    }
                    if(vis[tab[top][vec[j]]]==0)
                    {
                        vis[tab[top][vec[j]]]=1;
                        Q.push_back(tab[top][vec[j]]);
                    }
                }
            }
            if(flag)
                continue;
            else
            {
                if(ans>vec.size())
                    ans=vec.size();
            }
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
        int Arr0[] = {1,1,2,3,
                      1,0,3,2,
                      2,0,1,3,
                      1,2,3,0
                     };
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 2;
        verify_case(0, Arg1, minimalGoodSet(Arg0));
    }
    void test_case_1()
    {
        int Arr0[] = {0,1,2,3,
                      1,2,3,0,
                      2,3,0,1,
                      3,0,1,2
                     };
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 1;
        verify_case(1, Arg1, minimalGoodSet(Arg0));
    }
    void test_case_2()
    {
        int Arr0[] = {1,1,1,1,
                      2,2,2,2,
                      3,3,3,3,
                      0,0,0,0
                     };
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 4;
        verify_case(2, Arg1, minimalGoodSet(Arg0));
    }
    void test_case_3()
    {
        int Arr0[] = {0};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 1;
        verify_case(3, Arg1, minimalGoodSet(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    MultiplicationTable2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
