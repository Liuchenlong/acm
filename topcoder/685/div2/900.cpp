// BEGIN CUT HERE

// END CUT HERE
#line 5 "RGBTree.cpp"
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

int dp[1<<13][5][5][5];

class RGBTree
{
public:
    string exist(vector <string> G)
    {
        int n=G.size();
        int t=(n-1)/3;
        memset(dp,0,sizeof(dp));
        dp[0][0][0][0]=-1;
        for(int i=0; i<(1<<n); i++)
        {
            for(int g=0; g<=t; g++)for(int b=0; b<=t; b++)for(int r=0; r<=t; r++)
                    {
                        if(dp[i][g][b][r]==0)
                            continue;
                        for(int j=0; j<n; j++)
                            if(i&(1<<j)||dp[i][g][b][r]==-1)
                                for(int k=0; k<n; k++)
                                {
                                    if(G[j][k]=='.')
                                        continue;
                                    if(i&(1<<k))
                                        continue;
                                    int GREEN=g;
                                    int BLUE=b;
                                    int RED=r;
                                    if(G[j][k]=='G')
                                        GREEN++;
                                    else if(G[j][k]=='B')
                                        BLUE++;
                                    else if(G[j][k]=='R')
                                        RED++;
                                    if(GREEN<=t&&BLUE<=t&&RED<=t)
                                    {
                                        dp[i|(1<<k)|(1<<j)][GREEN][BLUE][RED]=1;
                                    }
                                }
                    }
        }
        if(dp[(1<<n)-1][t][t][t])
            return "Exist";
        else
            return "Does not exist";
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
        string Arr0[] = {".RGB",
                         "R...",
                         "G...",
                         "B..."
                        };
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arg1 = "Exist";
        verify_case(0, Arg1, exist(Arg0));
    }
    void test_case_1()
    {
        string Arr0[] = {".RRB",
                         "R...",
                         "R...",
                         "B..."
                        };
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arg1 = "Does not exist";
        verify_case(1, Arg1, exist(Arg0));
    }
    void test_case_2()
    {
        string Arr0[] = {".R..BG..G..RG","R...GG..BR.G.","...G.GG.RR.BB","..G.RR.B..GRB","BG.R.G.BRRR.G","GGGRG.R....RR","..G..R.BGRR..","...BB.B.RB.G.","GBR.R.GR.B.R.",".RR.R.RBB.BRB","...GR.R..B...","RGBR.R.GRR...","G.BBGR...B..."}
                        ;
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arg1 = "Exist";
        verify_case(2, Arg1, exist(Arg0));
    }
    void test_case_3()
    {
        string Arr0[] = {".............",".......BB.R..",".......RR....",".....G.G....R","........BB...","...G.........","........B...R",".BRG.......G.",".BR.B.B...GB.","....B......GR",".R......G....",".......GBG..B","...R..R..R.B."}
                        ;
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arg1 = "Does not exist";
        verify_case(3, Arg1, exist(Arg0));
    }
    void test_case_4()
    {
        string Arr0[] = {"..B.BB...RB..","......R..B.G.","B.......BB...",".......R...G.","B....GRB..R..","B...G.RG.R...",".R..RR..B.RB.","...RBG...G...","..B...B......","RBB..R.G....R","B...R.R......",".G.G..B.....R",".........R.R."}
                        ;
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arg1 = "Exist";
        verify_case(4, Arg1, exist(Arg0));
    }
    void test_case_5()
    {
        string Arr0[] = {"....",
                         "....",
                         "....",
                         "...."
                        }
                        ;
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
        string Arg1 = "Does not exist";
        verify_case(5, Arg1, exist(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    RGBTree ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
