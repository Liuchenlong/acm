#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define eps 1e-12
const double pi=acos(-1.0);
struct cube
{
    int l[3];
    int r[3];
    void input()
    {
        for(int i=0;i<3;i++)scanf("%d",&l[i]);
        for(int i=0;i<3;i++)scanf("%d",&r[i]);
    }
};
cube c[105];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)c[i].input();
        int L[3],R[3];
        for(int i=0;i<3;i++)
        {
            L[i]=c[0].l[i];
            R[i]=c[0].r[i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                L[j]=max(L[j],c[i].l[j]);
                R[j]=min(R[j],c[i].r[j]);
            }
        }
        int ans=1;
        for(int i=0;i<3;i++)
        {
            ans*=max(0,R[i]-L[i]);
        }
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
