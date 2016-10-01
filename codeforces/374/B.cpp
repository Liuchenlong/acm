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

string str[105];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=n;i++)cin>>str[i];
    int cnt=0;
    int cnt2=0;
    for(int i=0;i<n;i++)
    {
        if(str[i].length()<=str[n].length())cnt++;
        if(str[i].length()<str[n].length())cnt2++;
    }
    int ans=cnt;
    cnt--;
    ans+=cnt/k*5;
    int ans2=cnt2+1;
    ans2+=cnt2/k*5;

    printf("%d %d\n",ans2,ans);
    return 0;
}
