#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
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
void insert(int x)
{
    trie *p=root;
    int bit=1<<30;
    while(bit)
    {
        int k=((bit&x)>=1);
        if(p->next[k]==NULL)p->next[k]=new trie();
        p=p->next[k];
        p->num++;
        bit>>=1;
    }
}
void delet(int x)
{
    trie *p=root;
    int bit=1<<30;
    while(bit)
    {
        int k=((bit&x)>=1);
        p=p->next[k];
        p->num--;
        bit>>=1;
    }
}
int qry(int x)
{
    int bit=(1<<30);
    int ans=x;
    trie *p=root;
    bool flag=false;
    while(bit)
    {
        int k=((bit&x)>=1);
        if(k==1)
        {
            if(p->next[0]==NULL||p->next[0]->num==0)
            {
                if(flag==0)
                    break;
                else
                {
                    p=p->next[1];
                    ans^=bit;
                }
            }
            else
            {
                p=p->next[0];
            }
        }
        else
        {
            if(p->next[1]==NULL||p->next[1]->num==0)
            {
                p=p->next[0];
            }
            else
            {
                flag=true;
                p=p->next[1];
                ans^=bit;
            }
        }
        bit>>=1;
    }
    return ans;
}
int main()
{
    insert(0);
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        char str[3];
        int x;
        scanf("%s%d",str,&x);
        if(str[0]=='+')
            insert(x);
        if(str[0]=='-')
            delet(x);
        if(str[0]=='?')
            printf("%d\n",qry(x));
    }
    return 0;
}
