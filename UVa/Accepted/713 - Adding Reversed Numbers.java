/* 
* @Author: Enamul Hassan
* @Date:   2015-05-02 00:11:04
* @Last Modified by:   Enamul
* @Last Modified time: 2015-05-02 00:11:21
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\UVa\713 - Adding Reversed Numbers.cpp
*/

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.math.BigInteger;
import static java.math.BigInteger.ZERO;
import java.util.Scanner;

/**
 *
 * @author Enamul
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        
        int test = sc.nextInt();
        sc.nextLine();
        String inp;
        String[] num;
        BigInteger a, b;
        for (int i = 0; i < test; i++) {
            inp = sc.nextLine();
            
            num = inp.split(" ");
            a = new BigInteger(num[0]);
            b = new BigInteger(num[1]);
            a = new BigInteger(new StringBuilder(a.toString()).reverse().toString());
            b = new BigInteger(new StringBuilder(b.toString()).reverse().toString());
            a = a.add(b);
            a = new BigInteger(new StringBuilder(a.toString()).reverse().toString());
            System.out.println(a.toString());
        }
    }
    
}
