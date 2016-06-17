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

class SumFullSet
{
public :
    string isSumFullSet(vector <int> elements)
    {
        map <int,int>mp;
        int n=elements.size();
        for(int i=0;i<n;i++)
            mp[elements[i]]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int t=elements[i]+elements[j];
                if(mp.find(t)!=mp.end())
                    ;
                else
                    return "not closed";
            }
        }
        return "closed";
    }
};
