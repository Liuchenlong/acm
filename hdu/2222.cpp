struct trie
{
    int cnt;
    trie *next[26];
    trie *fail;
    trie()
    {
        for(int i=0;i<26;i++)
            next[i]=NULL;
        fail=NULL;
        cnt=0;
    }
};
trie *root;
void insert(char str[])
{
    int len,k;
    len=strlen(str);
    trie *p=root;
    for(int k=0;k<len;k++)
    {
        int nxt=str[k]-'a';
        if(p->next[nxt]==NULL)
            p->next[nxt]=new trie();
        p=p->next[nxt];
    }
    p->cnt++;
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
        for(int i=0;i<26;i++)
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
    int len,ans=0;
    len=strlen(str);
    trie *p=root,*tmp;
    for(int i=0;i<len;i++)
    {
        int nxt=str[i]-'a';
        while(p->next[nxt]==NULL&&p!=root)p=p->fail;
        p=p->next[nxt];
        if(p==NULL)p=root;
        tmp=p;
        while(tmp!=root)
        {
            if(tmp->cnt>=0)
            {
                ans+=tmp->cnt;
                tmp->cnt=-1;
            }
            else
                break;
            tmp=tmp->fail;
        }
    }
    printf("%d\n",ans);
}
void del(trie *rt)
{
    for(int i=0;i<26;i++)
    {
        if(rt->next[i]==NULL);
        else del(rt->next[i]);
    }
    delete rt;
}
