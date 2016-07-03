// BEGIN CUT HERE

// END CUT HERE
#line 5 "FoxAndGemstone.cpp"
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
const int m=16;
int sum[55][1<<m];
int cnt[55][m];
int maxn[1<<m];
long long dp[55][1<<m];
class FoxAndGemstone
{
public:
    string isPossible(vector <string> bags)
    {
        for(int i=0;i<bags.size();i++)
        {
            int len=bags[i].length();
            char str[55];
            for(int j=0;j<len;j++)
                str[j]=bags[i][j];
            str[len]='\0';
            sort(str,str+len);
            bags[i]=str;
        }
        sort(bags.begin(),bags.end());
        memset(cnt,0,sizeof(cnt));
        memset(sum,0,sizeof(sum));
        memset(maxn,0,sizeof(maxn));
        memset(dp,0,sizeof(dp));
        int n=unique(bags.begin(),bags.end())-bags.begin();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<bags[i].length();j++)
                cnt[i][bags[i][j]-'A']++;
            for(int j=0;j<(1<<m);j++)
            {
                for(int k=0;k<m;k++)
                {
                    if(j&(1<<k))
                        sum[i][j]+=cnt[i][k];
                }
            }
        }
        for(int i=0;i<(1<<m);i++)
        {
            for(int j=0;j<n;j++)
                maxn[i]=max(maxn[i],sum[j][i]);
        }
        long long ans=1;
        for(int i=1;i<=16;i++)
            ans*=i;
        for(int i=0;i<n;i++)
        {
            dp[i][0]=1;
            for(int j=1;j<(1<<m);j++)
            {
                if(sum[i][j]==maxn[j])
                {
                    for(int k=0;k<m;k++)
                    {
                        if(j&(1<<k))
                            dp[i][j]+=dp[i][j^(1<<k)];
                    }
                }
            }
            ans-=dp[i][(1<<m)-1];
        }
        if(ans>0)return "Impossible";
        return "Possible";
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
        string Arr0[] = {"CA", "AB", "CB", "AA", "CC", "CB", "AC", "BC", "BC", "CA", "CA", "CA", "CB", "CA", "AC", "AB", "CC", "CB", "BC", "AA", "AA", "BA", "AB", "BC", "CA", "CA", "CB", "BC", "BA", "AC", "CA"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arg1 = "Possible";
        verify_case(0, Arg1, isPossible(Arg0));
    }
    void test_case_1()
    {
        string Arr0[] = {"AA", "EB", "BA", "AC", "AD", "BB", "CB", "CB", "BC", "BE", "CB", "CC", "BC", "BA", "ED", "AE", "CE", "AB", "CD", "EE", "CE", "EC", "DC", "DC", "AB", "DC", "DA", "CD", "BE", "AB", "AE", "AB", "EB", "DA", "DA"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arg1 = "Impossible";
        verify_case(1, Arg1, isPossible(Arg0));
    }
    void test_case_2()
    {
        string Arr0[] = {"A", "B", "C", "AB", "AC", "BC", "ABC"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arg1 = "Possible";
        verify_case(2, Arg1, isPossible(Arg0));
    }
    void test_case_3()
    {
        string Arr0[] = {"AB","AC","AD","BC","BD","CD"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arg1 = "Possible";
        verify_case(3, Arg1, isPossible(Arg0));
    }
    void test_case_4()
    {
        string Arr0[] = {"AB", "CD"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arg1 = "Impossible";
        verify_case(4, Arg1, isPossible(Arg0));
    }
    void test_case_5()
    {
        string Arr0[] = {"A", "A", "A"};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arg1 = "Possible";
        verify_case(5, Arg1, isPossible(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FoxAndGemstone ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
