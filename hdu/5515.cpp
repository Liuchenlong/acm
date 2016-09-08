#include<stdio.h>
#include<cmath>
#include<assert.h>
#define eps 1e-8
struct point
{
    double x,y;
};
point p[4];
void init()
{
    p[0].x=0;
    p[0].y=0;
    p[1].x=0;
    p[1].y=300;
    p[2].x=300;
    p[2].y=300;
    p[3].x=300;
    p[3].y=0;
}
double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        double t,v1,v2;
        scanf("%lf%lf%lf",&t,&v1,&v2);
        int flag=0;
        if(fabs(v1)<=eps)
        {
            printf("Case #%d: No\n",cas);
            continue;
        }
        if(fabs(v2-v1)<=eps)
        {
            printf("Case #%d: Yes\n",cas);
            continue;
        }
        int chos=0;
        for(int k=3; k>0; k--)
        {
            if(v2*dist(p[0],p[k])<=300.0*k*v1+eps)
            {
                chos=k;
            }
        }
        if(chos==0)
        {
            printf("Case #%d: No\n",cas);
            continue;
        }
        else
        {
            if(chos==2)
            {
                double l=0.0,r=300.0;
                int tim=100;
                while(tim--)
                {
                    double mid=(l+r)/2.0;
                    double tim1=sqrt(mid*mid+90000)/v1;
                    double tim2=(300+mid)/v2;

                    if(tim1<tim2)
                        r=mid;
                    else
                        l=mid;

                }
                double ansx=l;
                double t1,t2;
                int pt1=1,pt2=1;
                t1=ansx/v1+(sqrt(90000+ansx*ansx)/v1);
                t2=t+300/v2;
                int mm=3;
                if(fabs(ansx-300)<=eps)
                {
                    pt2++;
                    mm--;
                    t1+=300.0/v1;
                    t2+=300.0/v2;
                }
                for(int i=0; i<mm; i++)
                {
                    t1=t1+300.0/v1;
                    t2=t2+300.0/v2;
                    if(t1<=t2+eps)
                        pt1++;
                    else
                        pt2++;
                }
                if(pt1>pt2)
                    flag=1;
            }
            else if(chos==3)
            {
                double l=0.0,r=300.0;
                int tim=100;
                while(tim--)
                {
                    double mid=(l+r)/2.0;
                    double tim1=sqrt((300.0-mid)*(300.0-mid)+90000)/v1;
                    double tim2=(600+mid)/v2;

                    if(tim1<tim2)
                        r=mid;
                    else
                        l=mid;
                }
                double ansx=l;
                double t1,t2;
                int pt1=1,pt2=2;
                t2=t+600/v2;
                t1=300/v1+sqrt(90000+ansx*ansx)/v1+sqrt(90000+(300-ansx)*(300-ansx))/v1;
                int mm=2;
                if(fabs(ansx-300)<=eps)
                {
                    pt2++;
                    mm--;
                    t1+=300.0/v1;
                    t2+=300.0/v2;
                }
                for(int i=0; i<mm; i++)
                {
                    t1=t1+300/v1;
                    t2=t2+300/v2;
                    if(t1<=t2+eps)
                        pt1++;
                    else
                        pt2++;
                }
                if(pt1>pt2)
                    flag=1;
            }
            if(flag)
                printf("Case #%d: Yes\n",cas);
            else
                printf("Case #%d: No\n",cas);
        }
    }
    return 0;
}
