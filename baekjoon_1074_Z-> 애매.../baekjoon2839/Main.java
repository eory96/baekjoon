package baekjoon2839;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int a=0;
		int countFive=0;
		int countThree=0;
		
		try {
			a = Integer.parseInt(br.readLine());
		} catch (IOException e) {
			e.printStackTrace();
		}
		int b=a;
		while(b>=3) {
			
			if(b%5==0) {
				countFive=b/5;
				b=0;
				break;
			}
			else{
				b-=3;
				countThree++;
			}
		}
		
		if(b==0) {
			System.out.println(countFive+countThree);
		}
		else {
			System.out.println("-1");
		}
	}

}
