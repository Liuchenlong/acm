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
#define LL long long
#define pii pair<int,int>
int hpy,atky,defy;
int hpm,atkm,defm;
int hpc,atkc,defc;
int cal(int ATK,int DEF)
{
    int HP=hpm;
    int need=0;
    int tim=HP/(ATK-defm)+(HP%(ATK-defm)!=0);
    need+=tim*max(0,atkm-DEF);
    return need;
}
int main()
{
    scanf("%d%d%d",&hpy,&atky,&defy);
    scanf("%d%d%d",&hpm,&atkm,&defm);
    scanf("%d%d%d",&hpc,&atkc,&defc);
    int ans=1000000000;
    for(int ATK=max(atky,defm+1);ATK<=200;ATK++)
    {
        for(int DEF=defy;DEF<=150;DEF++)
        {
            int cost=(ATK-atky)*atkc+(DEF-defy)*defc;
            int HP=cal(ATK,DEF);
            cost+=max(HP+1-hpy,0)*hpc;
            ans=min(ans,cost);
        }
    }
    printf("%d\n",ans);
    return 0;
}
