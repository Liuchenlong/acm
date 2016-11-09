#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))
#define eps 1e-12



vector <string>a,b;

char str[100005];
int main()
{
    cin >> str;
    int len=strlen(str);
    string tmp="";
    int flag=0;
    for(int i=0;i<=len;i++)
    {
        if(str[i]==','||str[i]==';'||i==len)
        {
            if(tmp.length()==0)
                b.push_back(tmp);
            else
            {
                if(flag)
                    b.push_back(tmp);
                else if(tmp.length()>1&&tmp[0]=='0')
                    b.push_back(tmp);
                else
                    a.push_back(tmp);
            }
            tmp="";
            flag=0;
            continue;
        }
        else
            tmp=tmp+str[i];

        if(str[i]>='0'&&str[i]<='9')
            ;
        else
            flag=1;
    }
    if(a.size()==0)
       cout << "-\n";
    else
    {
        cout << '\"';
        cout << a[0] ;
        for(int i=1;i<a.size();i++)
            cout << ',' << a[i];
        cout << '\"';
        cout << endl;
    }

    if(b.size()==0)
        cout << "-\n";
    else
    {
        cout << '\"';
        cout << b[0] ;
        for(int i=1;i<b.size();i++)
            cout << ',' << b[i];
        cout << '\"';
        cout << endl;
    }
    return 0;
}
