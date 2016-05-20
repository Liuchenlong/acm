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

int main()
{
//    freopen("A-small-practice.in","r",stdin);
//    freopen("A-small-practice.out","w",stdout);
//    freopen("A-large-practice.in","r",stdin);
//    freopen("A-large-practice.out","w",stdout);
//    freopen("data.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        int n;
        scanf("%d",&n);
        set<pair<int,int> >ss;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int num;
            scanf("%d",&num);
            ss.insert(make_pair(-num,i));
            sum+=num;
        }
        vector<string>ans;
        while(ss.size())
        {
            pair<int,int>head=*ss.begin();
            ss.erase(ss.begin());
            pair<int,int>sec=*ss.begin();
            ss.erase(ss.begin());
            int num1=-head.first;
            int num2=-sec.first;
//            printf("%d %d\n",num1,num2);
            string tmp="";
            if(num2*2>sum-1)
            {
                num1--;
                num2--;
                if(num1!=0)
                ss.insert(make_pair(-num1,head.second));
                if(num2!=0)
                ss.insert(make_pair(-num2,sec.second));
                tmp+=('A'+head.second);
                tmp+=('A'+sec.second);
                ans.push_back(tmp);
                sum-=2;
            }
            else
            {

                num1--;
                ss.insert(sec);
                if(num1!=0)
                ss.insert(make_pair(-num1,head.second));
                tmp+=('A'+head.second);
                ans.push_back(tmp);
                sum--;
            }
        }
        printf("Case #%d:",cas);
        for(int i=0;i<ans.size();i++)
            printf(" %s",ans[i].c_str());
        printf("\n");
    }
    return 0;
}
