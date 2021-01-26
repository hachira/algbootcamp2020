import java.util.Scanner;
public class lab {
	public static void main(String[] args) {
		//	Input two number strings.
		Scanner scan = new Scanner(System.in);
		String a = scan.next();
		String b = scan.next();

		//	Get string lengths
		int na = a.length();
		int nb = b.length();

		//	Make string arrays
		int[] aa = new int[na+nb+1];
		int[] ab = new int[na+nb+1];
		for(int i=0; i<na; i++) aa[i] = a.charAt(na-i-1) - '0';
		for(int i=0; i<nb; i++) ab[i] = b.charAt(nb-i-1) - '0';

		//	Calculate
		int c = 0, i;				//	set initial carry to 0
		for(i = 0; i < na || i < nb; i++) {
			c += aa[i] + ab[i];
			aa[i] = c%10;
			c /= 10;
		}
		if(c>0) aa[i++] = c;
		for( i--; i >= 0; i--) System.out.print(aa[i]);
		System.out.println("");
	}
}
