/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 118.java
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-05-23
 */
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Solution
{
    public static void main(String args[])
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int T = cin.nextInt();
        while (T-- > 0) {
            int n = cin.nextInt();
            BigInteger s = BigInteger.ZERO, p = BigInteger.ONE;
            for (int i = 0; i < n; ++i) {
                int v = cin.nextInt();
                s = s.add(p = p.multiply(BigInteger.valueOf(v)));
            }
            int val = 0;
            String str = s.toString();
            for (int i = 0; i < str.length(); ++i)
                val += str.charAt(i) - '0';
            while (val >= 10) {
                int t = val; val = 0;
                while (t > 0) { val += t % 10; t /= 10; }
            }
            System.out.println(val);
        }
    }
}
