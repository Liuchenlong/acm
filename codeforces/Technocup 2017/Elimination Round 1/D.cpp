#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
int num[6];
struct obj
{
    pair<int,int>pr;
    int pos;
};
bool cmp(obj a,obj b)
{
    return a.pr<b.pr;
}
int n;
obj node[100005];
int ans[1000005];
int main()
{
    for(int i=0;i<6;i++)scanf("%d",&num[i]);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char str[10];
        scanf("%s",str);
        int len=strlen(str);
        bool flag=false;
        for(int j=0;j<len;j++)
        {
            if(str[j]==',')
            {
                flag=true;
                break;
            }
        }
        int pos;
        if(str[0]=='S')pos=0;
        else if(str[0]=='M')pos=1;
        else if(str[0]=='L')pos=2;
        else if(str[0]=='X')
        {
            if(str[1]=='L')pos=3;
            else if(str[2]=='L')pos=4;
            else pos=5;
        }
        if(flag)
            node[i].pr=make_pair(pos,pos+1);
        else
            node[i].pr=make_pair(pos,pos);
        node[i].pos=i;
    }
    sort(node,node+n,cmp);
    bool ok=true;
    for(int i=0;i<n;i++)
    {
        int a=node[i].pr.first;
        int b=node[i].pr.second;
        if(num[a])
        {
            num[a]--;
            ans[node[i].pos]=a;
        }
        else
        {
            if(num[b])
            {
                num[b]--;
                ans[node[i].pos]=b;
            }
            else
            {
                ok=false;
                break;
            }
        }
    }
    if(ok)
    {
        printf("YES\n");
        for(int i=0;i<n;i++)
        {
            if(ans[i]==0)puts("S");
            if(ans[i]==1)puts("M");
            if(ans[i]==2)puts("L");
            if(ans[i]==3)puts("XL");
            if(ans[i]==4)puts("XXL");
            if(ans[i]==5)puts("XXXL");
        }
    }
    else
        printf("NO\n");
    return 0;
}

