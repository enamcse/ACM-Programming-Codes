/* 
* @Author: Enamul Hassan
* @Date:   2015-05-02 02:06:29
* @Last Modified by:   Enamul
* @Last Modified time: 2015-05-02 02:07:43
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\UVa\Accepted\10235 - Simply Emirp.java
*/
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.IOException;
import java.math.BigInteger;
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
        BigInteger a, b;
        boolean prime, emirp;
        while ((inp = Main.ReadLn (255)) != null) {
            
            a = new BigInteger(inp);
            b = new BigInteger(new StringBuilder(a.toString()).reverse().toString());
            prime = a.isProbablePrime(10);
            emirp = b.isProbablePrime(10);
            System.out.print(a.toString()+" is ");
            if(prime&&emirp&&!a.equals(b)){
                System.out.println("emirp.");
            }else if(prime){
                System.out.println("prime.");
            }
            else{
                System.out.println("not prime.");
            }
            
        }
    }
    
}
