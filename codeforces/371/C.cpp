#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
#define eps 1e-8
struct trie
{
    int num;
    trie *next[2];
    trie()
    {
        num=0;
        memset(next,NULL,sizeof(next));
    }
};
trie *root=new trie();
void insert(long long x)
{
    trie *p=root;
    for(int i=1;i<=19;i++)
    {
        int k=(x%10)%2;
        x/=10;
        if(p->next[k]==NULL)p->next[k]=new trie();
        p=p->next[k];
        p->num++;
    }
}
void del(long long x)
{
    trie *p=root;
    for(int i=1;i<=19;i++)
    {
        int k=(x%10)%2;
        x/=10;
        p=p->next[k];
        p->num--;
    }
}
char str[33];
int qry()
{
    int len=strlen(str);
    trie *p=root;
    for(int i=1;i<=19;i++)
    {
        int k;
        if(i<=len)
        {
            k=str[len-i]-'0';
        }
        else
            k=0;
        if(p->next[k]==NULL)return 0;
        p=p->next[k];
    }
    return p->num;
}
int main()
{
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        char ss[3];
        scanf("%s",ss);
        if(ss[0]=='+')
        {
            long long x;
            scanf("%I64d",&x);
            insert(x);
        }
        if(ss[0]=='-')
        {
            long long x;
            scanf("%I64d",&x);
            del(x);
        }
        if(ss[0]=='?')
        {
            scanf("%s",str);
            printf("%d\n",qry());
        }
    }
    return 0;
}
