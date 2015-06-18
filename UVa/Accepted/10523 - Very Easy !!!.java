/* 
* @Author: Enamul Hassan
* @Date:   2015-05-01 22:49:12
* @Last Modified by:   Enamul
* @Last Modified time: 2015-05-01 23:03:40
* @Verdict: Solved
* @File Path: H:\Dropbox\Code\UVa\Accepted\10523 - Very Easy !!!.cpp
*/

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.math.BigInteger;
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
        int a, b;
        while(true){
            try{
                a = sc.nextInt();
                b = sc.nextInt();
            }catch(Exception e){
                break;
            }
            BigInteger ans = new BigInteger("0");
            BigInteger AInit = new BigInteger(String.format("%d",b));
            BigInteger A = new BigInteger(String.format("%d",b));
            for (int i = 1; i <= a; i++) {
                ans = ans.add(A.multiply(new BigInteger(String.format("%d", i))));
                A = A.multiply(AInit);
            }
            System.out.println(ans);
        }
    }
    
}
