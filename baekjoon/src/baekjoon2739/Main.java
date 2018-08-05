package baekjoon2739;

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
			e.printStackTrace();
		}
		
		for(int i=1;i<=9;i++) {
			System.out.println(a+" * "+i+" = "+a*i);
		}
	}
}
