#include <bits/stdc++.h>

using namespace std;
char str[44];
int dx[4]={0,1,0,1};
int dy[4]={0,0,1,1};
int main()
{
    while(scanf("%s",str)!=EOF)
    {
        int n=strlen(str);
        int x=0,y=0;
        int d=1<<(n-1);
        for(int i=0;i<n;i++)
        {
            x+=dx[str[i]-'0']*d;
            y+=dy[str[i]-'0']*d;
            d>>=1;
        }
        printf("%d %d %d\n",n,x,y);
    }
    return 0;
}
