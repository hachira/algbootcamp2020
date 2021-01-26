import java.util.Scanner;
public class lab {
	public static void main(String[] args) {
		//	Process input
		Scanner scan = new Scanner(System.in);
		String a, b;
		a = scan.next();
		b = scan.next();

		//	Make arrays
		int na = a.length();
		int nb = b.length();
		int[] aa = new int[128];
		int[] ab = new int[128];
		int[] ac = new int[256];
		for(int i = 0; i < na; i++) aa[i] = a.charAt(na-i-1)-'0';
		for(int i = 0; i < nb; i++) ab[i] = b.charAt(nb-i-1)-'0';

		//	Multiply
		for(int i = 0; i < na; i++) {
			int carry = 0, j;
			for(j = 0; j < nb; j++) {
				carry += ac[i+j]+aa[i]*ab[j];
				ac[i+j] = carry%10;
				carry /= 10;
			}
			if(carry > 0) ac[i+j] = carry;
		}

		//	Print
		int max = na+nb-2;
		if(ac[max+1] > 0) max++;
		while( max >= 0 ) System.out.print(ac[max--]);
		System.out.println("");
	}
}
