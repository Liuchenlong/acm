#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
int n;
long long k,x;
long long num[200005];
struct obj
{
    long long a;
    int pos;
    bool operator < (const obj b)const
    {
        if(abs(a)==abs(b.a))
            return pos<b.pos;
        return abs(a)<abs(b.a);
    }
};
obj node[200005];
long long ans[200005];
bool cmp(int a,int b)
{
    return node[a]<node[b];
}
int main()
{
    scanf("%d%I64d%I64d",&n,&k,&x);
    vector<int>fu;
    vector<int>zero;
    vector<int>zheng;
    for(int i=0; i<n; i++)
    {
        scanf("%I64d",&num[i]);
        node[i].a=num[i];
        node[i].pos=i;
        if(num[i]==0)zero.push_back(i);
        else if(num[i]<0)fu.push_back(i);
        else zheng.push_back(i);
    }
    sort(fu.begin(),fu.end(),cmp);
    sort(zheng.begin(),zheng.end(),cmp);
    bool up=false;
    if(zero.size()>k)
    {
        for(int i=0; i<n; i++)
            printf("%I64d ",num[i]);
        puts("");
    }
    else
    {
        if(fu.size()%2==0)
        {
            if(zero.size()>0)
            {
                node[zero[0]].a-=x;
                for(int i=1; i<zero.size(); i++)
                    node[zero[i]].a+=x;
                k-=zero.size();
            }
            else
            {
                if((fu.size()>0&&x*k+node[fu[0]].a>0)&&((zheng.size()>0&&x*k>node[zheng[0]].a)))
                {
                    int t1=(abs(node[fu[0]].a))/x+1;
                    int t2=(node[zheng[0]].a)/x+1;
                    if(t1<t2)
                    {
                        k-=t1;
                        node[fu[0]].a+=x*t1;
                    }
                    else if(t1==t2)
                    {
                        if(abs(node[fu[0]].a+x*t1)>abs(node[zheng[0]].a-x*t2))
                        {
                            k-=t1;
                            node[fu[0]].a+=x*t1;
                        }
                        else
                        {
                            k-=t2;
                            node[zheng[0]].a-=x*t2;
                        }
                    }
                    else
                    {
                        k-=t2;
                        node[zheng[0]].a-=x*t2;
                    }
                }
                else if(fu.size()>0&&x*k+node[fu[0]].a>0)
                {
                    int t=(abs(node[fu[0]].a))/x+1;
                    k-=t;
                    node[fu[0]].a+=x*t;
                }
                else if(zheng.size()>0&&x*k>node[zheng[0]].a)
                {
                    int t=(node[zheng[0]].a)/x+1;
                    k-=t;
                    node[zheng[0]].a-=x*t;
                }
                else if(fu.size()>0&&x*k+node[fu[0]].a==0)
                {
                    k=0;
                    node[fu[0]].a=0;
                }
                else if(zheng.size()>0&&x*k==node[zheng[0]].a)
                {
                    k=0;
                    node[zheng[0]].a=0;
                }
                else
                {
                    up=true;
                }
            }
            multiset<obj>s;
            for(int i=0; i<n; i++)
                s.insert(node[i]);
            while(k--)
            {
                obj head=*s.begin();
                s.erase(s.begin());
                if(up)
                {
                    if(head.a>0)head.a-=x;
                    else head.a+=x;
                }
                else
                {
                    if(head.a>0)head.a+=x;
                    else head.a-=x;
                }
                s.insert(head);
            }
            while(!s.empty())
            {
                obj head=*s.begin();
                ans[head.pos]=head.a;
                s.erase(s.begin());
            }
            for(int i=0; i<n; i++)
                printf("%I64d ",ans[i]);
            puts("");
        }
        else
        {
            for(int i=0; i<zero.size(); i++)
            {
                node[zero[i]].a+=x;
                k--;
            }
            multiset<obj>s;
            for(int i=0; i<n; i++)
                s.insert(node[i]);
            while(k--)
            {
                obj head=*s.begin();
                s.erase(s.begin());
                if(up)
                {
                    if(head.a>0)head.a-=x;
                    else head.a+=x;
                }
                else
                {
                    if(head.a>0)head.a+=x;
                    else head.a-=x;
                }
                s.insert(head);
            }
            while(!s.empty())
            {
                obj head=*s.begin();
                ans[head.pos]=head.a;
                s.erase(s.begin());
            }
            for(int i=0; i<n; i++)
                printf("%I64d ",ans[i]);
            puts("");
        }
    }
    return 0;
}
