package baekjoon11720;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int a=0;
		char input[] = null;
		int sum=0;
		try {
			a=Integer.parseInt(br.readLine());
			input = br.readLine().toCharArray();
		} catch (NumberFormatException | IOException e) {
			e.printStackTrace();
		}
		
		for(int i=0;i<a;i++) {
			sum+=(input[i]-'0');
		}
		System.out.println(sum);
	}

}
