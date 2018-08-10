package baekjoon15552;

/*
 * 첫 줄에 테스트케이스의 개수 T가 주어진다. T는 최대 1,000,000이다. 다음 T줄에는 각각 두 정수 A와 B가 주어진다. A와 B는 1 이상, 1,000 이하이다.
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine().trim());
		
		for(int i = 0; i < n; i++) {
			String input = br.readLine();
			int blank = input.indexOf(" ");
			int a = Integer.parseInt(input.substring(0, blank));
			int b = Integer.parseInt(input.substring(blank + 1, input.length()));
			bw.write(a + b + "\n");
		}
		bw.flush();
		
		/*BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int i=0;
		int[] arr1=new int[2];
		ArrayList<Integer> list = new ArrayList<Integer>();
		
		try {
			i=Integer.parseInt(bf.readLine());
		} catch (NumberFormatException | IOException e) {
			e.printStackTrace();
		}
		
		for(int a=0; a<i;a++) {
			StringTokenizer tk;
			try {
				tk = new StringTokenizer(bf.readLine());
				arr1[0]=Integer.parseInt(tk.nextToken());
				arr1[1]=Integer.parseInt(tk.nextToken());
				list.add(arr1[0]+arr1[1]);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		
		for(int a:list) {
			try {
				bw.write(a+"\n");
				bw.flush();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}런타임에러가 발생하는 경우*/
	}
}
