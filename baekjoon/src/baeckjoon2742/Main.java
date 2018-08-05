package baeckjoon2742;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) {
		int n=0;
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		try {
			n = Integer.parseInt(bf.readLine());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		int a=n;
		for(int i=1;i<=n;i++) {
			System.out.println(a);
			a--;
		}

	}

}
