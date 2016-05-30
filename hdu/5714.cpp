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

int suml[50005];
int sumr[50005];
//vector<pair<int,int> >vecl,vecr;
pair<int,int>vecl[20005],vecr[20005];
vector<int>vec;
int n;
int pos[3000005];
int h[50005];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        memset(suml,0,sizeof(suml));
        memset(sumr,0,sizeof(sumr));
        memset(pos,0,sizeof(pos));
        scanf("%d",&n);
        int v1=0;
        int v2=0;
        for(int i=0; i<n; i++)
        {
            int x,y,z,d;
            scanf("%d%d%d%d",&x,&y,&z,&d);
            x+=1000000;
            y+=1000000;
            int L,R;
            L=y-z;
            R=x+z;
            if(L>R)
                continue;
            else
            {
                if(d==1)
                {
                    vecr[v1++]=make_pair(L,-1);
                    vecr[v1++]=make_pair(R,1);
                }
                else
                {
                    vecl[v2++]=make_pair(L,-1);
                    vecl[v2++]=make_pair(R,1);
                }
            }
        }
        sort(vecl,vecl+v2);
        sort(vecr,vecr+v1);
        int pos1=0,pos2=0;
        int hnum=0;
        for(int i=0; i<v2; i++)
        {
            h[hnum++]=vecl[i].first;
        }
        for(int i=0; i<v1; i++)
        {
            h[hnum++]=vecr[i].first;
        }
        sort(h,h+hnum);
        int sz=unique(h,h+hnum)-h;
        int hd=0;
        for(int i=0; i<sz; i++)
        {
            pos[h[i]]=++hd;
        }
        int num1=0,num2=0;
        int siz1=v2;
        int siz2=v1;
        for(int i=0; i<=hd; i++)
        {
            while(pos1<siz1&&i>=pos[vecl[pos1].first]&&vecl[pos1].second==-1)
            {
                num1++;
                pos1++;
            }
            suml[i]=num1;
            while(pos1<siz1&&i>=pos[vecl[pos1].first]&&vecl[pos1].second==1)
            {
                num1--;
                pos1++;
            }
            while(pos2<siz2&&i>=pos[vecr[pos2].first]&&vecr[pos2].second==-1)
            {
                num2++;
                pos2++;
            }
            sumr[i]=num2;
            while(pos2<siz2&&i>=pos[vecr[pos2].first]&&vecr[pos2].second==1)
            {
                num2--;
                pos2++;
            }
        }
        int ans=0;
        int maxr=0;
        for(int i=0; i<=hd; i++)
        {
            maxr=max(maxr,sumr[i]);
            ans=max(ans,maxr+suml[i]);
        }
        int maxl=0;
        for(int i=hd; i>=0; i--)
        {
            maxl=max(maxl,suml[i]);
            ans=max(ans,maxl+sumr[i]);
        }
        printf("Case #%d:\n",cas);
        printf("%d\n",ans);
    }
    return 0;
}
