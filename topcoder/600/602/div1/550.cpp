// BEGIN CUT HERE

// END CUT HERE
#line 5 "PilingRectsDiv1.cpp"
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
const int maxn=200005;
const int maxm=maxn*30;
int n,tot,m;
int lson[maxm],rson[maxm];
long long a[maxn],t[maxn];
int rt[maxm],c[maxm];
void inithash()
{
    for(int i=1;i<=n;i++)t[i]=a[i];
    sort(t+1,t+1+n);
    m=unique(t+1,t+1+n)-t-1;
}
int gethash(int x)
{
    return lower_bound(t+1,t+1+m,x)-t;
}
int build(int l,int r)
{
//    printf("%d %d %d\n",l,r,m);
    int root=tot++;
    c[root]=0;
    if(l!=r)
    {
        int mid=(l+r)/2;
        lson[root]=build(l,mid);
        rson[root]=build(mid+1,r);
    }
    return root;
}
int update(int root,int pos,int val)
{
    int newroot=tot++,tmp=newroot;
    int l=1,r=m;
    c[newroot]=c[root]+val;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(pos<=mid)
        {
            lson[newroot]=tot++;
            rson[newroot]=rson[root];
            newroot=lson[newroot];
            root=lson[root];
            r=mid;
        }
        else
        {
            lson[newroot]=lson[root];
            rson[newroot]=tot++;
            newroot=rson[newroot];
            root=rson[root];
            l=mid+1;
        }
        c[newroot]=c[root]+val;
    }
    return tmp;
}
int query(int lrt,int rrt,int k)
{
    int l=1,r=m;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(c[lson[rrt]]-c[lson[lrt]]>=k)
        {
            lrt=lson[lrt];
            rrt=lson[rrt];
            r=mid;
        }
        else
        {
            k-=(c[lson[rrt]]-c[lson[lrt]]);
            lrt=rson[lrt];
            rrt=rson[rrt];
            l=mid+1;
        }
    }
    return l;
}

