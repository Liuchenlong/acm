// BEGIN CUT HERE

// END CUT HERE
#line 5 "PairsOfStrings.cpp"
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
long long mod=1e9+7;
long long qpow(long long x,long long k)
{
    long long ans=1;
    while(k)
    {
        if(k&1)
            ans=ans*x%mod;
        k>>=1;
        x=x*x%mod;
    }
    return ans;
}
map<int,int>mp;
long long cal(int n,int k)
{
    if(mp.find(n)!=mp.end())
        return mp[n];
    long long ans=qpow(k,n)-k;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ans-=cal(i,k);
            if(i*i==n)
                ;
            else
                ans-=cal(n/i,k);
        }
    }
    ans=(ans%mod+mod)%mod;
    return mp[n]=ans;
}
class PairsOfStrings
{
public:
    int getNumber(int n, int k)
    {
        mp.clear();
        mp[1]=k;
        long long ans=0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                ans+=cal(i,k)*i%mod;
                if(i*i==n);
                else
                    ans+=cal(n/i,k)*(n/i)%mod;
            }
        }
        ans%=mod;
        return ans%mod;;
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
        int Arg0 = 2;
        int Arg1 = 2;
        int Arg2 = 6;
        verify_case(0, Arg2, getNumber(Arg0, Arg1));
    }
    void test_case_1()
    {
        int Arg0 = 3;
        int Arg1 = 2;
        int Arg2 = 20;
        verify_case(1, Arg2, getNumber(Arg0, Arg1));
    }
    void test_case_2()
    {
        int Arg0 = 3;
        int Arg1 = 4;
        int Arg2 = 184;
        verify_case(2, Arg2, getNumber(Arg0, Arg1));
    }
    void test_case_3()
    {
        int Arg0 = 6;
        int Arg1 = 2;
        int Arg2 = 348;
        verify_case(3, Arg2, getNumber(Arg0, Arg1));
    }
    void test_case_4()
    {
        int Arg0 = 100;
        int Arg1 = 26;
        int Arg2 = 46519912;
        verify_case(4, Arg2, getNumber(Arg0, Arg1));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PairsOfStrings ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
