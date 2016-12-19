#include<stdio.h>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
#define eps 1e-8
#include "iostream"
#include "cstring"
#include "algorithm"
#include "cmath"
#include "cstdio"
#include "sstream"
#include "queue"
#include "vector"
#include "list"
#include "string"
#include "stack"
#include "cstdlib"
#include "deque"
#include "fstream"
#include "map"
#include "set"
#include <ctime>
using namespace std;

typedef long long LL;
const int N = 1000000+100;
const LL INF = 1e18;
const int inf = 522133279;//2139062143;
const int mod = 1000000009;

#define lson(x) (x<<1)
#define rson(x) (x<<1|1)
#define LS (lson(rt))
#define RS (rson(rt))
#define MID(x,y) ((x+y)>>1)
#define FR (freopen("in.txt","r",stdin))
#define FO (freopen("out.txt","w",stdout))
#define clr(a,b) memset(a,b,sizeof(a))
#define lowbit(t) (t&-t)
#define EAT while(getchar() != '\n')
#define PI acos(-1.0)
#define mp make_pair
#define SZ size()
#define PB(x) push_back(x)
#define TL (tree[rt].l)
#define TR (tree[rt].r)
#define FI(a) (a.first)
#define SE(a) (a.second)
#define TOH(a) (1.0*a/180.0*PI)
#define TOJ(a) (1.0*a/PI*180)
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a>b?b:a)

int a[10];
int main()
{
    for(int i = 0 ; i < 6 ; i++)
        cin >> a[i];
    sort(a,a+6);

    if( a[0] == a[1] && a[0] == a[2] && a[0] == a[3])
    {
        if(a[4] == a[5])
            printf("Elephant\n");
        else printf("Bear\n");
    }

    else if(a[4] == a[1] && a[4] == a[2] && a[4] == a[3])
    {
        if(a[0] == a[5])
            printf("Elephant\n");
        else printf("Bear\n");
    }

    else if( a[4] == a[5] && a[4] == a[2] && a[4] == a[3])
    {
        if(a[1] == a[0])
            printf("Elephant\n");
        else printf("Bear\n");
    }
    else
        printf("Alien\n");
    return 0;
}
