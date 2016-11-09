#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<iomanip>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8

bool cmp(string a,string b)
{
    return a+b<b+a;
}
vector <string>vec;
int main()
{
    int n;
    cin >> n ;
    for(int i=0;i<n;i++)
    {
        string str;
        cin >> str;
        vec.push_back(str);
    }
    sort(vec.begin(),vec.end(),cmp);
    for(int i=0;i<n;i++)
        cout << vec[i];
    cout << endl;
    return 0;
}
