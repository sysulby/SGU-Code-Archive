/**
 * Copyright © 2015 Authors. All rights reserved.
 * 
 * FileName: 112.java
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
        int a = cin.nextInt(), b = cin.nextInt();
        System.out.println(BigInteger.valueOf(a).pow(b).subtract(
                    BigInteger.valueOf(b).pow(a)));
    }
}
