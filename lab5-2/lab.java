import java.util.Scanner;
public class lab {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int min = 1000000;
		int lmin = 1000000;
		for(int i = 0; i < n; i++) {
			int v = scan.nextInt();
			if(v < min) {
				lmin = min;
				min = v;
		  	}
			else if(v > min && v < lmin) {
				lmin = v;
			}
		}
		System.out.println(lmin);
	}
}
