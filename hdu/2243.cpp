#include<cstdio>
#include<cmath>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
int tot;
struct trie
{
    int pos;
    bool bad;
    trie *next[26];
    trie *fail;
    trie()
    {
        for(int i=0; i<26; i++)
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
        int nxt=str[k]-'a';
        if(p->next[nxt]==NULL)
            p->next[nxt]=new trie();
        p=p->next[nxt];
    }
    p->bad=1;
}
struct matrix
{
    unsigned long long num[155][155];
} E;
matrix mult(matrix a,matrix b)
{
    matrix c;
    memset(c.num,0,sizeof(c.num));
    for(int k=0; k<tot; k++)
        for(int i=0; i<tot; i++)
            for(int j=0; j<tot; j++)
                c.num[i][j]+=a.num[i][k]*b.num[k][j];
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
int nxt[133][26];
bool bbad[133];
void getfail()
{
    trie *p=root,*son,*tmp;
    queue<trie *>Q;
    for(int i=0; i<26; i++)
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
        for(int i=0; i<26; i++)
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
    for(int i=0; i<tot; i++)for(int j=0; j<26; j++)
        {
            if(bbad[i]||bbad[nxt[i][j]])continue;
            A.num[i][nxt[i][j]]++;
        }
}
char str[15];
unsigned long long qpow(unsigned long long x,int k)
{
    unsigned long long ans=1;
    while(k)
    {
        if(k&1)ans=ans*x;
        k>>=1;
        x*=x;
    }
    return ans;
}
unsigned long long gsum(int x)
{
    if(x==1)
        return 26;
    if(x%2==0)
    {
        long long ans=gsum(x/2);
        return ans*(qpow(26,x/2)+1);
    }
    else
    {
        long long ans=gsum(x/2);
        long long mid=qpow(26,x/2+1);
        return mid+ans*(mid+1);
    }
}
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(A.num,0,sizeof(A.num));
        tot=0;
        memset(bbad,0,sizeof(bbad));
        root=new trie();
        for(int i=0; i<m; i++)
        {
            scanf("%s",str);
            insert(str);
        }
        getfail();
        build();
        tot++;
        for(int i=0;i<tot;i++)E.num[i][i]=1;
        for(int i=0;i<tot;i++)A.num[i][tot-1]=1;
        unsigned long long ans=1+gsum(n);
        A=qpow(A,n);
        for(int i=0;i<tot;i++)
            ans-=A.num[0][i];
        printf("%I64u\n",ans);
    }
    return 0;
}
