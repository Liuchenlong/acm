// BEGIN CUT HERE

// END CUT HERE
#line 5 "GCDLCM2.cpp"
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

const long long mod=1e9+7;
const int SIZE=10000005;
bool notprime[SIZE];
int prime[SIZE/10],prinum=0;
int pos[SIZE];
void getprime()
{
    memset(notprime,0,sizeof(notprime));
    for(int i=2; i<SIZE; i++)
    {
        if(notprime[i])continue;
        pos[i]=prinum;
        prime[prinum++]=i;

        for(int j=2*i; j<SIZE; j+=i)
            notprime[j]=true;
    }
}
vector<int>val;
vector<long long>ans;
vector<int>vec[SIZE/10];
class GCDLCM2
{
public:
    int getMaximalSum(vector <int> start, vector <int> d, vector <int> cnt)
    {
        getprime();
        int siz=0;
        for(int i=0; i<cnt.size(); i++)siz+=cnt[i];
        for(int i=0; i<siz; i++)ans.push_back(1LL);
        for(int i=0; i<start.size(); i++)
        {
            int x=start[i];
            for(int j=0; j<cnt[i]; j++)
            {
                int y=x;
                for(int k=0; k<prinum; k++)
                {
                    if(prime[k]*prime[k]>y)
                    {
                        if(y!=1)
                            vec[pos[y]].push_back(y);
                        break;
                    }
                    if(y%prime[k]==0)
                    {
                        int det=1;
                        while(y%prime[k]==0)
                        {
                            det*=prime[k];
                            y/=prime[k];
                        }
                        vec[k].push_back(det);
                    }
                }
                x+=d[i];
            }
        }
        for(int i=0; i<SIZE/10; i++)
        {
            if(vec[i].size()>0)
            {
                sort(vec[i].begin(),vec[i].end());
                int tsiz=vec[i].size();
                for(int j=siz-tsiz; j<siz; j++)
                {
                    ans[j]=ans[j]*vec[i][j-(siz-tsiz)]%mod;
                }
            }
        }
        long long sum=0;
        for(int i=0; i<siz; i++)
            sum=(sum+ans[i])%mod;
        return (int)sum;
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
        int Arr0[] = {1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {3};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 8;
        verify_case(0, Arg3, getMaximalSum(Arg0, Arg1, Arg2));
    }
    void test_case_1()
    {
        int Arr0[] = {3};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {0};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {5};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 15;
        verify_case(1, Arg3, getMaximalSum(Arg0, Arg1, Arg2));
    }
    void test_case_2()
    {
        int Arr0[] = {2};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {2};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {4};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 32;
        verify_case(2, Arg3, getMaximalSum(Arg0, Arg1, Arg2));
    }
    void test_case_3()
    {
        int Arr0[] = {1, 2};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {2, 3};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {2, 2};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 33;
        verify_case(3, Arg3, getMaximalSum(Arg0, Arg1, Arg2));
    }
    void test_case_4()
    {
        int Arr0[] = {5,6};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        int Arr1[] = {23, 45};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {50000, 50000};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 804225394;
        verify_case(4, Arg3, getMaximalSum(Arg0, Arg1, Arg2));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    GCDLCM2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
