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
#include<bitset>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-7
const double pi=acos(-1.0);
bool zero(long double x)
{
    if(fabs(x)<=eps)
        return true;
    return false;
}
int sign(long double x)
{
    if(zero(x))return 0;
    if(x>0)return 1;
    return -1;
}
struct point3
{
    long double x,y,z;
    point3() {}
    point3(long double X,long double Y,long double Z)
    {
        x=X;
        y=Y;
        z=Z;
    }
    void input()
    {
        double xx,yy,zz;
        scanf("%lf%lf%lf",&xx,&yy,&zz);
        x=xx;
        y=yy;
        z=zz;
    }
    void output()
    {
        printf("%f %f %f\n",x,y,z);
    }
    point3 operator +(const point3 p)const
    {
        return point3(x+p.x,y+p.y,z+p.z);
    }
    point3 operator -(const point3 p)const
    {
        return point3(x-p.x,y-p.y,z-p.z);
    }
    point3 operator *(const long double k)const
    {
        return point3(x*k,y*k,z*k);
    }
    point3 operator /(const long double k)const
    {
        return point3(x/k,y/k,z/k);
    }
};
struct line3
{
    point3 a,b;
    line3() {}
    line3(point3 A,point3 B)
    {
        a=A;
        b=B;
    }
};
struct plane3
{
    point3 a,b,c;
    plane3() {}
    plane3(point3 A,point3 B,point3 C)
    {
        a=A;
        b=B;
        c=C;
    }
    void output()
    {
        a.output();
        b.output();
        c.output();
    }
};
//计算 cross product U x V
point3 xmult(point3 u,point3 v)
{
    point3 ret;
    ret.x=u.y*v.z-v.y*u.z;
    ret.y=u.z*v.x-u.x*v.z;
    ret.z=u.x*v.y-u.y*v.x;
    return ret;
}
//计算 dot product U . V
long double dmult(point3 u,point3 v)
{
    return u.x*v.x+u.y*v.y+u.z*v.z;
}
//矢量差 U - V
point3 subt(point3 u,point3 v)
{
    point3 ret;
    ret.x=u.x-v.x;
    ret.y=u.y-v.y;
    ret.z=u.z-v.z;
    return ret;
}
//取平面法向量
point3 pvec(plane3 s)
{
    return xmult(subt(s.b,s.a),subt(s.b,s.c));
}
point3 pvec(point3 s1,point3 s2,point3 s3)
{
    return xmult(subt(s1,s2),subt(s2,s3));
}

//向量大小
long double vlen(point3 p)
{
    return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
}
point3 intersection(line3 l,plane3 s)
{
    point3 ret=pvec(s);
    long double t=(ret.x*(s.a.x-l.a.x)+ret.y*(s.a.y-l.a.y)+ret.z*(s.a.z-l.a.z))/ (ret.x*(l.b.x-l.a.x)+ret.y*(l.b.y-l.a.y)+ret.z*(l.b.z-l.a.z));
    ret.x=l.a.x+(l.b.x-l.a.x)*t;
    ret.y=l.a.y+(l.b.y-l.a.y)*t;
    ret.z=l.a.z+(l.b.z-l.a.z)*t;
    return ret;
}
point3 PA,PB,PC,PD;
plane3 ABC,ACD,ABD,BCD;
point3 VABC,VACD,VABD,VBCD;
plane3 push(plane3 now,point3 vec,long double r)
{
    vec=(vec/vlen(vec))*r;
    now.a=now.a+vec;
    now.b=now.b+vec;
    now.c=now.c+vec;
    return now;
}
long double volume(point3 a,point3 b,point3 c,point3 d)
{
    return fabs(dmult(xmult(b-a,c-a),d-a));
}
point3 cal(long double R)
{
    plane3 abc,abd,acd,bcd;
    abc=push(ABC,VABC,R);
    abd=push(ABD,VABD,R);
    acd=push(ACD,VACD,R);
    bcd=push(BCD,VBCD,R);

    line3 abc_abd;
    point3 crs1=intersection(line3(abc.a,abc.c),abd);
    point3 crs2=intersection(line3(abc.b,abc.c),abd);
    abc_abd=line3(crs1,crs2);

    return intersection(abc_abd,acd);
}
int main()
{
    double x,y,z;
    while(scanf("%lf%lf%lf",&x,&y,&z)!=EOF)
    {
        PA=point3(x,y,z);
        PB.input();
        PC.input();
        PD.input();
        if(zero(dmult(xmult(PB-PA,PC-PA),PD-PA)))
        {
            printf("O O O O\n");
            continue;
        }
        ABC=plane3(PA,PB,PC);
        VABC=pvec(ABC);
        if(sign(dmult(VABC,PD-PB))==-1)
        {
            VABC=VABC*(-1);
        }
        BCD=plane3(PB,PC,PD);
        VBCD=pvec(BCD);
        if(sign(dmult(VBCD,PA-PB))==-1)
        {
            VBCD=VBCD*(-1);
        }
        ACD=plane3(PA,PC,PD);
        VACD=pvec(ACD);
        if(sign(dmult(VACD,PB-PA))==-1)
        {
            VACD=VACD*(-1);
        }
        ABD=plane3(PA,PB,PD);
        VABD=pvec(ABD);
        if(sign(dmult(VABD,PC-PA))==-1)
        {
            VABD=VABD*(-1);
        }
        long double V=volume(PA,PB,PC,PD)/2;
        long double S=fabs(vlen(xmult(PB-PA,PC-PA)))+fabs(vlen(xmult(PB-PA,PD-PA)))+fabs(vlen(xmult(PC-PA,PD-PA)))+fabs(vlen(xmult(PC-PB,PD-PB)));
        S/=2.0;
        long double l=V/S;
        if(zero(l))
        {
            printf("O O O O\n");
            continue;
        }
        point3 O=cal(l);
        printf("%.4f %.4f %.4f %.4f\n",(double)O.x,(double)O.y,(double)O.z,(double)l);
    }
    return 0;
}
