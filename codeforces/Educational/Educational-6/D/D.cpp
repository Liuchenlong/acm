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
int n,m;
long long a[2005];
long long b[2005];
int type;
long long det;
long long chosa,chosb;
long long suma,sumb;
vector <long long>veca,vecb;
void solve(long long num[],long long sum,int n,int &a1,int &a2)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(num[i]+num[j]==sum)
            {
                a1=i+1;
                a2=j+1;
                return ;
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%I64d",&a[i]);
        det+=a[i];
        suma+=a[i];
    }
    scanf("%d",&m);
    for(int i=0; i<m; i++)
    {
        scanf("%I64d",&b[i]);
        det-=b[i];
        sumb+=b[i];
    }
    det=abs(det);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(abs((suma-a[i]+b[j])-(sumb-b[j]+a[i]))<det)
            {
                type=1;
                chosa=a[i];
                chosb=b[j];
                det=abs((suma-a[i]+b[j])-(sumb-b[j]+a[i]));
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
            veca.push_back(a[i]+a[j]);
    }
    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<m;j++)
            vecb.push_back(b[i]+b[j]);
    }
    sort(veca.begin(),veca.end());
    sort(vecb.begin(),vecb.end());
    int siza=veca.size();
    int sizb=vecb.size();
    for(int i=0;i<siza;i++)
    {
        long long d=sumb+veca[i]-(suma-veca[i]);
        d/=2;
        int pos=lower_bound(vecb.begin(),vecb.end(),d)-vecb.begin();
        if(pos>=0&&pos<sizb)
        {
            if(abs((suma-veca[i]+vecb[pos])-(sumb+veca[i]-vecb[pos]))<det)
            {
                type=2;
                chosa=veca[i];
                chosb=vecb[pos];
                det=abs((suma-veca[i]+vecb[pos])-(sumb+veca[i]-vecb[pos]));
            }
        }
        if(pos-1>=0&&pos-1<sizb)
        {
            if(abs((suma-veca[i]+vecb[pos-1])-(sumb+veca[i]-vecb[pos-1]))<det)
            {
                type=2;
                chosa=veca[i];
                chosb=vecb[pos-1];
                det=abs((suma-veca[i]+vecb[pos-1])-(sumb+veca[i]-vecb[pos-1]));
            }
        }
    }
    if(type==0)
    {
        printf("%I64d\n0\n",det);
    }
    else if(type==1)
    {
        printf("%I64d\n1\n",det);
        for(int i=0;i<n;i++)
        {
            if(a[i]==chosa)
            {
                printf("%d ",i+1);
                break;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(b[i]==chosb)
            {
                printf("%d\n",i+1);
                break;
            }
        }
    }
    else
    {
        printf("%I64d\n2\n",det);
        int a1,a2,b1,b2;
        solve(a,chosa,n,a1,a2);
        solve(b,chosb,m,b1,b2);
        printf("%d %d\n%d %d\n",a1,b1,a2,b2);
    }
    return 0;
}
