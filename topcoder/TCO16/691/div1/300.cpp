// BEGIN CUT HERE

// END CUT HERE
#line 5 "Sunnygraphs.cpp"
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
int dist[55][55];
int n;
int inf=1000000;
void floyd()
{
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(i!=j&&dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
}

class Sunnygraphs
{
public:
    long long count(vector <int> a)
    {
        n=a.size();
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                dist[i][j]=inf;
        for(int i=0; i<n; i++)
        {
            dist[i][i]=0;
            dist[i][a[i]]=1;
            dist[a[i]][i]=1;
        }
        floyd();
        long long ans=0;
        if(dist[0][1]==inf)
        {
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    dist[i][j]=inf;
            for(int i=0; i<n; i++)
            {
                dist[i][i]=0;
                dist[i][a[i]]=1;
            }
            floyd();
            int s1=0,s2=0;
            int s3=0;
            for(int i=0; i<n; i++)
            {
                if(dist[0][i]==inf)
                    s1++;
                if(dist[1][i]==inf)
                    s2++;
                if(dist[0][i]==inf&&dist[1][i]==inf)
                    s3++;
            }
            ans=(1LL<<n)-((1LL<<s1)+(1LL<<s2)-(1LL<<s3));
            return ans;
        }
        else
        {

            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    dist[i][j]=inf;
            for(int i=0; i<n; i++)
            {
                dist[i][i]=0;
                dist[i][a[i]]=1;
            }
            floyd();
            if(dist[0][1]!=inf&&dist[1][0]!=inf)
            {
                ans=(1LL<<n);
                return ans;
            }
            else if(dist[0][1]!=inf)
            {
                int pos=-1;
                for(int i=0; i<n; i++)
                {
                    if(dist[0][i]!=inf&&dist[1][i]!=inf)
                    {
                        if(pos==-1)
                            pos=i;
                        else
                        {
                            if(dist[0][i]<dist[0][pos])
                                pos=i;
                        }
                    }
                }
                int d=dist[0][pos];
                int s=0;
                for(int i=0; i<n; i++)
                {
                    if(dist[1][i]!=inf)
                        continue;
                    if(dist[0][i]!=inf&&dist[i][1]!=inf)
                        continue;
                    s++;
                }
                return (1LL<<n)-(1LL<<s)*((1<<d)-1);
            }
            else if(dist[1][0]!=inf)
            {
                int pos=-1;
                for(int i=0; i<n; i++)
                {
                    if(dist[1][i]!=inf&&dist[0][i]!=inf)
                    {
                        if(pos==-1)
                            pos=i;
                        else
                        {
                            if(dist[1][i]<dist[1][pos])
                                pos=i;
                        }
                    }
                }
                int d=dist[1][pos];
                int s=0;
                for(int i=0; i<n; i++)
                {
                    if(dist[0][i]!=inf)
                        continue;
                    if(dist[1][i]!=inf&&dist[i][0]!=inf)
                        continue;
                    s++;
                }
                return (1LL<<n)-(1LL<<s)*((1<<d)-1);
            }
            else
            {
                int p1=0,p2=0;
                for(int i=2; i<n; i++)
                {
                    if(dist[0][i]!=inf&&dist[1][i]!=inf)
                    {
                        if(p1==0)
                        {
                            p1=i;
                            p2=i;
                        }
                        else
                        {
                            if(dist[0][i]<dist[0][p1])
                                p1=i;
                            if(dist[1][i]<dist[1][p2])
                                p2=i;
                        }
                    }
                }
                if(dist[0][p1]>dist[0][p2])
                    swap(p1,p2);
                long long ans=0;
                int s=0;
                for(int i=0; i<n; i++)
                {
                    if(dist[1][i]!=inf)
                        continue;
                    if(dist[0][i]!=inf&&dist[i][p2]!=inf)
                        continue;
                    s++;
                }
                ans=ans+((1LL<<dist[0][p1])-1)*(1LL<<s);
                s=0;
                for(int i=0; i<n; i++)
                {
                    if(dist[0][i]!=inf)
                        continue;
                    if(dist[1][i]!=inf&&dist[i][p1]!=inf)
                        continue;
                    s++;
                }
                ans=ans+((1LL<<dist[1][p2])-1)*(1LL<<s);
                return (1LL<<n)-ans;
            }
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
        int Arr0[] = {6, 11, 27, 33, 0, 13, 2, 22, 15, 11, 7, 19, 17, 23, 30, 8, 9, 22, 6, 16, 16, 30, 0, 20, 4, 8, 5, 12, 31, 26, 16, 12, 25, 15, 12};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        long long Arg1 = 33025949696LL;
        verify_case(0, Arg1, count(Arg0));
    }
    void test_case_1()
    {
        int Arr0[] = {16, 6, 21, 17, 21, 9, 0, 10, 18, 17, 12, 24, 23, 15, 22, 23, 4, 14, 22, 21, 4, 22, 24, 3, 23};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        long long Arg1 = 33529856LL;
        verify_case(1, Arg1, count(Arg0));
    }
    void test_case_2()
    {
        int Arr0[] = {2,3,0,1};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        long long Arg1 = 9LL;
        verify_case(2, Arg1, count(Arg0));
    }
    void test_case_3()
    {
        int Arr0[] = {2,2,3,4,3};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        long long Arg1 = 30LL;
        verify_case(3, Arg1, count(Arg0));
    }
    void test_case_4()
    {
        int Arr0[] = {18,18,20,28,7,27,8,13,40,3,7,21,30,17,13,34,29,16,15,11,0,9,39,36,38,23,24,8,4,9,29,22,35,5,13,23,3,27,34,23,8};
        vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        long long Arg1 = 2198754820096LL;
        verify_case(4, Arg1, count(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Sunnygraphs ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
