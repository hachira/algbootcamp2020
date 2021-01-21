import java.util.Scanner;
public class lab {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] v = new int[n];
		for(int i = 0; i < n; i++) v[i] = scan.nextInt();

		int min = v[0];
		for(int i = 1; i < n; i++) 
			if(min > v[i]) min = v[i];

		System.out.println(min);
	}
}
