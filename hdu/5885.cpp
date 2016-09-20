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
#define eps 1e-8
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

Complex A[1<<21];
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
Complex a[1<<21],b[1<<21];
int main()
{
    int n,m;
    double R;
    while(scanf("%d%d%lf",&n,&m,&R)!=EOF)
    {
        int r=(int)floor(R);
        int N=n+r+r;
        int M=m+r+r;
        int len=1;
        while(len<=N*M)len<<=1;
        len<<=1;
        memset(a,0,sizeof(*a)*len);
        memset(b,0,sizeof(*b)*len);
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)
        {
            double x;
            scanf("%lf",&x);
            a[i*M+j]=Complex(x,0);
        }
        for(int i=-r;i<=r;i++)for(int j=-r;j<=r;j++)
        {
            double d=sqrt(i*i+j*j);
            if(d<R)
                b[(i+r)*M+(j+r)]=Complex(1.0/(d+1),0);
        }
        FFT(a,len,1);
        FFT(b,len,1);
        for(int i=0;i<len;i++)a[i]=a[i]*b[i];
        FFT(a,len,-1);
        double ans=0.0;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)
        {
            ans=max(ans,a[(i+r)*M+j+r].real);
        }
        printf("%.3f\n",ans);
    }
    return 0;
}
