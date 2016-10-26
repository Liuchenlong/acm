int f(char ch)
{
    if(ch=='A')return 0;
    if(ch=='T')return 1;
    if(ch=='C')return 2;
    if(ch=='G')return 3;
}
struct trie
{
    int nxt[4];
    int fail;
    bool bad;
    trie()
    {
        for(int i=0;i<4;i++)nxt[i]=-1;
        fail=-1;
        bad=false;
    }
};
trie node[1005];
int tot;
void insert(char str[])
{
    int len,k;
    len=strlen(str);
    int rt=0;
    for(k=0;k<len;k++)
    {
        int nt=f(str[k]);
        if(node[rt].nxt[nt]==-1)
            node[rt].nxt[nt]=++tot;
        rt=node[rt].nxt[nt];
    }
    node[rt].bad=true;
}
void getfail()
{
    int rt=0,son,tmp;
    queue<int>Q;
    for(int i=0;i<4;i++)
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
            node[tmp].bad=true;
        for(int i=0;i<4;i++)
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
