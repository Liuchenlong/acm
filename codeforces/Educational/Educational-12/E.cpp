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
bool flag;
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
    int i;
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
int n,k;
long long cal(trie *p)
{
    if(p==NULL)return 0;
    return p->num;
}
long long dfs(trie *p,int bit,int num)
{
    if(p==NULL)return 0;
    if(bit==0)return p->num;
    int id1 = ((num&bit)>=1);//num当前位
    int id2 = ((k&bit)>=1);//k当前位
    if(id1==0&&id2==0)
    {
        return dfs(p->next[0],bit>>1,num)+cal(p->next[1]);
    }
    if(id1==0&&id2==1)
    {
        return dfs(p->next[1],bit>>1,num);
    }
    if(id1==1&&id2==0)
    {
        return dfs(p->next[1],bit>>1,num)+cal(p->next[0]);
    }
    if(id1==1&&id2==1)
    {
        return dfs(p->next[0],bit>>1,num);
    }
}
int a[1000005];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        a[i]^=a[i-1];
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=k)
            ans++;
        int bit=1<<30;
        ans+=dfs(root,bit,a[i]);
        insert(a[i]);
    }
    printf("%I64d\n",ans);
    return 0;
}
