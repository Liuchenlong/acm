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
struct trie
{
    int type;
    int vis;
    trie *next[128];
    trie *fail;
    trie()
    {
        for(int i=0; i<128; i++)
            next[i]=NULL;
        fail=NULL;
        type=0;
        vis=0;
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
int tot;
void query(char str[],int pos)
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
            if(tmp->vis!=pos)
            {
                tmp->vis=pos;
                if(tmp->type>0)vs.push_back(tmp->type);
            }
            else
                break;
            tmp=tmp->fail;
        }
    }
    sort(vs.begin(),vs.end());
    if(vs.size())
    {
        printf("web %d:",pos);
        for(int i=0; i<vs.size(); i++)printf(" %d",vs[i]);
        printf("\n");
        tot++;
    }
}
void del(trie *rt)
{
    for(int i=0; i<26; i++)
    {
        if(rt->next[i]==NULL);
        else del(rt->next[i]);
    }
    delete rt;
}
char str[1000000+5];
int main()
{
    root=new trie();
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%s",str);
        insert(str,i);
    }
    getfail();
    int m;
    scanf("%d",&m);
    for(int i=1; i<=m; i++)
    {
        scanf("%s",str);
        query(str,i);
    }
    printf("total: %d\n",tot);
    return 0;
}
