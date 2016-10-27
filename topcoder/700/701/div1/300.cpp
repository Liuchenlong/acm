// BEGIN CUT HERE

// END CUT HERE
#line 5 "PartisanGame.cpp"
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

int nxta[1<<5][1<<5][32];
int nxtb[1<<5][1<<5][32];
void init(vector<int>a,vector<int>b)
{
    memset(nxta,0,sizeof(a));
    memset(nxtb,0,sizeof(b));
    int numa[6],numb[6];
    for(int i=0; i<(1<<5); i++)
    {
        for(int k=0; k<5; k++)
        {
            numa[k]=((i&(1<<k))>0);
        }
        for(int j=0; j<(1<<5); j++)
        {
            for(int k=0; k<5; k++)
            {
                numb[k]=((j&(1<<k))>0);
            }
            numa[5]=0;
            for(int k=0; k<a.size(); k++)
                if(numb[5-a[k]]==0)
                    numa[5]=1;
            numb[5]=0;
            for(int k=0; k<b.size(); k++)
                if(numa[5-b[k]]==0)
                    numb[5]=1;
            int na=0,nb=0;
            for(int k=1; k<=5; k++)
            {
                na+=numa[k]*(1<<(k-1));
                nb+=numb[k]*(1<<(k-1));
            }
            nxta[i][j][0]=na;
            nxtb[i][j][0]=nb;
        }
    }
    for(int k=1; k<32; k++)
    {
        for(int i=0; i<(1<<5); i++)for(int j=0; j<(1<<5); j++)
            {
                nxta[i][j][k]=nxta[nxta[i][j][k-1]][nxtb[i][j][k-1]][k-1];
                nxtb[i][j][k]=nxtb[nxta[i][j][k-1]][nxtb[i][j][k-1]][k-1];
            }
    }
}
class PartisanGame
{
public:
    string getWinner(int n, vector <int> a, vector <int> b)
    {
        init(a,b);
        int sa[10],sb[10];
        sa[0]=sb[0]=0;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=1; i<=5; i++)
        {
            sa[i]=0;
            for(int k=0; k<a.size(); k++)
            {
                if(i>=a[k]&&sb[i-a[k]]==0)
                    sa[i]=1;
            }
            sb[i]=0;
            for(int k=0; k<b.size(); k++)
            {
                if(i>=b[k]&&sa[i-b[k]]==0)
                    sb[i]=1;
            }
        }
        if(n<=5)
        {
            if(sa[n])
                return "Alice";
            else
                return "Bob";
        }
        else
        {
            int sta=0,stb=0;
            n-=5;
            for(int i=1;i<=5;i++)
            {
                sta+=sa[i]*(1<<(i-1));
                stb+=sb[i]*(1<<(i-1));
            }
            while(n)
            {
                for(int k=30;k>=0;k--)
                {
                    if((1<<k)<=n)
                    {
                        n-=(1<<k);
                        int ta=sta,tb=stb;
                        sta=nxta[ta][tb][k];
                        stb=nxtb[ta][tb][k];
                        break;
                    }
                }
            }
            if(sta&(1<<4))
                return "Alice";
            else
                return "Bob";
        }
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
        int Arg0 = 7;
        int Arr1[] = {3, 4};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {4};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "Alice";
        verify_case(0, Arg3, getWinner(Arg0, Arg1, Arg2));
    }
    void test_case_1()
    {
        int Arg0 = 10;
        int Arr1[] = {1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {4, 3, 2};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "Bob";
        verify_case(1, Arg3, getWinner(Arg0, Arg1, Arg2));
    }
    void test_case_2()
    {
        int Arg0 = 104982;
        int Arr1[] = {2, 3, 4, 5};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {2, 5};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "Alice";
        verify_case(2, Arg3, getWinner(Arg0, Arg1, Arg2));
    }
    void test_case_3()
    {
        int Arg0 = 999999999;
        int Arr1[] = {4};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {5};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "Bob";
        verify_case(3, Arg3, getWinner(Arg0, Arg1, Arg2));
    }
    void test_case_4()
    {
        int Arg0 = 1000000000;
        int Arr1[] = {1,2,3,4,5};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1,2,3,4,5};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        string Arg3 = "Alice";
        verify_case(4, Arg3, getWinner(Arg0, Arg1, Arg2));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PartisanGame ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
