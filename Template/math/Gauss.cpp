//此为浮点型模板
//mod p 型需将除法改为乘逆元
const int MAXN=1005;
double a[MAXN][MAXN];//增广矩阵
double x[MAXN];//解集
void output(int equ,int var)
{
    for(int i=0;i<equ;i++)
    {
        for(int j=0;j<=var;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
int gauss(int equ,int var)
{
    memset(x,0,sizeof(x));
    int i,j,k;
    int max_r;// 当前这列绝对值最大的行.
    int col;//当前处理的列
    //转换为阶梯阵.
    col=0; // 当前处理的列
    for(k = 0; k < equ && col < var; k++,col++)
    {
        // 枚举当前处理的行.
        // 找到该col列元素绝对值最大的那行与第k行交换.(为了在除法时减小误差)
        max_r=k;
        for(i=k+1; i<equ; i++)
        {
            if(fabs(a[i][col])>fabs(a[max_r][col]))
                max_r=i;
        }
        if(max_r!=k)
        {
            // 与第k行交换.
            for(j=k; j<var+1; j++)
                swap(a[k][j],a[max_r][j]);
        }
        if(fabs(a[k][col])<=eps)
        {
            // 说明该col列第k行以下全是0了，则处理当前行的下一列.
            k--;
            continue;
        }
        for(i=k+1; i<equ; i++)
        {
            // 枚举要删去的行.
            if(fabs(a[i][col])>eps)
            {
                for(j=var; j>=col; j--)
                {
                    a[i][j]-=a[k][j]*(a[i][col]/a[k][col]);
                }
            }
        }
    }
    for(int i=k; i<equ; i++)//无解
    {
        if(fabs(a[i][var])>eps)
            return -1;
    }
    if(k<var)//无穷解,返回自由变元个数//会改变解的顺序
    {
        for(int i=0; i<equ; i++)
        {
            if(a[i][i]!=0)
                continue;
            else
            {
                int flag=0;
                for(int j=i+1; j<var; j++)
                {
                    if(a[i][j]!=0)
                    {
                        flag=1;
                        for(int k=0; k<=i; k++)
                        {
                            swap(a[k][i],a[i][j]);
                        }
                        break;
                    }
                }
                if(!flag)
                    return var-i;
            }
        }
        return var-equ;
    }
    for(i=var-1; i>=0; i--)
    {
        x[i]=a[i][var]/a[i][i];
        for(j=0; j<i; j++)
        {
            a[j][var]-=a[i][var]*(a[j][i]/a[i][i]);
        }
    }
    return 0;
}
int solve(int equ,int var)
{
    //构建方程组
    //求解(此时模板不是浮点的)
    int flag=gauss(equ,var);
    if(flag==-1)
        return -1;
    else if(flag==0)
    {
        int ans=0;
        for(int i=0; i<equ; i++)
            ans+=x[i];
        return ans;
    }
    else
    {
        int ans=9999;
        for(int i=0; i<(1<<flag); i++)
        {
            memset(x,0,sizeof(x));
            for(int k=0; k<flag; k++)
            {
                if(i&(1<<k))
                    x[var-1-k]=1;
            }
            int t[55];
            for(int ii=0; ii<equ; ii++)
            {
                t[ii]=a[ii][var];
                for(int jj=var-flag; jj<var; jj++)
                {
                    t[ii]=t[ii]^(a[ii][jj]*x[jj]);
                }
            }
            for(int ii=var-flag-1; ii>=0; ii--)
            {
                x[ii]=t[ii]/a[ii][ii];
                for(int jj=0; jj<ii; jj++)
                {
                    t[jj]^=(t[ii]*(a[jj][ii]/a[ii][ii]));
                }
            }
            int tans=0;
            for(int k=0; k<var; k++)
            {
                tans+=x[k];
            }
            ans=MIN(ans,tans);
        }
        return ans;
    }
}
