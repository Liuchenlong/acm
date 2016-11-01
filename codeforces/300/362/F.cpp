#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
#define pii pair<int,int>

struct trie
{
    int nxt[26];
    int fail;
    int val;
    bool bad;
    trie()
    {
        for(int i=0; i<26; i++)nxt[i]=-1;
        fail=-1;
        val=0;
        bad=false;
    }
};
trie node[205];
int tot;
void insert(char str[],int v)
{
    int len,k;
    len=strlen(str);
    int rt=0;
    for(k=0; k<len; k++)
    {
        int nt=str[k]-'a';
        if(node[rt].nxt[nt]==-1)
            node[rt].nxt[nt]=++tot;
        rt=node[rt].nxt[nt];
    }
    node[rt].val+=v;
    node[rt].bad=true;
}
void getfail()
{
    int rt=0,son,tmp;
    queue<int>Q;
    for(int i=0; i<26; i++)
    {
        if(node[rt].nxt[i]==-1)
            node[rt].nxt[i]=rt;
        else
        {
            node[node[rt].nxt[i]].fail=rt;
            Q.push(node[rt].nxt[i]);
        }
    }
    while(!Q.empty())
    {
        tmp=Q.front();
        Q.pop();
        if(node[node[tmp].fail].bad)
        {
            node[tmp].val+=node[node[tmp].fail].val;
            node[tmp].bad=true;
        }
        for(int i=0; i<26; i++)
        {
            son=node[tmp].nxt[i];
            if(son!=-1)
            {
                node[son].fail=node[node[tmp].fail].nxt[i];
                Q.push(son);
            }
            else
            {
                node[tmp].nxt[i]=node[node[tmp].fail].nxt[i];
            }
        }
    }
}
int n;
long long l;
int v[202];
char str[205];
int siz;
struct matrix
{
    long long num[202][202];
    matrix()
    {
        memset(num,-1,sizeof(num));
    }
}E,A,X;
matrix mult(matrix a,matrix b)
{
    matrix c;
    for(int i=0;i<siz;i++)
    {
        for(int j=0;j<siz;j++)
        {
            for(int k=0;k<siz;k++)if(a.num[i][k]>=0&&b.num[k][j]>=0)
                c.num[i][j]=max(c.num[i][j],a.num[i][k]+b.num[k][j]);
        }
    }
    return c;
}
matrix qpow(matrix x,long long k)
{
    matrix ans=x;
    k--;
    while(k)
    {
        if(k&1)
            ans=mult(ans,x);
        k>>=1;
        x=mult(x,x);
    }
    return ans;
}
void make_matrix()
{
    for(int i=0;i<=tot;i++)for(int j=0;j<=tot;j++)
            A.num[i][j]=-1;
    for(int i=0;i<=tot;i++)
    {
        for(int j=0;j<26;j++)
        A.num[node[i].nxt[j]][i]=node[node[i].nxt[j]].val;
    }
}
int main()
{
    scanf("%d%I64d",&n,&l);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        insert(str,v[i]);
    }
    getfail();
    siz=tot+1;
    make_matrix();
    X.num[0][0]=0;
    for(int i=1;i<=tot;i++)X.num[i][0]=-1;
    A=qpow(A,l);
    matrix ans=mult(A,X);
    long long res=0;
    for(int i=0;i<=tot;i++)res=max(res,ans.num[i][0]);
    printf("%I64d\n",res);
    return 0;
}
