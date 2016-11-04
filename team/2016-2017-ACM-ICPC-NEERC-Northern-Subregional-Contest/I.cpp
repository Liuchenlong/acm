#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
int n;
int x[200005],y[200005];
vector<int>vec[2][2];
int val[400005],dx[400005],dy[400005];
int pre[400005];
int main()
{
    freopen("integral.in","r",stdin);
    freopen("integral.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        x[i]=(x[i]%2+2)%2;
        y[i]=(y[i]%2+2)%2;
        vec[(x[i]+2)%2][(y[i]+2)%2].push_back(i);
    }
    int sum=0;
    for(int i=0; i<n; i++)
    {
        int now=i,nxt=(i+1)%n;
        sum+=(x[now]-x[0])*(y[nxt]-y[0])-(x[nxt]-x[0])*(y[now]-y[0]);
    }
    sum=(sum%2+2)%2;
    if(sum%2==1)
    {
        printf("0\n");
        return 0;
    }
    long long ans=0;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            if(vec[i][j].size()==0)continue;
            for(int k=0; k<2*n; k++)
            {
                int now=k%n,nxt=(now+1)%n;
                val[k]=((x[now]*y[nxt]-y[now]*x[nxt])%2+2)%2;
                dy[k]=(y[now]-y[nxt]+2)%2;
                dx[k]=(x[nxt]-x[now]+2)%2;
                pre[k]=val[k]+i*dy[k]+j*dx[k];
                if(k)
                    pre[k]+=pre[k-1];
                pre[k]=(pre[k]%2+2)%2;
            }
            int head=0,tail=0;
            int inzero=0,inone=0;
            for(int k=0; k<vec[i][j].size(); k++)
            {
                int pos=vec[i][j][k];
                while(tail<=(pos-3+n))
                {
                    if(pre[tail]==0)inzero++;
                    else inone++;
                    tail++;
                }
                while(head<=pos)
                {
                    if(pre[head]==0)inzero--;
                    else inone--;
                    head++;
                }
                if(pre[pos]==1)ans+=inone;
                else ans+=inzero;
            }
        }
    }
    printf("%I64d\n",ans/2);
    return 0;
}
