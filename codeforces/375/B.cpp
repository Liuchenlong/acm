#include <bits/stdc++.h>
using namespace std;

char str[1005];
vector<string>vin,vout;
int main()
{
    int len;
    scanf("%d",&len);
    scanf("%s",str);
    bool in=false;
    string tmp="";
    for(int i=0;i<=len;i++)
    {
        if(i==len)
        {
            if(tmp.length())
                vout.push_back(tmp);
            break;
        }
        if(str[i]=='_')
        {
            if(tmp.length())
            {
                if(in)vin.push_back(tmp);
                else vout.push_back(tmp);
                tmp="";
            }
        }
        else if(str[i]=='(')
        {
            if(tmp.length())
            {
                vout.push_back(tmp);
                tmp="";
            }
            in=true;
        }
        else if(str[i]==')')
        {
            if(tmp.length())
            {
                vin.push_back(tmp);
                tmp="";
            }
            in=false;
        }
        else
        {
            tmp=tmp+str[i];
        }
    }
    int ans=0;
    for(int i=0;i<vout.size();i++)ans=max(ans,(int)vout[i].length());
    printf("%d %d\n",ans,vin.size());
    return 0;
}
