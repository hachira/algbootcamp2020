import java.util.*;
public class lab {
	static boolean isPellin(String s, int f, int e) {
		while(f < e) {
			if(s.charAt(f++) != s.charAt(e--)) return false;
		}
		return true;
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s = scan.next();
		int last = s.length() - 1;
		for(int i = 0; i < s.length(); i++) {
			if(s.charAt(last) != s.charAt(i)) continue;
			if(!isPellin(s, i, last)) continue;
			System.out.print(s);
			for( i--; i >= 0; i--) System.out.print(s.charAt(i));
			System.out.println("");
			break;
		}
	}
}