pair<long long,long long>pr[200005];
class PilingRectsDiv1
{
public:
    long long getmax(int N, vector <int> XS, vector <int> YS, int XA, int XB, int XC, int YA, int YB, int YC)
    {
        int siz=2*N;
        n=siz;
        for(int i=1;i<=XS.size();i++)
        {
            long long x=XS[i-1];
            long long y=YS[i-1];
            pr[i]=make_pair(x,y);
        }
        for(int i=XS.size()+1;i<=siz;i++)
        {
            long long x=(1LL*pr[i-1].first*XA+XB)%XC+1;
            long long y=(1LL*pr[i-1].second*YA+YB)%YC+1;
            pr[i]=make_pair(x,y);
        }
        for(int i=1;i<=siz;i++)
        {
            if(pr[i].first>pr[i].second)
                swap(pr[i].first,pr[i].second);
        }
        sort(pr+1,pr+siz+1);
        tot=0;
        for(int i=1;i<=siz;i++)
            a[i]=pr[i].second;
        inithash();
        rt[0]=build(1,m);
        for(int i=1;i<=siz;i++)
        {
            int pos=gethash(pr[i].second);
            rt[i]=update(rt[i-1],pos,1);
        }
//        for(int i=1;i<=siz;i++)
//            printf("%I64d %I64d\n",pr[i].first,pr[i].second);
//        printf("\n");
        long long ans=0;
        long long x0,y0;
        x0=pr[1].first;
        y0=pr[1].second;
        for(int i=2;i<=N+1;i++)
        {
            long long x1=pr[i].first;
            long long y1=pr[i].second;
//            printf("%d\n",i);
//            printf("%I64d %I64d\n",x0,y0);
//            printf("%I64d %I64d\n",x1,y1);
            if(i==N+1)
            {
                y1=min(y1,t[query(rt[i],rt[2*N],1)]);
//                printf("%I64d\n",t[query(rt[i],rt[2*N],N-1)]);
//                printf("%I64d\n",t[query(rt[i],rt[2*N],1)]);
//                printf("%I64d\n",t[query(rt[i],rt[2*N],2)]);
                ans=max(ans,x0*y0+x1*y1);
//                printf("%I64d\n",ans);
                break;
            }
            else
            {
                long long sum1=x0*min(y0,t[query(rt[i],rt[2*N],1)])+x1*min(y1,t[query(rt[i],rt[2*N],N-i+2)]);
//                printf("%I64d %I64d\n",t[query(rt[i],rt[2*N],1)],t[query(rt[i],rt[2*N],N-i+2)]);
//                printf("\t%I64d %I64d\n",y0,y1);
//                printf("%I64d\n",x0*min(y0,))
                long long sum2=x0*min(y0,t[query(rt[i],rt[2*N],N)])+x1*min(y1,t[query(rt[i],rt[2*N],1)]);
//                printf("%I64d %I64d\n",t[query(rt[i],rt[2*N],N)],t[query(rt[i],rt[2*N],1)]);
//                printf("%I64d %I64d\n",sum1,sum2);
                ans=max(ans,max(sum1,sum2));
            }
            y0=min(y0,y1);
        }
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
        int Arg0 = 2;
        int Arr1[] = {1,2,3,4};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {10,5,3,5};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 0;
        int Arg4 = 0;
        int Arg5 = 1;
        int Arg6 = 0;
        int Arg7 = 0;
        int Arg8 = 1;
        long long Arg9 = 14LL;
        verify_case(0, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
    }
    void test_case_1()
    {
        int Arg0 = 2;
        int Arr1[] = {7,7};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {4,4};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 9;
        int Arg4 = 0;
        int Arg5 = 10;
        int Arg6 = 2;
        int Arg7 = 7;
        int Arg8 = 9;
        long long Arg9 = 56LL;
        verify_case(1, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
    }
    void test_case_2()
    {
        int Arg0 = 3;
        int Arr1[] = {5,6,9,10,4,7};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {9,5,8,6,8,7};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 0;
        int Arg4 = 0;
        int Arg5 = 1;
        int Arg6 = 0;
        int Arg7 = 0;
        int Arg8 = 1;
        long long Arg9 = 69LL;
        verify_case(2, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
    }
    void test_case_3()
    {
        int Arg0 = 10000;
        int Arr1[] = {1000000000};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {1000000000};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 93827162;
        int Arg4 = 91238127;
        int Arg5 = 98231267;
        int Arg6 = 92138287;
        int Arg7 = 98563732;
        int Arg8 = 99381279;
        long long Arg9 = 1240119561532788LL;
        verify_case(3, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
    }
    void test_case_4()
    {
        int Arg0 = 5;
        int Arr1[] = {229, 115, 934, 396, 701, 960, 357, 446, 426, 771};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {403, 407, 975, 327, 384, 66, 510, 756, 705, 703};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 105;
        int Arg4 =282;
        int Arg5 = 726;
        int Arg6 = 133;
        int Arg7 = 591;
        int Arg8 = 791;
        long long Arg9 = 295320LL;
        verify_case(4, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
    }
    void test_case_5()
    {

        int Arg0 = 34734;
        int Arr1[] = {898,579,465,665,875,391,583,901,326,133,656,562,701,707,492,617,455,441,382,952,689,656,334,877,120,318,497,25,569,962,845,562,632,898,882,498,595,889,382,507,791,548,810,606,105,869,569,970,322,974};
        vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
        int Arr2[] = {83,18,492,27,339,622,851,915,464,347,287,210,282,166,976,167,968,769,14,383,454,983,319,165,185,315,795,851,124,287,846,745,19,639,894,828,540,420,147,452,501,670,466,554,166,1,446,808,508,172};
        vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
        int Arg3 = 569;
        int Arg4 = 185;
        int Arg5 = 285;
        int Arg6 = 741;
        int Arg7 = 304;
        int Arg8 = 296;
        long long Arg9 = 10050LL;
        verify_case(5, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PilingRectsDiv1 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
