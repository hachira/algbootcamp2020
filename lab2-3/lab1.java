import java.util.Scanner;
public class lab1 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();

		int nodiv = 0;
		int i;
		for(i=1; i*i < n; i++) {
			if(n%i==0) nodiv+=2;
		}
		if(i*i==n) nodiv++;
		System.out.println(nodiv);
	}
}
