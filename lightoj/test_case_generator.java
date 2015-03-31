import java.util.*;
import java.io.*;
class test_case_generator{
	public static void main(String argv[]){
		Random rand = new Random();
		File file = new File("input.txt");
		int n, k, len;
		len = rand.nextInt(7000)+1;
		try{
		FileWriter writer = new FileWriter(file);
		writer.write(String.format("%d\n", len));
		for(int i = 0; i<len;i++)
		{
			n = rand.nextInt(20)+1;
			writer.write(String.format("%d\n", n));
			for(int j = 0;j<n;j++){
				k = rand.nextInt(1000)+1;
				writer.write(String.format("%d ", k));
			}
			writer.write(String.format("\n"));
			
			for(int j = 0;j<n;j++){
				k = rand.nextInt(1000)+1;
				writer.write(String.format("%d ", k));
			}
			writer.write(String.format("\n"));
			
			
		}
		writer.write(String.format("\n"));
		writer.close();
		}catch(Exception e){System.out.println("E: "+e);}
	}
}