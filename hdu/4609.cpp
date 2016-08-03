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
#define eps 1e-12
const double PI = acos(-1.0);
struct Complex
{
    double real, image;
    Complex(double _real, double _image)
    {
        real = _real;
        image = _image;
    }
    Complex(){}
};

Complex operator + (const Complex &c1, const Complex &c2)
{
    return Complex(c1.real + c2.real, c1.image + c2.image);
}

Complex operator - (const Complex &c1, const Complex &c2)
{
    return Complex(c1.real - c2.real, c1.image - c2.image);
}

Complex operator * (const Complex &c1, const Complex &c2)
{
    return Complex(c1.real*c2.real - c1.image*c2.image, c1.real*c2.image + c1.image*c2.real);
}

int rev(int id, int len)
{
    int ret = 0;
    for(int i = 0; (1 << i) < len; i++)
    {
        ret <<= 1;
        if(id & (1 << i)) ret |= 1;
    }
    return ret;
}

Complex A[500000];
void FFT(Complex* a, int len, int DFT)//对a进行DFT或者逆DFT, 结果存在a当中
{
    //Complex* A = new Complex[len]; 这么写会爆栈
    for(int i = 0; i < len; i++)
        A[rev(i, len)] = a[i];
    for(int s = 1; (1 << s) <= len; s++)
    {
        int m = (1 << s);
        Complex wm = Complex(cos(DFT*2*PI/m), sin(DFT*2*PI/m));
        for(int k = 0; k < len; k += m)
        {
            Complex w = Complex(1, 0);
            for(int j = 0; j < (m >> 1); j++)
            {
                Complex t = w*A[k + j + (m >> 1)];
                Complex u = A[k + j];
                A[k + j] = u + t;
                A[k + j + (m >> 1)] = u - t;
                w = w*wm;
            }
        }
    }
    if(DFT == -1) for(int i = 0; i < len; i++) A[i].real /= len, A[i].image /= len;
    for(int i = 0; i < len; i++) a[i] = A[i];
    return;
}
Complex a[300000];
int num[100005];
int cnt[100005];
long long cob[200005];
long long sum[200005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(cnt,0,sizeof(cnt));
        int n;
        scanf("%d",&n);
        int mx=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            cnt[num[i]]++;
            mx=max(mx,num[i]);
        }
        sort(num,num+n);
        int len=1;
        while(len<=mx)len<<=1;
        len<<=1;
        for(int i=0;i<=mx;i++)
        {
            a[i]=Complex(cnt[i],0);
        }
        for(int i=mx+1;i<len;i++)
        {
            a[i]=Complex(0,0);
        }
        FFT(a,len,1);
        for(int i=0;i<len;i++)
            a[i]=a[i]*a[i];
        FFT(a,len,-1);
        for(int i=0;i<=2*mx;i++)
            cob[i]=(long long)(a[i].real+0.5);
        for(int i=0;i<n;i++)
            cob[num[i]+num[i]]--;
        for(int i=0;i<=2*mx;i++)
            cob[i]/=2;
        for(int i=1;i<=2*mx;i++)
            sum[i]=sum[i-1]+cob[i];
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=sum[2*mx]-sum[num[i]];
            ans-=(long long)(n-1-i)*(n-2-i)/2;
            ans-=(n-1);
            ans-=(long long)(n-1-i)*i;
        }
        long long tot=(long long)n*(n-1)*(n-2)/6;
        printf("%.7f\n",(double)ans/tot);
    }
    return 0;
}
