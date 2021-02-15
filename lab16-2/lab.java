import java.util.*;
public class lab {
	static void dfs(int[][] map, int y, int x) {
		int[] dy = { 0, -1, 0, 1 };
		int[] dx = { -1, 0, 1, 0 };
		for(int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(map[ny][nx] == 1) {
				map[ny][nx] = 0;
				dfs(map, ny, nx);
			}
		}
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int m = scan.nextInt();
		int[][] map = new int[n+2][m+2];
		for(int i = 0; i < n; i++) {
			String s = scan.next();
			for(int j = 0; j < m; j++) {
				map[i+1][j+1] = (s.charAt(j) == '1') ? 1 : 0;
			}
		}

		int count = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				if(map[i][j] == 0) continue;
				count++;
				map[i][j] = 0;
				dfs(map, i, j);
			}
		}
		System.out.println(count);
	}
}
