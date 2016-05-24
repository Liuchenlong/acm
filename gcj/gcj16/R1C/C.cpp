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
//    freopen("C-small-practice.in","r",stdin);
//    freopen("C-small-practice.out","w",stdout);
//    freopen("C-large-practice.in","r",stdin);
//    freopen("C-large-practice.out","w",stdout);
//    freopen("data.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        int J,P,S,K;
        scanf("%d%d%d%d",&J,&P,&S,&K);
        if(K>=S)
        {
            printf("Case #%d: %d\n",cas,J*P*S);
            for(int i=0;i<J;i++)for(int j=0;j<P;j++)for(int k=0;k<S;k++)
                printf("%d %d %d\n",i+1,j+1,k+1);
        }
        else
        {
            printf("Case #%d: %d\n",cas,J*P*K);
            for(int i=0;i<J;i++)for(int j=0;j<P;j++)for(int k=0;k<K;k++)
                printf("%d %d %d\n",i+1,j+1,(i+j+k)%S+1);
        }
    }
    return 0;
}
