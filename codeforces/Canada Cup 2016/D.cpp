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
#define LL long long
#define pii pair<int,int>
int n;
long long t[300005],w[300005];
pair<long long,int>pr[300005];
vector<long long>vec;
multiset<long long>s;
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%I64d%I64d",&t[i],&w[i]);
        vec.push_back(t[i]);
        pr[i]=make_pair(-t[i],i);
    }
    vec.push_back(0);
    sort(pr,pr+n);
    sort(vec.begin(),vec.end());
    int siz=unique(vec.begin(),vec.end())-vec.begin();
    int pos;
    int ans=999999999;
    for(int i=0; i<siz; i++)
    {
        if(vec[i]==t[0])
        {
            pos=i;
            break;
        }
    }
    int head=0;
    long long has=0;
    for(int i=pos; i>=0; i--)
    {
        if(i<pos)
            has+=vec[i+1]-vec[i];
        while(1)
        {
            if(head==n)
                break;
            if(pr[head].second==0)
            {
                head++;
            }
            else
            {
                if(-pr[head].first>vec[i])
                {
                    s.insert(w[pr[head].second]-t[pr[head].second]);
                    head++;
                }
                else
                    break;
            }
        }
        while(1)
        {
            if(s.empty())
                break;
            long long need=*s.begin();
            if(need<has)
            {
                has-=(need+1);
                s.erase(s.begin());
            }
            else
                break;
        }
        ans=min(ans,(int)(s.size()+1));
    }
    printf("%d\n",ans);
    return 0;
}
