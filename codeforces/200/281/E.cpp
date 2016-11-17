#include<bits/stdc++.h>

using namespace std;
long long cnt[77];
int main()
{
    long long t,a,b;
    scanf("%I64d%I64d%I64d",&t,&a,&b);
    if(t==1)
    {
        if(a==1&&b==1)
            puts("inf");
        else
        {
            if(a==1)
                puts("0");
            else
            {
                long long tmp=b;
                while(tmp%a==0)
                {
                    tmp/=a;
                }
                if(tmp==1&&b>a)
                {
                    puts("1");
                    return 0;
                }
                else
                {
                    int ans=0;
                    if(a==b)
                        ans++;
                    int pos=0;
                    while(b)
                    {
                        cnt[pos++]=b%a;
                        b/=a;
                    }
                    long long val=1;
                    for(int i=0; i<pos; i++)
                    {
                        if(a/val<cnt[i])
                        {
                            printf("%d\n",ans);
                            return 0;
                        }
                        a-=val*cnt[i];
                        val*=t;
                    }
                    if(a==0)
                    {
                        ans++;
                        printf("%d\n",ans);
                    }
                    else
                        printf("%d\n",ans);
                }
            }
        }

    }
    else
    {
        int ans=0;
        if(a==b)
            ans++;
        if(a<t)
        {
            printf("%d\n",ans);
            return 0;
        }
        int pos=0;
        while(b)
        {
            cnt[pos++]=b%a;
            b/=a;
        }
        long long val=1;
        for(int i=0; i<pos; i++)
        {
            if(a/val<cnt[i])
            {
                printf("%d\n",ans);
                return 0;
            }
            a-=val*cnt[i];
            val*=t;
        }
        if(a==0)
        {
            ans++;
            printf("%d\n",ans);
        }
        else
            printf("%d\n",ans);
    }
    return 0;
}
