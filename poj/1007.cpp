#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
const double pi=acos(-1.0);
struct obj
{
    string str;
    int pos;
    int inv;
    bool operator < (const obj a)const
    {
        if(inv==a.inv)
            return pos<a.pos;
        return inv<a.inv;
    }
};
obj p[505];
int cal(string s)
{
    int len=s.length();
    int sum=0;
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(s[j]<s[i])
                sum++;
        }
    }
    return sum;
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> p[i].str;
        p[i].pos=i;
        p[i].inv=cal(p[i].str);
    }
    sort(p,p+m);
    for(int i=0;i<m;i++)
        cout << p[i].str << endl;
    return 0;
}
