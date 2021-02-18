import java.util.Scanner;
import java.lang.Math;
public class lab {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int S = scan.nextInt();
		int P = scan.nextInt();
		
		if(S == P) { System.out.println(1); return; }
		int n = (int)(S*Math.exp(-1));
		double maxValue = Math.pow(S/n, n);
		double t = Math.pow(S/(n+1), n+1);
		if(t > maxValue) { maxValue = t; n++; }

		if(P > maxValue) { System.out.println(-1); return; }

		//	Binary Search
		int left = 2, right = n;
		while(left < right) {
			int c = (left+right)/2;
			double v = Math.pow(S/c, c);
			if(P <= v) right = c;
			else left = c+1;
		}
		System.out.println(right);
	}
}
