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


multiset<int>ss;
vector<pair<int,int> >ans;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        char oper[22];
        scanf("%s",oper);
        if(oper[0]=='i')
        {
            int dat;
            scanf("%d",&dat);
            ss.insert(dat);
            ans.push_back(make_pair(0,dat));
        }
        else if(oper[0]=='g')
        {
            int dat;
            scanf("%d",&dat);
            while(ss.size()>0&&(*ss.begin()<dat))
            {
                ss.erase(ss.begin());
                ans.push_back(make_pair(2,0));
            }
            if(ss.size()>0)
            {
                if(*ss.begin()==dat)
                {
                    ans.push_back(make_pair(1,dat));
                }
                else
                {
                    ss.insert(dat);
                    ans.push_back(make_pair(0,dat));
                    ans.push_back(make_pair(1,dat));
                }
            }
            else
            {
                ss.insert(dat);
                ans.push_back(make_pair(0,dat));
                ans.push_back(make_pair(1,dat));
            }
        }
        else
        {
            if(ss.size()>0)
            {
                ss.erase(ss.begin());
                ans.push_back(make_pair(2,0));
            }
            else
            {
                ans.push_back(make_pair(0,0));
                ans.push_back(make_pair(2,0));
            }
        }
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
    {
        pair<int,int>pr=ans[i];
        if(pr.first==0)
        {
            printf("insert %d\n",pr.second);
        }
        else if(pr.first==1)
        {
            printf("getMin %d\n",pr.second);
        }
        else
            printf("removeMin\n");
    }
    return 0;
}
