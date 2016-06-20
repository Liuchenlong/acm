// BEGIN CUT HERE

// END CUT HERE
#line 5 "Procrastination.cpp"
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
#define SIZE 1000005
bool notprime[SIZE];
long long prime[SIZE/5];
int prinum;
void getprime()
{
    for(int i=2; i<SIZE; i++)
    {
        if(notprime[i])
            continue;
        prime[prinum++]=i;
        for(int j=2*i; j<SIZE; j+=i)
            notprime[j]=1;
    }
}
long long pre=0;
long long fac[20][2];
int facnum;
void dfs(vector<long long>&factor,int pos,long long val)
{
    if(pos==facnum)
    {
        factor.push_back(val);
        return ;
    }
    for(int i=0; i<=fac[pos][1]; i++)
    {
        dfs(factor,pos+1,val);
        val*=fac[pos][0];
    }
}
long long check(long long x)
{
    long long t=x;
    facnum=0;
    memset(fac,0,sizeof(fac));
    for(int i=0; i<prinum; i++)
    {
        if(prime[i]*prime[i]>x)
            break;
        if(x%prime[i]==0)
        {
            fac[facnum][0]=prime[i];
            while(x%prime[i]==0)
            {
                fac[facnum][1]++;
                x/=prime[i];
            }
            facnum++;
        }
    }
    if(x!=1)
    {
        fac[facnum][0]=x;
        fac[facnum][1]=1;
        facnum++;
    }
    vector<long long>factor;
    dfs(factor,0,1);
    sort(factor.begin(),factor.end());
    long long value=*upper_bound(factor.begin(),factor.end(),pre);
    return value;
}
class Procrastination
{
public:
    long long findFinalAssignee(long long n)
    {
        getprime();
        pre=1;
        if(n<=3)
            return n;
        while(1)
        {
            long long n1=check(n-1);
            long long n2=check(n);
            if(n1*2<=(n-1)&&n2*2<=(n))
            {
                if(n1<n2)
                {
                    n--;
                    pre=n1;
                }
                else
                {
                    n++;
                    pre=n2;
                }
            }
            else if(n1*2<=(n-1))
            {
                n--;
                pre=n1;
            }
            else if(n2*2<=n)
            {
                n++;
                pre=n2;
            }
            else
                break;
        }
        return n;
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
    void verify_case(int Case, const long long &Expected, const long long &Received)
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
        long long Arg0 = 2LL;
        long long Arg1 = 2LL;
        verify_case(0, Arg1, findFinalAssignee(Arg0));
    }
    void test_case_1()
    {
        long long Arg0 = 8LL;
        long long Arg1 = 11LL;
        verify_case(1, Arg1, findFinalAssignee(Arg0));
    }
    void test_case_2()
    {
        long long Arg0 = 20LL;
        long long Arg1 = 20LL;
        verify_case(2, Arg1, findFinalAssignee(Arg0));
    }
    void test_case_3()
    {
        long long Arg0 = 196248LL;
        long long Arg1 = 196259LL;
        verify_case(3, Arg1, findFinalAssignee(Arg0));
    }
    void test_case_4()
    {
        long long Arg0 = 5587021440LL;
        long long Arg1 = 5587021440LL;
        verify_case(4, Arg1, findFinalAssignee(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Procrastination ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
