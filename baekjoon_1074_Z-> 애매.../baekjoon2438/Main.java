package baekjoon2438;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int a=0;
		try {
			a = Integer.parseInt(bf.readLine());
		} catch (NumberFormatException | IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		for(int i=0;i<a;i++) {
			for(int b=0;b<=i;b++) {
				System.out.print("*");
			}
			System.out.println();
		}
		
	}

}
