import java.util.Scanner;
public class hw {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int k = scan.nextInt();
		int[] v = new int[k];
		for(int i = 0; i < k; i++) v[i] = scan.nextInt();

		long sum = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < k; j++) {
				if(i%v[j] == 0) {
					sum += i;
					break;
				}
			}
		}
		System.out.println(sum);
	}
}
					
