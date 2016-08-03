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
    Complex() {}
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

Complex A[600000];
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
char strA[100005];
char strB[100005];
Complex a[300000];
Complex b[300000];
int cnta[100005];
int cntb[100005];
unsigned long long H[100005];
unsigned long long seedpow[100005];
unsigned long long query(int l,int r)
{
    if(l==0)return H[r];
    return H[r]-H[l-1]*seedpow[r-l+1];
}
int main()
{
    seedpow[0]=1;
    for(int i=1; i<=100000; i++)
        seedpow[i]=seedpow[i-1]*500009;
    int K;
    int cas=0;
    while(scanf("%d",&K),K+1)
    {
        cas++;
        map<unsigned long long,bool>mp;
        scanf("%s",strA);
        scanf("%s",strB);
        int la=strlen(strA);
        int lb=strlen(strB);
        if(lb>la)
        {
            printf("Case %d: 0\n",cas);
            continue;
        }
        H[0]=strA[0]-'a'+1;
        for(int i=1; i<la; i++)
            H[i]=H[i-1]*500009+(strA[i]-'a'+1);
        int ma=1;
        int mb=1;
        while(ma<=la)ma<<=1;
        while(mb<=lb)mb<<=1;
        int len=max(ma,mb)<<1;
        for(int i=0; i<len; i++)
        {
            if(i<la)
            {
                if(strA[i]=='a')
                    a[i]=Complex(1,0);
                else
                    a[i]=Complex(0,0);
            }
            else
                a[i]=Complex(0,0);
            if(i<lb)
            {
                if(strB[lb-1-i]=='a')
                    b[i]=Complex(1,0);
                else
                    b[i]=Complex(0,0);
            }
            else
            {
                b[i]=Complex(0,0);
            }
        }
        FFT(a,len,1);
        FFT(b,len,1);
        for(int i=0; i<len; i++)
            a[i]=a[i]*b[i];
        FFT(a,len,-1);
        for(int i=0; i+lb<=la; i++)
        {
            cnta[i]=(int)(a[i+lb-1].real+0.5);
        }

        for(int i=0; i<len; i++)
        {
            if(i<la)
            {
                if(strA[i]=='b')
                    a[i]=Complex(1,0);
                else
                    a[i]=Complex(0,0);
            }
            else
                a[i]=Complex(0,0);
            if(i<lb)
            {
                if(strB[lb-1-i]=='b')
                    b[i]=Complex(1,0);
                else
                    b[i]=Complex(0,0);
            }
            else
            {
                b[i]=Complex(0,0);
            }
        }
        FFT(a,len,1);
        FFT(b,len,1);
        for(int i=0; i<len; i++)
            a[i]=a[i]*b[i];
        FFT(a,len,-1);
        for(int i=0; i+lb<=la; i++)
        {
            cntb[i]=(int)(a[i+lb-1].real+0.5);
        }
        int ans=0;
        for(int i=0; i+lb<=la; i++)
        {
            unsigned long long hs=query(i,i+lb-1);
            if(cnta[i]+cntb[i]>=lb-K)
                if(mp[hs]==0)
                {
                    ans++;
                    mp[hs]=1;
                }
        }
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
