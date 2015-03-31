import java.util.*;
import java.io.*;
class test_case_generator{
	public static void main(String argv[]){
		Random rand = new Random();
		File file = new File("input.txt");
		int t = 1;//rand.nextInt(1);
		
		int n=0, k, len, now;
		int[][] arr = new int[501][501];
		try{
		FileWriter writer = new FileWriter(file);
		writer.write(String.format("%d\n", t));
		for(int loop = 0;loop<t;loop++){
			n = 0;
			len = 500;//rand.nextInt(5)+1;
			now=len*len;
			
			
			writer.write(String.format("%d\n", len));
			for(int j =0; j<len;j++){
				for(int i = 0; i<len;i++)
				{
					arr[j][i] = n++;
				}
			}
			
			int it, p, q, r, s, temp;
			it = rand.nextInt(250);
			while(it-->=0)
			{
				p = rand.nextInt(len);
				q = rand.nextInt(len);
				r = rand.nextInt(len);
				s = rand.nextInt(len);
				temp = arr[p][q];
				arr[p][q] = arr[r][s];
				arr[r][s] = temp;
			}
			
			for(int j=0; j<len;j++){
				for(int i = 0; i<len;i++)
				{
					writer.write(String.format("%d ", arr[j][i]));
				}
				writer.write(String.format("\n"));
			}
		}

		writer.close();
		}catch(Exception e){System.out.println("E: "+e);}
	}
}