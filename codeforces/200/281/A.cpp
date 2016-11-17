#include<stdio.h>
#include<math.h>
#include<cmath>
#include<vector>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) (a<b?a:b)
#define ll long long
#define INF 9223372036854775807
struct man
{
    char nam[55];
    int num;
    int tim=-1;
} m[222];
char namh[55];
char nama[55];
bool cmp(man a,man b)
{
    return a.tim<b.tim;
}
int main()
{
    scanf("%s",namh);
    scanf("%s",nama);
    for(int i=1; i<=99; i++)
    {
        strcpy(m[i].nam,namh);
        strcpy(m[i+101].nam,nama);
        m[i].num=i;
        m[i+101].num=i;
    }
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int t;
        char ch1;
        int nu;
        char ch2;
        scanf("%d %c %d %c",&t,&ch1,&nu,&ch2);
        if(ch1=='a')
        {
            if(ch2=='r'&&m[101+nu].tim<=0)
            {
                m[101+nu].tim=t;
            }
            else if(ch2=='y'&&m[nu+101].tim<=0)
            {
                if(m[101+nu].tim==0)
                {
                    m[101+nu].tim=t;
                }
                else m[101+nu].tim++;
            }
        }
        else if(ch1=='h')
        {
            if(ch2=='r'&&m[nu].tim<=0)
            {
                m[nu].tim=t;
            }
            else if(ch2=='y'&&m[nu].tim<=0)
            {
                if(m[nu].tim==0)
                {
                    m[nu].tim=t;
                }
                else m[nu].tim++;
            }
        }
    }
    sort(m,m+222,cmp);
    for(int i=0; i<222; i++)
    {
        if(m[i].tim>0)
        {
            printf("%s %d %d\n",m[i].nam,m[i].num,m[i].tim);
        }
    }
    return 0;
}
