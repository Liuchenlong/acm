// BEGIN CUT HERE

// END CUT HERE
#line 5 "BearFair.cpp"
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

int cal(int l,int r)
{
    int sum=0;
    for(int i=l; i<=r; i++)
        if(i%2==0)
            sum++;
    return sum;
}
class BearFair
{
public:
    string isFair(int n, int b, vector <int> upTo, vector <int> quantity)
    {
        vector<pair<int,int> >vec;
        for(int i=0; i<upTo.size(); i++)
            vec.push_back(make_pair(upTo[i],quantity[i]));
        vec.push_back(make_pair(0,0));
        vec.push_back(make_pair(b,n));
        sort(vec.begin(),vec.end());
        int evenl=0,evenr=0;
        int oddl=0,oddr=0;
        for(int i=1; i<vec.size(); i++)
        {
            if(vec[i].second<vec[i-1].second||(vec[i].first==vec[i-1].first&&vec[i].second!=vec[i-1].second))
                return "unfair";
            if(vec[i].first-vec[i-1].first<vec[i].second-vec[i-1].second)
                return "unfair";
            if(vec[i].second==vec[i-1].second)
                continue;
            int even=cal(vec[i-1].first+1,vec[i].first);
            int odd=vec[i].first-vec[i-1].first-even;
            int det=vec[i].second-vec[i-1].second;
            evenl+=max(0,det-odd);
            evenr+=min(det,even);
            oddl+=max(0,det-even);
            oddr+=min(det,odd);
        }
        if(oddl>n/2||evenl>n/2)
            return "unfair";
        return "fair";
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
        int Arg0 = 4;
        int Arg1 = 6;
        int Arr2[] = {3,6};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {2,4};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        string Arg4 = "fair";
        verify_case(0, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_1()
    {
        int Arg0 = 4;
        int Arg1 = 6;
        int Arr2[] = {3,6};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {2,3};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        string Arg4 = "unfair";
        verify_case(1, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_2()
    {
        int Arg0 = 2;
        int Arg1 = 6;
        int Arr2[] = {1,2,3};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {1,1,2};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        string Arg4 = "unfair";
        verify_case(2, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_3()
    {
        int Arg0 = 50;
        int Arg1 = 1000;
        int Arr2[] = {736,205,264,235,273,40,901,37,900,424,122,517,820,402,669,279,455,921,774,923,107,936,484,171,248,
                      186,970,231,321,902,606,24,451,585,823,270,361,292,128,521,689,683,270,726,980,652,996,909,196,357
                     };
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {35,9,9,9,9,3,46,3,46,18,7,25,39,18,32,9,20,49,37,49,7,49,24,8,9,8,49,9,12,46,29,2,20,29,39,9,16,11,7,27,33,32,9,34,49,32,50,47,8,16};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        string Arg4 = "fair";
        verify_case(3, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
    }
    void test_case_4()
    {
        int Arg0 = 4;
        int Arg1 = 1000;
        int Arr2[] = {400,600};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arr3[] = {4,0};
        vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0])));
        string Arg4 = "unfair";
        verify_case(4, Arg4, isFair(Arg0, Arg1, Arg2, Arg3));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    BearFair ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
