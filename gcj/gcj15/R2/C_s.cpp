#include<cstdio>
#include<sstream>
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
vector<long long>vec[22];
char str[20005];
vector<long long>eng,frn;
long long gethash(string s)
{
    long long ans=0;
    for(int i=0;i<s.length();i++)
    {
        ans=ans*27+(s[i]-'a'+1);
    }
    return ans;
}
int main()
{
    freopen("C-small-practice.in","r",stdin);
//    freopen("C-small-practice.out","w",stdout);
    FILE* fp=fopen("C-small-practice.out","w");
//    freopen("A-large-practice.in","r",stdin);
//    freopen("A-large-practice.out","w",stdout);
//    freopen("data.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        int n;
        map<long long,int>mp;
        scanf("%d\n",&n);
        for(int i=0; i<n; i++)
        {
            vec[i].clear();
            gets(str);
            istringstream ssin(str);
            string ss;
            while(ssin>>ss)vec[i].push_back(gethash(ss));
            int siz=unique(vec[i].begin(),vec[i].end())-vec[i].begin();
            for(int j=0;j<siz;j++)
            {
                mp[vec[i][j]]|=(1<<i);
            }
        }
        int ans=1000000;
        for(int i=0; i<(1<<(n-2)); i++)
        {
//            printf("%d\n",i);
            int eng=(i<<2)|(1<<0);
            int frn=((1<<n)-1)^eng;
            int tmp=0;
            for(map<long long,int>::iterator iter=mp.begin();iter!=mp.end();iter++)
            {
                int t=iter->second;
                if(t&eng)if(t&frn)
                    tmp++;
            }
            ans=min(ans,tmp);
        }
        printf("Case #%d:\n",cas);
        fprintf(fp,"Case #%d: %d\n",cas,ans);
    }
    return 0;
}
