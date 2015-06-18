/* 
* @Author: Enamul
* @Date:   2015-06-15 07:06:03
* @Last Modified by:   Enamul
* @Last Modified time: 2015-06-15 07:07:55
*/
import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class FibonacciModified {
    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
        int A,B,N;
        A = sc.nextInt();
        B = sc.nextInt();
        N = sc.nextInt();
        if(N==1) System.err.println(A);
        else if(N==2) System.err.println(B);
        BigInteger a, b;
        a = new BigInteger(String.format("%d", A));
        b = new BigInteger(String.format("%d", B));
        boolean flag = true;
        for (int i = 2; i < N; i++) {
                if(flag){
                    a=a.add(b.multiply(b));
                    flag = false;
                }else{
                    b=b.add(a.multiply(a));
                    flag = true;
                }
            }
        if(flag) System.out.println(b);
        else System.out.println(a);
    }
}