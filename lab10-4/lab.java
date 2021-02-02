import java.util.*;
public class lab {
	static int[] lineflag = new int[9];
	static int[] vertflag = new int[9];
	static int[] blockflag = new int[9];
	static void solve(int[][] sudoku, int r, int c) {
		//	Search empty space
		while( r < 9 ) {
			if(sudoku[r][c] == 0) break;
			c++;
			if(c == 9) { r++; c = 0; }
		}
		if(r == 9) {
			for(int i = 0; i < 9; i++) {
				for(int j = 0; j < 9; j++) {
					System.out.print(sudoku[i][j]+" ");
				}
				System.out.println("");
			}
			return;
		}
		int lf = lineflag[r], vf = vertflag[c], bf = blockflag[(r/3)*3+(c/3)];
		for(int i = 1; i <= 9; i++) {
			//	check i
			if( (lf & (1<<i)) != 0) continue;
			if( (vf & (1<<i)) != 0) continue;
			if( (bf & (1<<i)) != 0) continue;
			lineflag[r] |= 1<<i;
			vertflag[c] |= 1<<i;
			blockflag[(r/3)*3+(c/3)] |= 1<<i;
			sudoku[r][c] = i;
			solve(sudoku, (c==8)?r+1:r, (c==8)?0:c+1);
			lineflag[r] &= ~(1<<i);
			vertflag[c] &= ~(1<<i);
			blockflag[(r/3)*3+(c/3)] &= ~(1<<i);
		}
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int[][] sudoku = new int[9][9];
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++) {
				sudoku[i][j] = scan.nextInt();
				lineflag[i] |= 1<<sudoku[i][j];
				vertflag[j] |= 1<<sudoku[i][j];
				blockflag[(i/3)*3+(j/3)] |= 1<<sudoku[i][j];
			}
		}

		solve(sudoku, 0, 0);
	}
}
