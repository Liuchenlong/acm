#include <bits/stdc++.h>

using namespace std;
char tab[10][10];
int num[10][10];
int main()
{
    for(int i=0;i<4;i++)scanf("%s",tab[i]);
    for(int i=0;i<4;i++)for(int j=0;j<4;j++)
    {
        if(tab[i][j]=='#')num[i][j]=1;
    }
    for(int i=0;i<3;i++)for(int j=0;j<3;j++)
    {
        int cnt=num[i][j]+num[i+1][j]+num[i][j+1]+num[i+1][j+1];
        if(cnt==1||cnt==3||cnt==4||cnt==0)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
