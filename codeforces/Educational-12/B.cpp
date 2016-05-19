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

vector<int>vec;
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<k; i++)
    {
        int t;
        scanf("%d",&t);
        vec.push_back(t);
    }
    int ans=0;
    for(int i=0; i<n; i++)
    {

        for(int j=0; j<m; j++)
        {
            int t;
            scanf("%d",&t);
            for(vector<int>::iterator iter=vec.begin(); iter!=vec.end(); iter++)
            {
                if(*iter==t)
                {
                    ans+=(iter-vec.begin())+1;
                    vec.erase(iter);
                    vec.insert(vec.begin(),t);
                }
            }
        }

    }
    printf("%d\n",ans);
    return 0;
}
