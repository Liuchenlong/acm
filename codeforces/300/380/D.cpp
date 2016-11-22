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
const long long inf=(1LL<<60);
int n,a,b,k;
char str[200005];
vector<pair<int,int> >vec;
int main()
{
    scanf("%d%d%d%d",&n,&a,&b,&k);
    scanf("%s",str+1);
    for(int i=1;i<=n;)
    {
        if(str[i]=='1')
            i++;
        else
        {
            int l=i;
            while(i<=n&&str[i]=='0')i++;
            if(i-l>=b)
            vec.push_back(make_pair(l,i-1));
        }
    }
    int cnt=0;
    for(int i=0;i<vec.size();i++)
    {
        cnt+=(vec[i].second-vec[i].first+1)/b;
    }
    printf("%d\n",cnt-a+1);
    for(int i=0;i<vec.size();i++)
    {
        int l=vec[i].first,r=vec[i].second;
        for(int pos=l+b-1;pos<=r;pos+=b)
        {
            printf("%d ",pos);
            cnt--;
            if(cnt==a-1)
                break;
        }
        if(cnt==a-1)
            break;
    }
    return 0;
}
