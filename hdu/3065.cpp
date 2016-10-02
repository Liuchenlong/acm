#include<stdio.h>
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
string ss[1005];
int cnt[1005];
struct trie
{
    int type;
    trie *next[128];
    trie *fail;
    trie()
    {
        for(int i=0; i<128; i++)
            next[i]=NULL;
        fail=NULL;
        type=0;
    }
};
trie *root;
void insert(char str[],int pos)
{
    int len,k;
    len=strlen(str);
    trie *p=root;
    for(int k=0; k<len; k++)
    {
        int nxt=str[k];
        if(p->next[nxt]==NULL)
            p->next[nxt]=new trie();
        p=p->next[nxt];
    }
    p->type=pos;
}
void getfail()
{
    trie *p=root,*son,*tmp;
    queue<trie *>Q;
    Q.push(p);
    while(!Q.empty())
    {
        tmp=Q.front();
        Q.pop();
        for(int i=0; i<128; i++)
        {
            son=tmp->next[i];
            if(son!=NULL)
            {
                if(tmp==root)
                    son->fail=root;
                else
                {
                    p=tmp->fail;
                    while(p)
                    {
                        if(p->next[i])
                        {
                            son->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(p==NULL)
                        son->fail=root;
                }
                Q.push(son);
            }
        }
    }
}
void query(char str[])
{
    vector<int>vs;
    int len,ans=0;
    len=strlen(str);
    trie *p=root,*tmp;
    for(int i=0; i<len; i++)
    {
        int nxt=str[i];
        while(p->next[nxt]==NULL&&p!=root)p=p->fail;
        p=p->next[nxt];
        if(p==NULL)p=root;
        tmp=p;
        while(tmp!=root)
        {
            if(tmp->type)
            {
                cnt[tmp->type]++;
            }
            tmp=tmp->fail;
        }
    }
}
void del(trie *rt)
{
    for(int i=0; i<128; i++)
    {
        if(rt->next[i]==NULL);
        else del(rt->next[i]);
    }
    delete rt;
}
char str[2000000+5];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(cnt,0,sizeof(cnt));
        root=new trie();
        for(int i=1; i<=n; i++)
        {
            scanf("%s",str);
            ss[i]=string(str);
            insert(str,i);
        }
        getfail();
        scanf("%s",str);
        query(str);
        for(int i=1; i<=n; i++)
        {
            if(cnt[i])
                printf("%s: %d\n",ss[i].c_str(),cnt[i]);
        }
        del(root);
    }
    return 0;
}
