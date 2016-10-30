// BEGIN CUT HERE

// END CUT HERE
#line 5 "FleetFunding.cpp"
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
struct obj
{
    int pos;
    int num;
    int l,r;
    bool operator < (const obj &A)const
    {
        if(A.l==l)
            return r<A.r;
        return l<A.l;
    }
};
multiset<obj>s;
int n;
obj p[55];
int use[55];
int has[100005];
bool check(int x,int m)
{
    memset(use,0,sizeof(use));
    memset(has,0,sizeof(has));
    for(int i=1; i<=m;)
    {
        int chos=-1;
        for(int j=0;j<n;j++)
        {
            if(p[j].l<=i&&p[j].r>=i&&use[j]<p[j].num&&(chos==-1||p[chos].r>p[j].r))
                chos=j;
        }
        if(chos==-1)
            return false;
        int det=min(x-has[i],p[chos].num-use[chos]);
        has[i]+=det;
        use[chos]+=det;
        if(has[i]==x)
            i++;
    }
    return true;
}
class FleetFunding
{
public:
    int maxShips(int m, vector <int> k, vector <int> a, vector <int> b)
    {
        s.clear();
        n=k.size();
        for(int i=0; i<n; i++)
        {
            p[i].pos=i;
            p[i].num=k[i];
            p[i].l=a[i];
            p[i].r=b[i];
        }
        int l=0,r=6e7;
//        check(159,m);
        while(l<r)
        {
            int mid=(l+r+1)/2;
            if(check(mid,m))
                l=mid;
            else
                r=mid-1;
        }
        return l;
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
        int Arg0 = 3;
        int Arr1[] = {2,2,2};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1,2,1};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {3,3,2};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arg4 = 2;
        verify_case(0, Arg4, maxShips(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_1()
    {
        int Arg0 = 1;
        int Arr1[] = {10,9,8,7,6,5,4,3,2,1};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1,1,1,1,1,1,1,1,1,1};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {1,1,1,1,1,1,1,1,1,1};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arg4 = 55;
        verify_case(1, Arg4, maxShips(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_2()
    {
        int Arg0 = 10;
        int Arr1[] = {2,4,6,8,10,1,3,5,7,9};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1,2,3,4,5,6,7,8,9,10};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {1,2,3,4,5,6,7,8,9,10};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arg4 = 1;
        verify_case(2, Arg4, maxShips(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_3()
    {
        int Arg0 = 84457;
        int Arr1[] = {374778,169109,529984,498638,29462,465769,29285,394948,307944,459189,
                      349316,766627,686851,404285,850199,359378,3014,248257,558856,27393,32370,
                      574862,337134,965567,32223,935678,389898,973497,990575,483190,122899,
                      857994,991217,149619,415870
                     };
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {92,4997,11,28545,933,210,2,124,114,4513,32959,1,57,17,13,133,1843,41851,
                      3,9296,9757,28,3,769,10,11102,683,6173,11821,3982,214,2,4304,439,1998
                     };
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {81034,54474,70239,79597,47317,82938,83883,74652,84033,84422,84456,84457,
                      81095,83743,79210,84255,84455,45596,84456,82959,67062,80330,44090,84445,
                      84454,84450,45931,77190,83025,83567,83639,84333,83355,70982,84456
                     };
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arg4 = 186;
        verify_case(3, Arg4, maxShips(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_4()
    {
        int Arg0 = 2;
        int Arr1[] = {1000000,1000000,1000000,1000000,1000000};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1,1,1,2,2};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {1,1,2,2,2};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        int Arg4 = 2500000;
        verify_case(4, Arg4, maxShips(Arg0, Arg1, Arg2, Arg3));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FleetFunding ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
