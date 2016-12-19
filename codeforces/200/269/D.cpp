#pragma comment(linker, "/STACK:1024000000,1024000000")
#include "iostream"
#include "cstring"
#include "algorithm"
#include "cmath"
#include "cstdio"
#include "sstream"
#include "queue"
#include "vector"
#include "string"
#include "stack"
#include "cstdlib"
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


int next[500000+100];
string pat,text; //模式串，文本串
LL pats[200000+100],txts[200000+100];
int n,w;
int cnt;

void getnext()
{
    clr(next , 0);
    for(int i = 1 ; i < w-1 ; i++)
    {
        int j = i;
        while(j)
        {
            j = next[j];
            if(pats[i] == pats[j])
            {
                next[i+1]=j+1;
                break;
            }
        }
    }
}

void kmp()
{
    cnt=0;
    getnext();

    for(int i = 0 , j = 0 ; i < n-1 ; i++)
    {
        if(j < w-1 && txts[i] == pats[j])
            j++;
        else
        {
            while(j)
            {
                j = next[j];
                if(txts[i] == pats[j])
                {
                    j++;
                    break;
                }
            }
        }

        if(j == w-1) cnt++;
        //cout << i-j+1 << endl;  这是输出匹配位置

    }
    cout << cnt << endl;
}

LL a[200000+100];
LL b[200000+100];

int main()
{
    cin >> n >> w;


    for(int i = 0 ; i < n ; i++)
        cin >> a[i];

    for(int i = 0 ; i < n-1;  i++ )
        txts[i] = a[i+1]-a[i];

    for(int j = 0 ; j < w ; j++)
        cin >> b[j];

    for(int j = 0 ; j < w-1 ; j++)
        pats[j] = b[j+1]-b[j];

    if(w == 1)
    {
        cout << n << endl;
        return 0;
    }


    kmp();

    return 0;
}
