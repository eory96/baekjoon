package baekjoon1924_Calender;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int a=0;
		int b=0;
		int sum=0;
		int count=0;
		try {
			StringTokenizer st = new StringTokenizer(br.readLine());
			a=Integer.parseInt(st.nextToken());
			b=Integer.parseInt(st.nextToken());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		for(int i=0;i<a;i++) {
			if(i==1||i==3||i==5||i==7||i==8||i==10||i==12) {
				sum+=31;
			}
			else if(i==4||i==6||i==9||i==11) {
				sum+=30;
			}
			else sum+=28;
		}
		sum+=b;
		count=sum%7;
		if(count==0) System.out.println("SUN");
		else if(count ==1) System.out.println("MON");
		else if(count ==2) System.out.println("TUE");
		else if(count ==3) System.out.println("WED");
		else if(count ==4) System.out.println("THU");
		else if(count ==5) System.out.println("FRI");
		else if(count ==6) System.out.println("SAT");
		
	}
}
