import java.util.*;
public class lab {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int S = scan.nextInt();
		int K = scan.nextInt();
		int base = S/K;
		int mod = S%K;
		long res = 1; 
		for(int i = 0; i < K-mod; i++) res *= base;
		for(int i = 0; i < mod; i++) res *= base+1;
		System.out.println(res);
	}
}
