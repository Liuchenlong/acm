#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
const long long mod=1e9+7;
const int MAXN=1005;
int a[MAXN][MAXN];//增广矩阵
int x[MAXN];//解集
void output(int equ,int var)
{
    for(int i=0;i<equ;i++)
    {
        for(int j=0;j<=var;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
int gauss(int equ,int var)
{
    int i,j,k;
    int max_r;// 当前这列绝对值最大的行.
    int col;//当前处理的列
    //转换为阶梯阵.
    col=0; // 当前处理的列
    for(k = 0; k < equ && col < var; k++,col++)
    {
        // 枚举当前处理的行.
        // 找到该col列元素绝对值最大的那行与第k行交换.(为了在除法时减小误差)
        max_r=k;
        for(i=k+1; i<equ; i++)
        {
            if((a[i][col])>(a[max_r][col]))
                max_r=i;
        }
        if(max_r!=k)
        {
            // 与第k行交换.
            for(j=k; j<var+1; j++)
                swap(a[k][j],a[max_r][j]);
        }
        if((a[k][col])==0)
        {
            // 说明该col列第k行以下全是0了，则处理当前行的下一列.
            k--;
            continue;
        }
        for(i=k+1; i<equ; i++)
        {
            // 枚举要删去的行.
            if((a[i][col])>0)
            {
                for(j=var; j>=col; j--)
                {
                    a[i][j]^=a[k][j]*(a[i][col]/a[k][col]);
                }
            }
        }
    }
    if(k<var)//无穷解,返回自由变元个数//会改变解的顺序
    {
        for(int i=0; i<equ; i++)
        {
            if(a[i][i]!=0)
                continue;
            else
            {
                int flag=0;
                for(int j=i+1; j<var; j++)
                {
                    if(a[i][j]!=0)
                    {
                        flag=1;
                        for(int k=0; k<=i; k++)
                        {
                            swap(a[k][i],a[i][j]);
                        }
                        break;
                    }
                }
                if(!flag)
                    return var-i;
            }
        }
        return var-equ;
    }
    return 0;
}

ll qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int vis[100000], prime[10000];
int cnt;
void init() {
    memset(vis, 0, sizeof vis);
    cnt = 0;
    for(int i = 2; i <= 2000; i++) {
        if(!vis[i]) prime[cnt++] = i;
        for(int j = 0; j < cnt && i * prime[j] <= 2000; j++) {
            vis[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
}
int n;
long long v[303];
int main() {
    init();
    int equ=cnt,var=0;
    int _T; scanf("%d", &_T); int cas = 1;
    while(_T--) {
        scanf("%d", &n);
        var=n;
        for(int i = 0; i < n; i++) {
            ll x; scanf("%I64d", &x);
            v[i] = x;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < cnt; j++) {
                bool flag = false;
                ll k = v[i], w = prime[j];
                while(k % w == 0) flag ^= 1, k /= w;
                a[j][i] = flag;
            }
        }
        ll ans = gauss(equ,var);
        printf("Case #%d:\n", cas++);
        if(ans == -1) printf("0\n");
        else printf("%I64d\n", (qpow(2ll, ans) - 1 + mod) % mod);
    }
    return 0;
}
