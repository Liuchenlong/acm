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
#define eps 1e-8
struct trie
{
    trie *next[26];
    trie()
    {
        memset(next,NULL,sizeof(next));
    }
};
void insert(trie *root,string str)
{
    trie *p=root;
    for(int i=0;i<str.length();i++)
    {
        int k=str[i]-'A';
        if(p->next[k]==NULL)p->next[k]=new trie();
        p=p->next[k];
    }
}
int cal(trie *root)
{
    int ans=1;
    for(int i=0;i<26;i++)
    {
        if(root->next[i]!=NULL)
            ans+=cal(root->next[i]);
    }
    return ans;
}
void deletenode(trie *root)
{
    if(root==NULL)
        return ;
    for(int i=0;i<26;i++)
    {
        if(root->next[i]!=NULL)
            deletenode(root->next[i]);
    }
    delete(root);
}
trie *root[4];
string str[8];
int state[4];
int n,m;
int maxn;
map<int,int>mp;
void dfs(int pos,int mask)
{
    if(pos==m)
    {
        if(mask!=((1<<n)-1))
            return ;
        for(int i=0;i<m;i++){
            deletenode(root[i]);
            root[i]=new trie();
            }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(state[i]&(1<<j)){
                insert(root[i],str[j]);}
            }
        }
        int num=0;
        for(int i=0;i<m;i++)
            num+=cal(root[i]);
        mp[num]++;
        maxn=max(maxn,num);
    }
    else
    {
        for(int i=1;i<(1<<n);i++)
        {
            if(i&mask)
                ;
            else
            {
                state[pos]=i;
                dfs(pos+1,mask|i);
            }
        }
    }
}
int main()
{
    freopen("D-small-practice.in","r",stdin);
    FILE *fp=fopen("D-small-practice.out","w");
//    freopen("D-small-practice.out","w",stdout);
//    freopen("B-large-practice.in","r",stdin);
//    freopen("B-large-practice.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        printf("%d\n",cas);
        scanf("%d%d",&n,&m);
        maxn=0;
        mp.clear();
        for(int i=0;i<n;i++)
            cin >> str[i];
        dfs(0,0);
        fprintf(fp,"Case #%d: %d %d\n",cas,maxn,mp[maxn]);
    }
    return 0;
}
