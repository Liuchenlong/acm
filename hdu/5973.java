import java.lang.*;
import java.util.*;
import java.math.*;
import java.io.*;
public class Main
{
    public static void main(String[] args)
    {
        BigDecimal eps=new BigDecimal(0.1).pow(111);
        BigDecimal L=new BigDecimal(1.6180339887);
        BigDecimal R=new BigDecimal(1.6180339888);
        while(R.subtract(eps).compareTo(L)==1)
        {
            BigDecimal mid=R.add(L).divide(BigDecimal.valueOf(2));
            BigDecimal val=mid.multiply(BigDecimal.valueOf(2)).subtract(BigDecimal.ONE).pow(2);
            if(val.compareTo(BigDecimal.valueOf(5))==1)
                R=mid;
            else
                L=mid;
        }
        Scanner sc=new Scanner(System.in);
        while(sc.hasNext())
        {
            BigInteger a,b;
            a=sc.nextBigInteger();
            b=sc.nextBigInteger();
            BigInteger ta,tb;
            if(a.compareTo(b)>0)
            {
                ta=b;
                tb=a;
            }
            else
            {
                ta=a;
                tb=b;
            }
            BigDecimal rit=new BigDecimal(tb).subtract(new BigDecimal(ta)).multiply(L);
            rit.setScale(0,BigDecimal.ROUND_DOWN);
            BigInteger r=rit.toBigInteger();
            if(ta.compareTo(r)==0)
                System.out.println(0);
            else
                System.out.println(1);
        }
    }
}
