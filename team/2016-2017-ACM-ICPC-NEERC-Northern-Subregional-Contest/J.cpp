#include <stdio.h>

int main()
{
    freopen("java2016.in","r", stdin);
    freopen("java2016.out","w",stdout);
    int n;
    scanf("%d",&n);
    if(n == 0)
    {
        puts("? / ? / ?");
    }
    else
    {
        puts("a = ? max ? max ?");
        puts("j = a max a");
        for(char ch = 'k'; ch <= 'z'; ch++)
        {
            printf("%c = %c max %c\n", ch, ch - 1, ch - 1);
        }
        puts("b = z / z");
        puts("c = b + b");
        puts("d = c + c");
        puts("e = d + d");
        puts("f = e + e");
        puts("g = f + f");
        puts("h = g + g");
        puts("i = h + h");
        int now = 1;
        int flag = 0;
        int flagg = 0;
        while(n)
        {
            if(n & 1)
            {
                if(flag) printf(" +");
                else flag = 1;
                if(flagg)
                    printf(" %c", 'a' + now);
                else{
                    printf("%c", 'a' + now);
                    flagg = 1;
                }
            }
            now++;
            n /= 2;
        }
        puts("");
    }
}
