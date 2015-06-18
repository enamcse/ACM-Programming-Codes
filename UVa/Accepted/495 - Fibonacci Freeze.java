/* 
* @Author: Enamul Hassan
* @Date:   2015-05-02 04:31:06
* @Last Modified by:   Enamul
* @Last Modified time: 2015-05-02 04:32:19
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\UVa\495 - Fibonacci Freeze.java
*/

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.IOException;
import java.math.BigInteger;
import static java.math.BigInteger.ONE;
import static java.math.BigInteger.ZERO;
import java.util.Scanner;

/**
 *
 * @author Enamul
 */
public class Main {
    static String ReadLn (int maxLg)  // utility function to read from stdin
    {
        byte lin[] = new byte [maxLg];
        int lg = 0, car = -1;
        String line = "";

        try
        {
            while (lg < maxLg)
            {
                car = System.in.read();
                if ((car < 0) || (car == '\n')) break;
                lin [lg++] += car;
            }
        }
        catch (IOException e)
        {
            return (null);
        }

        if ((car < 0) && (lg == 0)) return (null);  // eof
        return (new String (lin, 0, lg));
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);

        String inp;
        BigInteger ans[] = new BigInteger[5005];
        ans[0] = ZERO;
        ans[1] = ONE;
        
        for (int i = 2; i < 5005; i++) {
            ans[i] = ans[i-1].add(ans[i-2]);
        }
        
        while ((inp = Main.ReadLn (255)) != null)
            System.out.println("The Fibonacci number for "+inp+" is "+ans[ Integer.parseInt(inp) ]);
    }
    
}
