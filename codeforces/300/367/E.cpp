#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
using namespace std;
struct node
{
    int val;
    node *U;
    node *D;
    node *L;
    node *R;
};
node p[1005][1005];
int n,m,q;
node *U1;
node *U2;
node *L1;
node *L2;
node *R1;
node *R2;
node *D1;
node *D2;
void output()
{
    for(int i=1;i<=n;i++)
    {
        node *now=&p[i][0];
        for(int j=0;j<m;j++)
        {
            now=now->R;
            printf("%d ",now->val);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&p[i][j].val);
            p[i][j].L=&p[i][j-1];
            p[i][j].R=&p[i][j+1];
            p[i][j].U=&p[i-1][j];
            p[i][j].D=&p[i+1][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        p[i][0].R=&p[i][1];
        p[i][m+1].L=&p[i][m];
    }
    for(int i=1;i<=m;i++)
    {
        p[0][i].D=&p[1][i];
        p[n+1][i].U=&p[n][i];
    }
    for(int i=0; i<q; i++)
    {
        int a,b,c,d,h,w;
        scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&h,&w);
        node *rec1=&p[a][0];
        node *rec2=&p[c][0];
        for(int i=0; i<b; i++)rec1=rec1->R;
        for(int i=0; i<d; i++)rec2=rec2->R;
        U1=rec1->U;
        U2=rec2->U;
        swap(U1->D,U2->D);
        swap(rec1->U,rec2->U);
        for(int i=1; i<w; i++)
        {
            rec1=rec1->R;
            rec2=rec2->R;
            U1=rec1->U;
            U2=rec2->U;
            swap(U1->D,U2->D);
            swap(rec1->U,rec2->U);
        }
        R1=rec1->R;
        R2=rec2->R;
        swap(R1->L,R2->L);
        swap(rec1->R,rec2->R);
        for(int i=1; i<h; i++)
        {
            rec1=rec1->D;
            rec2=rec2->D;
            R1=rec1->R;
            R2=rec2->R;
            swap(R1->L,R2->L);
            swap(rec1->R,rec2->R);
        }
        D1=rec1->D;
        D2=rec2->D;
        swap(D1->U,D2->U);
        swap(rec1->D,rec2->D);
        for(int i=1; i<w; i++)
        {
            rec1=rec1->L;
            rec2=rec2->L;
            D1=rec1->D;
            D2=rec2->D;
            swap(D1->U,D2->U);
            swap(rec1->D,rec2->D);
        }
        L1=rec1->L;
        L2=rec2->L;
        swap(L1->R,L2->R);
        swap(rec1->L,rec2->L);
        for(int i=1; i<h; i++)
        {
            rec1=rec1->U;
            rec2=rec2->U;
            L1=rec1->L;
            L2=rec2->L;
            swap(L1->R,L2->R);
            swap(rec1->L,rec2->L);
        }
    }
    output();
    return 0;
}
