// BEGIN CUT HERE

// END CUT HERE
#line 5 "DistinguishableSetDiv2.cpp"
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

bool badmask[1<<20];
class DistinguishableSetDiv2
{
public:
    int count(vector <string> answer)
    {
        memset(badmask,0,sizeof(badmask));
        int n=answer.size();
        int m=answer[0].length();
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)
        {
            int mask=0;
            for(int k=0;k<m;k++)
            {
                if(answer[i][k]==answer[j][k])
                    mask|=(1<<k);
            }
            badmask[mask]=true;
        }
        for(int i=(1<<m)-1;i>0;i--)
        {
            if(badmask[i])
            {
                for(int j=0;j<m;j++)
                {
                    if(i&(1<<j))
                    {
                        badmask[i^(1<<j)]=true;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<(1<<m);i++)
        {
            if(!badmask[i])
                ans++;
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
        string Arr0[] = {"AA","AB","CC"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 2;
        verify_case(0, Arg1, count(Arg0));
    }
    void test_case_1()
    {
        string Arr0[] = {"XYZ","XYZ","XYZ"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 0;
        verify_case(1, Arg1, count(Arg0));
    }
    void test_case_2()
    {
        string Arr0[] = {"AAAA","BACA","CDCE"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 11;
        verify_case(2, Arg1, count(Arg0));
    }
    void test_case_3()
    {
        string Arr0[] = {"HGHHGUHUHI","BQHJWOSZMM","NDKSKCNXND","QOEOEIWIDS","IIQIWUNNZM"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 1017;
        verify_case(3, Arg1, count(Arg0));
    }
    void test_case_4()
    {
        string Arr0[] = {"XYZ","XAB","YAC"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arg1 = 5;
        verify_case(4, Arg1, count(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    DistinguishableSetDiv2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
