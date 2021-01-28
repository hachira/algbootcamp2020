import java.util.Scanner;
public class lab {
	static void perm(String s, int n, int r, int v) {
		if(r==0) {
			System.out.println(s);
			return;
		}
		for(int i = 1; i <= n; i++) {
			if( (v & (1<<i)) != 0) continue;
			perm(s+i, n, r-1, v|(1<<i));
		}
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int r = scan.nextInt();
		perm("", n, r, 0);
	}
}
