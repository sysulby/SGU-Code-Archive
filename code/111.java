/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 111.java
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2015-05-22
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
        BigInteger v = cin.nextBigInteger();
        BigInteger l = BigInteger.ONE, r = v;
        while (l.compareTo(r) < 0) {
            BigInteger mid = l.add(r).add(
                    BigInteger.ONE).divide(BigInteger.valueOf(2));
            if (mid.pow(2).compareTo(v) <= 0) l = mid;
            else r = mid.subtract(BigInteger.ONE);
        }
        System.out.println(l);
    }
}
