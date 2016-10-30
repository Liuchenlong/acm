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

struct triple
{
    int nod;
    int tim;
    int dir;
    triple(int a,int b,int c)
    {
        nod=a;
        tim=b;
        dir=c;
    }
};
bool cmp(triple a,triple b)
{
    return a.tim<b.tim;
}
class RailroadSwitchOperator
{
public:
    int minEnergy(int N, vector <int> x, vector <int> t)
    {
        vector <triple>vec;
        for(int i=0; i<x.size(); i++)
        {
            int p=0;
            x[i]--;
            int tim=t[i];
            int l=0,r=N;
            while(l+1<r)
            {
                int mid=(l+r)/2;
                if(x[i]<mid)
                {
                    r=mid;
                    vec.push_back(triple(p,tim,-1));
                    p=2*p+1;
                }
                else
                {
                    l=mid;
                    vec.push_back(triple(p,tim,1));
                    p=2*p+2;
                }
                tim++;
            }
        }
        sort(vec.begin(),vec.end(),cmp);
        vector <int>point(2*N-1,-1);
        vector <int>lastuse(2*N-1,0);
        int ans=0;
        int last=-1;
        for(int i=0;i<vec.size();i++)
        {
            if(lastuse[vec[i].nod]<last)
            {
                lastuse[vec[i].nod]=vec[i].tim;
                point[vec[i].nod]=vec[i].dir;
            }
            else
            {
                if(point[vec[i].nod]==vec[i].dir)
                {
                    lastuse[vec[i].nod]=vec[i].tim;
                }
                else
                {
                    ans++;
                    last=vec[i].tim;
                    lastuse[vec[i].nod]=vec[i].tim;
                    point[vec[i].nod]=vec[i].dir;
                }
            }
        }
        return ans;
    }


};
