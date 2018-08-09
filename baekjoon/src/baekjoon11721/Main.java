package baekjoon11721;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int a=0;
		char str[]=null;
		try {
			str=br.readLine().toCharArray();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		for(int i=1; i<=str.length; i++) {
			System.out.print(str[i-1]);
			if(i%10==0) System.out.println();
			
		}
	}
}