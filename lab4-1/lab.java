import java.util.Scanner;
import java.util.Random;
public class lab {
	static int strike, ball;
	public static void judge(int[] think, int[] guess) {
		strike = 0;
		ball = 0;
		int flag = 0;
		//	Make flags for think
		for(int i=0; i < 3; i++) flag |= 1<<think[i];
		//	Check flags for guess
		for(int i=0; i < 3; i++) {
			if((flag & (1<<guess[i])) == 0) continue;
			if(think[i] == guess[i]) strike++;
			else ball++;
		}
	}
	public static void main(String[] args) {
		Random rand = new Random();
		Scanner scan = new Scanner(System.in);

		//	Make 9 cards for shuffling
		int[] think = new int[9];
		int[] guess = new int[3];
		for(int i = 0; i < 9; i++) think[i] = i+1;
		//	Shuffle 9 cards very many
		for(int i = 0; i < 9*9*10; i++) {
			//	select two numbers for swapping
			int a = rand.nextInt(9);
			int b = rand.nextInt(9);
			int t = think[a];
			think[a] = think[b];
			think[b] = t;
		}
		int score = 0;
		while(strike != 3) {
			System.out.print("Guess : ");
			String str = scan.next();
			for(int i = 0; i < 3; i++) guess[i] = str.charAt(i)-'0';
			judge(think, guess);
			System.out.println(strike+"S"+ball+"B");
		}
	}
}
