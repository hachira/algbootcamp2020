import java.util.Scanner;
public class lab {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int k = scan.nextInt();
		long sum = 0;
		for(int i = 1; i <= n; i++) {
			if(i%k == 0) sum += i;
		}
		System.out.println(sum);
	}
}
