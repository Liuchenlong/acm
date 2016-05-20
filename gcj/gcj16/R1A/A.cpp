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
//    freopen("A-small-attempt0.in","r",stdin);
//    freopen("A-small-attempt0.out","w",stdout);
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        string str;
        cin >> str;
        string ans;
        ans+=str[0];
        for(int i=1;i<str.length();i++)
        {
            if(str[i]>=ans[0])
                ans=str[i]+ans;
            else
                ans=ans+str[i];
        }
        cout << "Case #" << cas << ": ";
        cout << ans << endl;
    }
    return 0;
}
