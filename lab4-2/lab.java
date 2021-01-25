import java.util.Random;
import java.util.Scanner;
public class lab {
	//	return value with (strike << 4 | ball)
	static int judge(int a, int b) {
		int flag = 0, r = a, sb = 0;
		while(r > 0) {
			flag |= 1<<(r%10);
			r/=10;
		}
		while(a > 0) {
			if((flag & (1<<(b%10))) != 0) {
				if(a%10 == b%10) sb += 16;
				else sb++;
			}
			a/=10;
			b/=10;
		}
		return sb;
	}
	public static void main(String[] args) {
		Random rand = new Random();
		Scanner scan = new Scanner(System.in);

		//	Make candidate list
		int[] cand = new int[504];
		int t = 0;
		for(int i = 1; i < 10; i++) {
			for(int j = 1; j < 10; j++) {
				if(i==j) continue;
				for(int k = 1; k < 10; k++) {
					if(i==k || j==k) continue;
					cand[t++] = i*100+j*10+k;
				}
			}
		}

		//	Shuffle candidate list
		for(int i = 0; i < 504*504*10; i++) {
			int a = rand.nextInt(504);
			int b = rand.nextInt(504);
			int t = cand[a];
			cand[a] = cand[b];
			cand[b] = t;
		}

		//	Guess and write history
		int[] history = new int[100];
		int hc = 0;
		for(int i = 0; i < 504; i++) {
			//	check history
			boolean isValid = true;
			for(int j = 0; j < hc; j+=2) {
				int r = judge(cand[i], history[j]);
				if(r != history[j+1]) {
					isValid = false;
					break;
		  		}
			}
			if( !isValid) continue;
			System.out.println("Guess : "+cand[i]);
			int s = scan.nextInt();
			int b = scan.nextInt();
			if( s == 3 ) break;
			history[hc++] = cand[i];
			history[hc++] = (s<<4)|b;
		}
	}
}
