// BEGIN CUT HERE

// END CUT HERE
#line 5 "Nim.cpp"
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
const int maxn=1<<18;
bool notprime[maxn];
int prime[maxn],prinum;
bool flag=false;
void getprime()
{
    if(flag)return ;
    notprime[0]=notprime[1]=1;
    for(int i=2; i<maxn; i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
        }
        for(int j=0; j<prinum&&i*prime[j]<maxn; j++)
        {
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    flag=true;
}

//copy from Nero
//C[i^j]+=A[i]*B[j]
//C=fwt(fwt(A,1)*fwt(B,1),0)
const int MOD = (int)1e9 + 7;
const int inv2 = (MOD + 1) >> 1;
int A[1 << 18];
void fwt(int A[],int n,int inv)
{
    for (int l = 1; l << 1 <= n; l <<= 1)
    {
        for (int s = 0; s < n; ++ s)
        {
            if (~s & l)
            {
                int a = A[s];
                int b = A[s ^ l];
                if (inv == 1)
                {
                    A[s] = (a - b + MOD) % MOD;
                    //xor a-b   $ and a+b   $ or a
                    A[s ^ l] = (a + b) % MOD;
                    //xor a+b   $ and b     $ or a+b
                }
                else
                {
                    A[s] = (a + b) * 1ll * inv2 % MOD;
                    A[s ^ l] = (b - a + MOD) * 1ll * inv2 % MOD;
                }
            }
        }
    }
}
long long qpow(long long x,long long k,long long mod)
{
    long long ans=1;
    while(k)
    {
        if(k&1)ans=ans*x%mod;
        k>>=1;
        x=x*x%mod;
    }
    return ans;
}
class Nim
{
public:
    int count(int K, int L)
    {
        getprime();
//        for(int i=0; i<50; i++)printf("%d %d\n",i,notprime[i]);
        int len=1;
        while(len<=L)len<<=1;
        for(int i=0; i<len; i++)A[i]=0;
        for(int i=2; i<=L; i++)A[i]=1^notprime[i];
        fwt(A,len,1);
        for(int i=0; i<len; i++)A[i]=qpow(A[i],K,MOD);
        fwt(A,len,0);
        return A[0];
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
        int Arg0 = 3;
        int Arg1 = 7;
        int Arg2 = 6;
        verify_case(0, Arg2, count(Arg0, Arg1));
    }
    void test_case_1()
    {
        int Arg0 = 4;
        int Arg1 = 13;
        int Arg2 = 120;
        verify_case(1, Arg2, count(Arg0, Arg1));
    }
    void test_case_2()
    {
        int Arg0 = 10;
        int Arg1 = 100;
        int Arg2 = 294844622;
        verify_case(2, Arg2, count(Arg0, Arg1));
    }
    void test_case_3()
    {
        int Arg0 = 123456789;
        int Arg1 = 12345;
        int Arg2 = 235511047;
        verify_case(3, Arg2, count(Arg0, Arg1));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Nim ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
