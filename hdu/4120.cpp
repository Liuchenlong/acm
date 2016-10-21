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
#define LL long long
#define pii pair<int,int>
int n,k;
int a[1005];
int det[1005];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        vector<pair<int,int> >ans;
        scanf("%d%d",&n,&k);
        for(int i=0; i<=k; i++)
        {
            scanf("%d",&a[i]);
            if(i)
                det[i]=a[i-1]-a[i];
        }
        printf("Case #%d:\n",cas);
        bool flag=true;
        for(int i=1; i<=k; i++)if(a[i]>a[i-1]||(a[i]==a[i-1]&&a[i]>0))
            {
                flag=false;
                break;
            }
        for(int i=2; i<=k; i++)
        {
            if(det[i]<det[i-1])
            {
                n--;
                ans.push_back(make_pair(i-1,det[i-1]-det[i]));
            }
            if(det[i]>det[i-1])
                flag=false;
        }
        if(!flag)
        {
            puts("No Solution");
            continue;
        }
        int resh=det[k];
        int resf=a[k];
        if(n<0||resh<n)
        {
            puts("No Solution");
            continue;
        }
        else if(n==0)
        {
            if(resh==0&&resf==0)
            {
                puts("Unique Solution");
                for(int i=0; i<ans.size(); i++)
                    printf("%d %d\n",ans[i].first,ans[i].second);
            }
            else
            {
                puts("No Solution");
            }
        }
        else
        {
            if(n==1)
            {
                if(resf%resh)
                {
                    puts("No Solution");
                }
                else
                {
                    puts("Unique Solution");
                    for(int i=0; i<ans.size(); i++)
                        printf("%d %d\n",ans[i].first,ans[i].second);
                    printf("%d %d\n",k+resf/resh,resh);
                }
                continue;
            }
            else if(n==2)
            {
                vector<pair<int,int> >ans2;
                for(int l=0; l<=1000; l++)
                {
                    for(int j=1; j<resh; j++)
                    {
                        if(l*j>resf)break;
                        if(resf-l*j>0&&(resf-l*j)%(resh-j)==0)
                        {
                            int oth=(resf-l*j)/(resh-j);
                            if(oth>l)
                                ans2.push_back(make_pair(l,j));
                        }
                    }
                }
                if(ans2.size()==0)
                {
                    puts("No Solution");
                }
                else if(ans2.size()==1)
                {
                    puts("Unique Solution");
                    for(int i=0; i<ans.size(); i++)
                        printf("%d %d\n",ans[i].first,ans[i].second);
                    printf("%d %d\n",k+ans2[0].first,ans2[0].second);
                    printf("%d %d\n",k+(resf-ans2[0].first*ans2[0].second),resh-ans2[0].second);
                }
                else
                {
                    puts("Multiple Solutions");
                }
            }
            else
            {
                int minf=0;
                for(int i=0; i<n; i++)
                    minf+=i;
                if(resf==minf||(resf==minf+1&&resh==n))
                {
                    puts("Unique Solution");
                    for(int i=0; i<ans.size(); i++)
                        printf("%d %d\n",ans[i].first,ans[i].second);
                    printf("%d %d\n",k,resh-n+1);
                    for(int i=1; i<n-1; i++)
                        printf("%d %d\n",k+i,1);
                    if(resf==minf)printf("%d %d\n",k+n-1,1);
                    else printf("%d %d\n",k+n,1);
                }
                else if(resf>minf)
                {
                    puts("Multiple Solutions");
                }
                else
                    puts("No Solution");
            }
        }
    }
    return 0;
}
