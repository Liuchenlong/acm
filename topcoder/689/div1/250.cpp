// BEGIN CUT HERE

// END CUT HERE
#line 5 "ColorfulGarden.cpp"
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

vector<char>vec;
map <char,int>mp;
bool cmp(char a,char b)
{
    return mp[a]>mp[b];
}
class ColorfulGarden
{
public:
    vector <string> rearrange(vector <string> garden)
    {
        mp.clear();
        vec.clear();
        vector<string>ans;
        int N=garden[0].length();
        for(int i=0;i<2;i++)for(int j=0;j<N;j++)
        {
            if(mp[garden[i][j]])
                ;
            else
                vec.push_back(garden[i][j]);
            mp[garden[i][j]]++;
        }
        sort(vec.begin(),vec.end(),cmp);
        for(int i=0; i<vec.size(); i++)
        {
            if(mp[vec[i]]>N)
            {
                return ans;
            }
        }
        string s1="",s2="";
        for(int i=0;i<vec.size();i++)
        {
            if(mp[vec[i]]==0)
                continue;
            if(s1.length()==N)
            {
                while(mp[vec[i]])
                {
                    s2+=vec[i];
                    mp[vec[i]]--;
                }
            }
            else
            {
                while(mp[vec[i]]&&s1.length()<N)
                {
                    s1+=vec[i];
                    mp[vec[i]]--;
                }
                i--;
            }
        }
        string ans1="",ans2="";
        for(int i=0; i<N; i++)
        {
            if(i%2==0)
            {
                ans1+=s1[i];
                ans2+=s2[i];
            }
            else
            {
                ans1+=s2[i];
                ans2+=s1[i];
            }
        }
        ans.push_back(ans1);
        ans.push_back(ans2);
//        cout << ans1 << endl;
//        cout << ans2 << endl;
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
    void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received)
    {
        cerr << "Test Case #" << Case << "...";
        if (Expected == Received) cerr << "PASSED" << endl;
        else
        {
            cerr << "FAILED" << endl;
            cerr << "\tExpected: " << print_array(Expected) << endl;
            cerr << "\tReceived: " << print_array(Received) << endl;
        }
    }
    void test_case_0()
    {
        string Arr0[] = {"aa",
                         "bb"
                        };
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arr1[] = {"ab", "ba" };
        vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(0, Arg1, rearrange(Arg0));
    }
    void test_case_1()
    {
        string Arr0[] = {"xxxx",
                         "xxxx"
                        };
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arr1[] = { };
        vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(1, Arg1, rearrange(Arg0));
    }
    void test_case_2()
    {
        string Arr0[] = {"abcd",
                         "abcd"
                        };
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arr1[] = {"abcd", "dcba" };
        vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(2, Arg1, rearrange(Arg0));
    }
    void test_case_3()
    {
        string Arr0[] = {"abcdefghijklm",
                         "nopqrstuvwxyz"
                        };
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arr1[] = {"abcdefghijklm", "nopqrstuvwxyz" };
        vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(3, Arg1, rearrange(Arg0));
    }
    void test_case_4()
    {
        string Arr0[] = {"aaa",
                         "aab"
                        };
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arr1[] = { };
        vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        verify_case(4, Arg1, rearrange(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ColorfulGarden ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
