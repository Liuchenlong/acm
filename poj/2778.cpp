#include<cstdio>
#include<cmath>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
const long long mod=100000;
int to(char ch)
{
    if(ch=='A')return 0;
    if(ch=='C')return 1;
    if(ch=='T')return 2;
    if(ch=='G')return 3;
}
int tot;
struct trie
{
    int pos;
    bool bad;
    trie *next[4];
    trie *fail;
    trie()
    {
        for(int i=0; i<4; i++)
            next[i]=NULL;
        fail=NULL;
        bad=0;
        pos=tot++;
    }
};
trie *root;
void insert(char str[])
{
    int len,k;
    len=strlen(str);
    trie *p=root;
    for(int k=0; k<len; k++)
    {
        int nxt=to(str[k]);
        if(p->next[nxt]==NULL)
            p->next[nxt]=new trie();
        p=p->next[nxt];
    }
    p->bad=1;
}
struct matrix
{
    long long num[155][155];
} E;
matrix mult(matrix a,matrix b)
{
    matrix c;
    memset(c.num,0,sizeof(c.num));
    for(int k=0; k<tot; k++)
        for(int i=0; i<tot; i++)
            for(int j=0; j<tot; j++)
                c.num[i][j]+=a.num[i][k]*b.num[k][j];
    for(int i=0; i<tot; i++)
        for(int j=0; j<tot; j++)
            c.num[i][j]%=mod;
    return c;
}
matrix qpow(matrix x,int t)
{
    matrix b = E;
    while (t > 0)
    {
        if (t & 1)
            b = mult(b,x);
        t = t >> 1 ;
        x = mult(x,x);
    }
    return b;
}
matrix A;
int nxt[133][4];
bool bbad[133];
void getfail()
{
    trie *p=root,*son,*tmp;
    queue<trie *>Q;
    for(int i=0; i<4; i++)
    {
        if(root->next[i]==NULL)
            root->next[i]=root;
        else
        {
            root->next[i]->fail=root;
            Q.push(root->next[i]);
        }
        nxt[0][i]=root->next[i]->pos;
    }
    while(!Q.empty())
    {
        tmp=Q.front();
        Q.pop();
        if(tmp->fail->bad)
            tmp->bad=1;
        if(tmp->bad)
            bbad[tmp->pos]=1;
        for(int i=0; i<4; i++)
        {
            son=tmp->next[i];
            if(son!=NULL)
            {
                son->fail=tmp->fail->next[i];
                Q.push(son);
            }
            else
            {
                tmp->next[i]=tmp->fail->next[i];
            }
            nxt[tmp->pos][i]=tmp->next[i]->pos;
        }
    }
}
void build()
{
    for(int i=0;i<tot;i++)for(int j=0;j<4;j++)
    {
        if(bbad[i]||bbad[nxt[i][j]])continue;
        A.num[i][nxt[i][j]]++;
    }
}
char str[15];
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    root=new trie();
    for(int i=0; i<m; i++)
    {
        scanf("%s",str);
        insert(str);
    }
    getfail();
    build();
    for(int i=0; i<tot; i++)E.num[i][i]=1;
    A=qpow(A,n);
    long long ans=0;
    for(int i=0; i<tot; i++)ans+=A.num[0][i];
    printf("%I64d\n",ans%mod);
    return 0;
}
