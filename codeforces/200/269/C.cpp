#include<stdio.h>
#include<math.h>
#include<string.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 1000000+100;
const LL INF = 1e18;
const int inf = 522133279;//2139062143;
const int mod = 1000000009;
#define eps 1e-8
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
LL a[1000000];
int main()
{
    LL n;
    LL s = 2;
    LL t = s;
    LL ii = 2;
    a[1] = 2;
    while(t <= 1e12)
    {
        t = s + 3 * ii - 1;
        s = t;
        a[ii] = t;
        ii++;
    }
    while(cin >> n)
    {
        int ans = 0;
        for(int i = 1 ; a[i] <= n && i < ii; i++)
        {

            if((n - a[i]) % 3 == 0)
                ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}
