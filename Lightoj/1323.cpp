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
int cal(int x,int l,int k)
{
    if(x+k<=l)
        return x+k;
    if(x+k<=l+l)
        return l-(x+k-l);
    return x+k-l-l;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int w,l,n,k;
        scanf("%d%d%d%d",&l,&w,&n,&k);
        vector<pair<int,int> >vec;
        for(int i=0;i<n;i++)
        {
            int x,y;
            char dir[12];
            scanf("%d%d%s",&x,&y,dir);
            int dx,dy;
            if(dir[0]=='N')
                dy=1;
            else
                dy=-1;
            if(dir[1]=='W')
                dx=-1;
            else
                dx=1;
            x=cal(x,l,(dx*k%(2*l)+(2*l))%(2*l));
            y=cal(y,w,(dy*k%(2*w)+(2*w))%(2*w));
            vec.push_back(make_pair(x,y));
        }
        sort(vec.begin(),vec.end());
        printf("Case %d:\n",cas);
        for(int i=0;i<n;i++)
            printf("%d %d\n",vec[i].first,vec[i].second);
    }
    return 0;
}
