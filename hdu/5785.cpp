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
#define eps 1e-14
const long long mod=1e9+7;
const int maxn=1000010;
char str[maxn];//原字符串
char tmp[maxn<<1];//转换后的字符串
int Len[maxn<<1];
int pos[maxn<<1];
//转换原始串
long long suml[maxn<<1];
long long sumr[maxn<<1];
int INIT(char *st)
{
    int i,len=strlen(st);
    tmp[0]='@';//字符串开头增加一个特殊字符，防止越界
    for(i=1; i<=2*len; i+=2)
    {
        tmp[i]='#';
        tmp[i+1]=st[i/2];
        pos[i+1]=i/2+1;
    }
    tmp[2*len+1]='#';
    tmp[2*len+2]='$';//字符串结尾加一个字符，防止越界
    tmp[2*len+3]=0;
    return 2*len+1;//返回转换字符串的长度
}
//Manacher算法计算过程
int MANACHER(char *st,int len)
{
    int mx=0,ans=0,po=0;//mx即为当前计算回文串最右边字符的最大值
    for(int i=1; i<=len; i++)
    {
        if(mx>i)
            Len[i]=min(mx-i,Len[2*po-i]);//在Len[j]和mx-i中取个小
        else
            Len[i]=1;//如果i>=mx，要从头开始匹配
        while(st[i-Len[i]]==st[i+Len[i]])
            Len[i]++;
        if(Len[i]+i>mx)//若新计算的回文串右端点位置大于mx，要更新po和mx的值
        {
            mx=Len[i]+i;
            po=i;
        }
        ans=max(ans,Len[i]);
    }
    return ans-1;//返回Len[i]中的最大值-1即为原串的最长回文子串额长度
}
pair<int,int>pr[maxn];
long long delsodd[maxn<<1];
long long delseven[maxn<<1];
int delodd[maxn<<1];
int deleven[maxn<<1];
int main()
{
    while(scanf("%s",str)!=EOF)
    {
        int len=INIT(str);
        MANACHER(tmp,len);
        memset(delsodd,0,sizeof(delsodd));
        memset(delseven,0,sizeof(delseven));
        memset(delodd,0,sizeof(delodd));
        memset(deleven,0,sizeof(deleven));
        memset(suml,0,sizeof(suml));
        memset(sumr,0,sizeof(sumr));
        long long sumodd=0;
        long long sumeven=0;
        int cntodd=0;
        int cnteven=0;
        for(int i=2; i<len; i++)
        {
            if(tmp[i]=='#')
            {
                delseven[i+Len[i]-1]+=pos[i+1];
                deleven[i+Len[i]-1]++;
            }
            else
            {
                delsodd[i+Len[i]-1]+=pos[i];
                delodd[i+Len[i]-1]++;
            }
        }
        int head=0;
        for(int i=2; i<len; i++)
        {
            if(tmp[i]=='#')
            {
                cnteven++;
                sumeven+=pos[i+1];
            }
            else
            {
                cntodd++;
                sumodd+=pos[i];
            }
            if(tmp[i]!='#')
            {
                suml[i]=sumodd*2-(long long)pos[i]*cntodd;
                suml[i]+=sumeven*2-(long long)pos[i]*cnteven-cnteven;
                suml[i]=(suml[i]%mod+mod)%mod;
            }
            sumodd-=delsodd[i];
            sumeven-=delseven[i];
            cntodd-=delodd[i];
            cnteven-=deleven[i];
        }
        memset(delsodd,0,sizeof(delsodd));
        memset(delseven,0,sizeof(delseven));
        memset(delodd,0,sizeof(delodd));
        memset(deleven,0,sizeof(deleven));
        for(int i=2; i<len; i++)
        {
            if(tmp[i]=='#')
            {
                delseven[i-Len[i]+1]+=pos[i-1];
                deleven[i-Len[i]+1]++;
            }
            else
            {
                delsodd[i-Len[i]+1]+=pos[i];
                delodd[i-Len[i]+1]++;
            }
        }
        sumodd=0;
        sumeven=0;
        cntodd=0;
        cnteven=0;
        for(int i=len-1; i>=2; i--)
        {
            if(tmp[i]=='#')
            {
                cnteven++;
                sumeven+=pos[i-1];
            }
            else
            {
                cntodd++;
                sumodd+=pos[i];
            }
            if(tmp[i]!='#')
            {
                sumr[i]=sumodd*2-(long long)pos[i]*cntodd;
                sumr[i]+=sumeven*2-(long long)pos[i]*cnteven+cnteven;
                sumr[i]=(sumr[i]%mod+mod)%mod;
            }

            sumodd-=delsodd[i];
            sumeven-=delseven[i];
            cntodd-=delodd[i];
            cnteven-=deleven[i];
        }
        long long ans=0;
        for(int i=2; i<len; i+=2)
        {
            ans=ans+(suml[i]%mod)*(sumr[i+2]%mod)%mod;
        }
        printf("%I64d\n",ans%mod);
    }
    return 0;
}
