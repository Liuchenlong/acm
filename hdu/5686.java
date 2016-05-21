import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        BigInteger dp[] = new BigInteger[202];
        dp[0]=BigInteger.ONE;
        dp[1]=dp[0];
        for(int i=2;i<=200;i++)
        {
            dp[i]=dp[i-1].add(dp[i-2]);
        }
        while(sc.hasNext())
        {
            int n=sc.nextInt();
            System.out.println(dp[n]);
        }
    }
}
