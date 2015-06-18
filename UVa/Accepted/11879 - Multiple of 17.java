/* 
* @Author: Enamul Hassan
* @Date:   2015-05-01 23:03:57
* @Last Modified by:   Enamul
* @Last Modified time: 2015-05-01 23:04:59
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\UVa\Accepted\11879 - Multiple of 17.cpp
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
        String num;
        BigInteger div = new BigInteger("17");
        while(true){
            num = sc.nextLine();
            BigInteger ans = new BigInteger(num);
            if(ans.equals(ZERO)) break;
            System.out.println((ans.mod(div).equals(ZERO)?1:0));
        }
    }
    
}











