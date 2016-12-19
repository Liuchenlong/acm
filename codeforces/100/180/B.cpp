#include <bits/stdc++.h>
using namespace std;

int t;
int sx,sy;
int ex,ey;
char str[100005];
int main()
{
    scanf("%d",&t);
    scanf("%d%d",&sx,&sy);
    scanf("%d%d",&ex,&ey);
    scanf("%s",str);
    for(int i=0;i<t;i++)
    {
        if(str[i]=='N')
        {
            if(sy<ey)
                sy++;
        }
        if(str[i]=='S')
        {
            if(sy>ey)
                sy--;
        }
        if(str[i]=='E')
        {
            if(sx<ex)
                sx++;
        }
        if(str[i]=='W')
        {
            if(sx>ex)
                sx--;
        }
        if(sx==ex&&sy==ey)
        {
            printf("%d\n",i+1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
