import java.lang.*;
import java.util.*;
import java.math.*;
import java.io.*;
public class Main
{
	public static BigInteger ans[]=new BigInteger [10005];
	public static BigInteger gcd(BigInteger a,BigInteger b)
	{
		if(b.equals(BigInteger.ZERO))return a;
		return gcd(b,a.mod(b));
	}
	public static BigInteger abs(BigInteger a)
	{
		if(a.compareTo(BigInteger.ZERO)<0)
			return a.multiply(BigInteger.valueOf(-1));
		return a;
	}
    public static void main(String[] args)
    {
    	Scanner sc=new Scanner(System.in);
    	int n=sc.nextInt();
    	for(int i=0;i<n;i++)ans[i]=sc.nextBigInteger();
    	boolean flag=false;
    	BigInteger tans=BigInteger.ONE;
    	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)
    	{
    		if(!flag)
    		{
    			flag=true;
    			tans=abs(ans[i].subtract(ans[j]));
    		}
    		else
    		{
    			tans=gcd(tans,abs(ans[i].subtract(ans[j])));
    		}
    	}
    	BigInteger res=(tans.subtract(ans[0].mod(tans))).mod(tans);
    	System.out.println(res);
    }
}
