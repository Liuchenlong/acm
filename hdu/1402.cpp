#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
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

Complex A[140000];
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

char numa[50005],numb[50005];
Complex a[140000],b[140000];
int ans[140000];
int main()
{
    while(scanf("%s",numa)!=EOF)
    {
        scanf("%s",numb);
        int lena=strlen(numa);
        int lenb=strlen(numb);
        int sa=0,sb=0;
        while((1<<sa)<lena)sa++;
        while((1<<sb)<lenb)sb++;
        int len=(1<<(max(sa,sb)+1));
        for(int i=0;i<len;i++)
        {
            if(i<lena)
                a[i]=Complex(numa[lena-i-1]-'0',0);
            else
                a[i]=Complex(0,0);
            if(i<lenb)
                b[i]=Complex(numb[lenb-i-1]-'0',0);
            else
                b[i]=Complex(0,0);
        }
        FFT(a,len,1);
        FFT(b,len,1);
        for(int i=0;i<len;i++)
            a[i]=a[i]*b[i];
        FFT(a,len,-1);
        for(int i=0;i<len;i++)
            ans[i]=(int)(a[i].real+0.5);
        for(int i=0;i<len;i++)
        {
            ans[i+1]+=ans[i]/10;
            ans[i]%=10;
        }
        bool flag=false;
        for(int i=len-1;i>=0;i--)
        {
            if(ans[i])
            {
                printf("%d",ans[i]);
                flag=true;
            }
            else if(flag||i==0)
                printf("0");
        }
        printf("\n");
    }
    return 0;
}

