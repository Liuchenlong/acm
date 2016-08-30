#include <iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
//赤裸裸的模板啊。
const int maxn = 101;
const int INF = (1<<31)-1;
int w[maxn][maxn];
int lx[maxn],ly[maxn]; //顶标
int linky[maxn];
int visx[maxn],visy[maxn];
int slack[maxn];
int nx,ny;
bool find(int x)
{
    visx[x] = true;
    for(int y = 0; y < ny; y++)
    {
        if(visy[y])
            continue;
        int t = lx[x] + ly[y] - w[x][y];
        if(t==0)
        {
            visy[y] = true;
            if(linky[y]==-1 || find(linky[y]))
            {
                linky[y] = x;
                return true;        //找到增广轨
            }
        }
        else if(slack[y] > t)
            slack[y] = t;
    }
    return false;                   //没有找到增广轨（说明顶点x没有对应的匹配，与完备匹配(相等子图的完备匹配)不符）
}
int KM()                //返回最优匹配的值
{
    int i,j;
    memset(linky,-1,sizeof(linky));
    memset(ly,0,sizeof(ly));
    for(i = 0; i < nx; i++)
        for(j = 0,lx[i] = -INF; j < ny; j++)
            if(w[i][j] > lx[i])
                lx[i] = w[i][j];
    for(int x = 0; x < nx; x++)
    {
        for(i = 0; i < ny; i++)
            slack[i] = INF;
        while(true)
        {
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
            if(find(x))                     //找到增广轨，退出
                break;
            int d = INF;
            for(i = 0; i < ny; i++)          //没找到，对l做调整(这会增加相等子图的边)，重新找
            {
                if(!visy[i] && d > slack[i])
                    d = slack[i];
            }
            for(i = 0; i < nx; i++)
            {
                if(visx[i])
                    lx[i] -= d;
            }
            for(i = 0; i < ny; i++)
            {
                if(visy[i])
                     ly[i] += d;
                else
                     slack[i] -= d;
            }
        }
    }
    int result = 0;
    for(i = 0; i < ny; i++)
    if(linky[i]>-1)
        result += w[linky[i]][i];
    return result;
}
int num[1000005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k,m;
        scanf("%d%d%d",&n,&k,&m);
        nx=ny=26;
        for(int i=0;i<n;i++)
        {
            char str[3];
            scanf("%s",str);
            num[i]=str[0]-'A';
        }
        for(int i=0;i<m;i++)
        {
            memset(w,0,sizeof(w));
            for(int j=0;j<n;j++)
            {
                char str[3];
                scanf("%s",str);
                w[str[0]-'A'][num[j]]++;
            }
            printf("%.4f\n",1.0*KM()/n);
        }
    }
    return 0;
}
