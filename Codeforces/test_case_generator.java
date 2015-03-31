import java.util.*;
import java.io.*;
class test_case_generator{
	public static void main(String argv[]){
		Random rand = new Random();
		int pos[] = {16,45,47,55,1000012,6,5,7,8,1000054};
		File file = new File("input.txt");
		int n, k, len, m;
		len = 20000;
		try{
		FileWriter writer = new FileWriter(file);
		writer.write(String.format("%d\n", len));
		for(long i = 0; i<len;i++)
		{
			n = rand.nextInt(10);
			writer.write(String.format("%d ", 0));

		}
		writer.write(String.format("\n"));
		
		m = rand.nextInt(Math.min((len*(len-1))/200,200000))+1;
		
		writer.write(String.format("%d\n", m));
		for(long i = 0; i<m;i++)
		{
			k = n = rand.nextInt(len)+1;
			writer.write(String.format("%d ", n));
			while(k==n) k = rand.nextInt(len)+1;
			writer.write(String.format("%d\n", k));
		}
		
		writer.write(String.format("\n"));

		writer.close();
		}catch(Exception e){System.out.println("E: "+e);}
	}
}