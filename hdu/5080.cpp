#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
const double eps=1e-8;
bool zero(double x)
{
    return fabs(x)<=eps;
}
int n,m,c;
double x[55],y[55];
int mat[55][55];
long long ans;
double nx[55],ny[55];
int nxt[55];
bool vis[55];
long long qpow(long long x,long long k,long long mod)
{
    long long ans=1;
    while(k)
    {
        if(k&1)ans=ans*x%mod;
        k>>=1;
        x=x*x%mod;
    }
    return ans;
}
void rot()
{
    int res=0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0)
            {
                nx[j]=x[j];
                ny[j]=y[j];
            }
            if(i==1)
            {
                nx[j]=y[j];
                ny[j]=-x[j];
            }
            if(i==2)
            {
                nx[j]=-x[j];
                ny[j]=-y[j];
            }
            if(i==3)
            {
                nx[j]=-y[j];
                ny[j]=x[j];
            }
        }
        bool flag=true;
        for(int j=0; j<n; j++)
        {
            bool tmpflag=false;
            for(int k=0; k<n; k++)
            {
                if(zero(x[j]-nx[k])&&zero(y[j]-ny[k]))
                {
                    tmpflag=true;
                    nxt[k]=j;
                }
            }
            if(!tmpflag)
            {
                flag=false;
                break;
            }
        }
        for(int j=0; j<n; j++)for(int k=0; k<n; k++)
            {
                if(mat[j][k]&&mat[nxt[j]][nxt[k]]==0)
                {
                    flag=false;
                    break;
                }
            }
        if(flag)
        {
            res++;
            memset(vis,0,sizeof(vis));
            int cnt=0;
            for(int j=0; j<n; j++)
            {
                if(vis[j])continue;
                cnt++;
                int nt=nxt[j];
                while(vis[nt]==0)
                {
                    vis[nt]=1;
                    nt=nxt[nt];
                }
            }
            ans+=qpow(c,cnt,mod);
            ans%=mod;
        }
    }
    ans=ans*qpow(res,mod-2,mod)%mod;
    printf("%I64d\n",ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        memset(mat,0,sizeof(mat));
        scanf("%d%d%d",&n,&m,&c);
        double ox=0,oy=0;
        for(int i=0; i<n; i++)
        {
            scanf("%lf%lf",&x[i],&y[i]);
            ox+=x[i];
            oy+=y[i];
        }
        ox/=n;
        oy/=n;
        for(int i=0; i<n; i++)
        {
            x[i]-=ox;
            y[i]-=oy;
        }
        for(int i=0; i<m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            a--;
            b--;
            mat[a][b]=1;
            mat[b][a]=1;
        }
        rot();
    }
    return 0;
}
