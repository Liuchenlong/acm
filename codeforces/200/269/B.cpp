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
int n;
vector<int> g[2100];

int main()
{

    cin >> n;

    for(int i = 1 ; i <= n ; i++)
    {
        int lv;
        cin >> lv;
        g[lv].PB(i);
    }

    LL tot=1;
    int lala=0;

    int ok=0;
    for(int i = 1 ; i <= 2000 ; i++)
    {
        if(g[i].size())
        {
            tot *= g[i].size();

            if(g[i].size() >= 2) lala++;
            if(tot >= 3)
            {
                ok=1;
            }
        }
    }

    if(!ok)
        printf("NO\n");
    else
    {
        printf("YES\n");

        vector<int> ans[10];

        if(lala == 1)
        {
            for(int i = 1 ; i <= 2000 ; i++)
            {
                if(g[i].size() >= 3)
                {
                    ans[0].PB(g[i][0]),ans[0].PB(g[i][1]),ans[0].PB(g[i][2]);
                    ans[1].PB(g[i][0]),ans[1].PB(g[i][2]),ans[1].PB(g[i][1]);
                    ans[2].PB(g[i][2]),ans[2].PB(g[i][0]),ans[2].PB(g[i][1]);

                    for(int j = 3 ; j < g[i].size() ; j++)
                        ans[0].PB(g[i][j]),ans[1].PB(g[i][j]),ans[2].PB(g[i][j]);
                }
                else if(g[i].size())
                    ans[0].PB(g[i][0]),ans[1].PB(g[i][0]),ans[2].PB(g[i][0]);
            }
        }
        else
        {
            int cnt=1;
            for(int i = 1 ; i <= 2000 ; i++)
            {
                for(int j = 0 ; j < g[i].size() ; j++)
                {
                    ans[0].PB(g[i][j]);
                }

                for(int j = g[i].size()-1 ; j>=0 ; j--)
                    ans[1].PB(g[i][j]);

                if(g[i].size() >= 2)
                {
                    if(cnt)
                    {
                        for(int j = 0 ; j < g[i].size() ; j++)
                            ans[2].PB(g[i][j]);
                        cnt=0;
                    }
                    else
                    {
                        for(int j = g[i].size()-1 ; j>=0 ; j--)
                            ans[2].PB(g[i][j]);
                        cnt=1;
                    }
                }
                else if(g[i].size())
                    ans[2].PB(g[i][0]);
            }
        }
        for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0 ; j < ans[i].size() ; j++)
                printf("%d ",ans[i][j]);
            puts("");
        }
    }

    return 0;
}
