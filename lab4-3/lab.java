import java.util.Scanner;
public class lab {
	static String pelindrome(int n) {
		String r = "";
		while(n > 0) {
			r = r + n%10;
			n /= 10;
		}
		return r;
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int k = scan.nextInt();
		if(k <= 9) {
			System.out.println(k);
			return;
		}
		k -= 10;
		int iv = 9, is, tv = 1;
		for(is = 2; is < 10 ; is++) {
			if(k < iv) break;
			k -= iv;
			if(is%2 == 1) tv *= 10;
			else iv *= 10;
		}
		if(is%2 == 1) {
			int f = k/10+tv;
			System.out.println((f)+""+(k%10)+pelindrome(f));
		} else {
			k += tv;
			System.out.println(k+pelindrome(k));
		}
	}
}
