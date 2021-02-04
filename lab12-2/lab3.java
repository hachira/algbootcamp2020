import java.util.*;
public class lab3 {
	static int[] F = { 1, 1, 1, 0 };
	static int MOD = 1000000009;
	static int[] mult(int[] a, int[] b) {
		int[] t = new int[4];
		t[0] = (int)(((long)a[0]*b[0]+(long)a[1]*b[2])%MOD);
		t[1] = (int)(((long)a[0]*b[1]+(long)a[1]*b[3])%MOD);
		t[2] = (int)(((long)a[2]*b[0]+(long)a[3]*b[2])%MOD);
		t[3] = (int)(((long)a[2]*b[1]+(long)a[3]*b[3])%MOD);
		return t;
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[] f = F, r = { 1, 0, 0, 1 };
		for( ; n > 0 ; n >>=1) {
			if((n&1) == 1) r = mult(r, f);
			f = mult(f, f);
		}
		System.out.println(r[2]);
	}
}
